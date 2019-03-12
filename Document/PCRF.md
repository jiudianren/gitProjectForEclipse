#1 PCRF
PCRF包括一个 imp，相当于一个hub。接受其他网元的消息。然后转发给PCRF。
为什么需要这个hub，因为有时候需要对接不同的系统，另外还维护的Diamater的链接。将diamter转成zxos消息。

OLC充当OCS与各外部在线计费上报网元的接口，处理网元发送的在线计费相关的请求，转换成OCS内部使用的的协议（DCC协议），发送给OCS；
接受OCS返回的CCA，转换成各网元使用的协议，发送到网元


PCRF是一个多进程的程序。
包括进程管理进程和业务进程。 zxinit 和zxmonitor 等负责管理进程的启动和监控，进程的拉起。

通过心跳实现

消息分发进程和消息处理进程。
PDis消息分发进程，（比如按号码分发等）
当有多个PDE的时候。
这其中有Rulecache共享内存管理进程 。将用户资料加载，更快的访问。静态资料。

其中包括共享内存版本管理， 比如 新建资费计划。共享内存的新建，刷新，PDE自费版本的切换
当PDE单进程处理性能不够的时候，可以多启动几个PDE进程处理。

#imp

##平台层
由操作系统相关的系统级功能构成，它屏蔽了不同操作系统的细节，为应用提供统一的调用系统API的接口，并提供部分通用的服务和管理程序：监控、启动、停止等。主要包括：
1、	线程管理。OLC采用基于多线程协作处理的架构，负责线程的创建、销毁、健康监测等
2、	链路管理。对OLC与外部网元、OLC与OCS的链路进行管理，如定时检测链路是否
正常、链路是否积压、断链重连等。支持TCP、UDP、SSL。
3、	消息队列管理。线程之间使用消息队列进行通信
4、	共享内存管理。负责OLC平台中的共享内存变量，以及各service接口的共享内存
变量的创建
5、	定时器服务。为各种需要定时触发的事件提供服务，如定时输出统计数据等
6、	日志管理。提供统一的日志输出接口，控制日志文件生成的个数、大小等
7、	配置管理。负责配置文件的读取和写入
8、	系统内核资源管理。如线程锁、信号量等


##imp的架构是这样的：

OLC采用多线程架构，其中比较重要的一点是，从socket收发数据的操作与具体的业务
处理逻辑是分离的，因此系统中主要分两类线程：
1、	socket线程。一个socket连接有两个线程，socket接收线程负责从对端recv数据，
socket发送线程负责send数据到对端。
2、	业务处理线程。即通常所见的service380、service366等。
socket接收线程收到网元的消息后，需要将该消息转发给业务线程来处理；业务线程处
理完消息后，需要将消息转发给socket发送线程，从而发送到网元。

放到的消息队列中了


zxos消息协议的一些内容：

//zxos消息头结构，消息头后面就是消息体的内容
typedef struct
{
  		UINT16  pno         //线程（或进程）在zxos节点内的逻辑编号
  		UINT8   module;     //zxos节点的模块号
  		UINT8   postOffice; //局号，没多大用处，不过需要保持配置一致
} PID;


typedef struct
{
  		PID     sender;   //消息发送方的PID
  		PID     receiver; //消息接收方的PID
  		UINT16  event;    //发送的消息的事件ID
  		UINT16  len;      //消息体的字节数
} MSG_HEAD;


这个链接是一个长链接。Diamater有 DWR 和DWA消息维持心跳。解决黏包的时候，使用的 消息头包含长度信息的方式。


用的是msgget systemv消息队列

OLC一共有3个消息队列：

1、	消息队列0
生产者：为socket接收线程，在收到对端（OCS或外部网元）的数据后，将数据放入到
消息队列0
消费者：为业务处理线程，如service380，从消息队列0取消息进行处理
2、	消息队列1
生产者：为业务处理线程，如service380，处理完消息后，将待转发到网元的消息放入
到消息队列1
消费者：为socket发送线程，从该队列取消息，通过socket发送到网元
3、	消息队列2
用于impmonitor进程对OLC的各线程进行健康检查，一般不需要关注

发送到消息队列的消息，实际上为一个指针，该指针指向具体的数据，包括zxos消息
头以及zxos数据体


# 我的工作

从参与这个项目以来，主要做的工作包括：
##1，前期了解项目代码。解决一些系统的bug.

解决的bug的各个部分都有，就在这个过程中对整体的代码有了一些了解。

##2, 做了一个报表统计进程。离线入库进程。  
PDE进程，从pde的业务进程，各个内部，将需求的业务信息，通过消息，发送的报表统计进程。
报表统计进程，根据分类，时间，等将这些消息，进行格式化处理成 csv格式，并将报表落地成文件。
离线入库进程，将落地后的文件，进行读取，再入数据库。

##bypass 部分解释

bypass，这是个替代功能，当pde进程这边挂掉，或者处理过来的的情况下，
由 olc 代替进程简单处理。比如回复默认套餐，或回复错误码等。
这个需求，完成之后，还没有现场使用。


##5  云化管理 和dockerfile的编写
dockerfile的编写， 将原来的代码转化为镜像。

简单学习了下zk的一些基本知识，和一些api，
将对zk的使用，划分成了，zk管理的三大块，：对这些api进行了包装：
zk的链接管理类。  ---- 》管理和获取zk的连接的句柄
zk的路径管理类   ---》初始化路径
zk的事件处理类    ---》 对zk节点变化的时间进行处理 ，在zk——init的时候，注入


##这一块要看清楚 todo


###处理的 事件有：
	void TZNodeEventMgr::fun_watch(zhandle_t *zhandle, 
								const int iEvent, 
									int iState, 
									const char* sPath, 
									void* context)
	{
	
		    // 使用者只关注部分事件
	    const std::set<int> &refEventCare = GetSelf()->GetEventCare();
	    if(!refEventCare.empty())
	    {
	        bProcEvent = refEventCare.find(iEvent) != refEventCare.end();
	        VLOG_INFO("TZNodeEventMgr::fun_watch In Event Only Care,  Event is {}", iEvent);
	    }
	    if (iEvent == ZOO_SESSION_EVENT) 
	    //会话失效事件，客户端与服务端断开或重连时触发
	    {
	    }
	    else if (iEvent == ZOO_CHANGED_EVENT) 
	    //节点数据改变事件，此watch通过zoo_exists()或zoo_get()设置
	    {
	            if(bProcEvent)
		        {
		            ProZooChangedEvent(zhandle, sPath);
		        }
	    }
	    else if (iEvent == ZOO_CREATED_EVENT) 
	    //节点创建事件，需要watch一个不存在的节点，当节点被创建时触发，此watch通过zoo_exists()设置
	    {
	    }
	    else if (iEvent == ZOO_DELETED_EVENT) 
	    //节点删除事件，此watch通过zoo_exists()或zoo_get()设置
	    {
	    }
	    else if (iEvent == ZOO_CHILD_EVENT) 
	    //子节点列表改变事件，此watch通过zoo_get_children()或zoo_get_children2()设置
	    {
	    }
	}
	
	

### ProZooChangedEvent 示例

	void TZNodeEventMgr::ProZooChangedEvent(zhandle_t *zhandle, const char* sPath)
	{
	    VLOG_INFO("Info, Pro ZOO_CHANGED_EVENT Begin, path:{}.", sPath);
	    TEventKeyEle tEventKey;
	    //regist a watcher again to make watch persistence
	    struct Stat stat;
	    zoo_exists(zhandle, sPath, 1, &stat);
	    
	    tEventKey.Set(sPath, E_EventType::CHANGE_VALUE);
	    
	    GetSelf()->ExecCallbackImp(sPath, tEventKey);
	}
	
	void TZNodeEventMgr::ExecCallbackImp(const std::string sPath,
		 const TEventKeyEle tEvent)
	{
	    auto it = m_mapCallbackFunc.find(sPath);
	    if (it != m_mapCallbackFunc.end())
	    {
	        //call event processor
	        it->second(tEvent);
	    }
	    else
	    {
	        VLOG_INFO("module,path:{},id:{},does not found event processor.", tEvent.sZNodePath, tEvent.Action());
	    }
	}
	
	
	
###
	bool TZKStatusAgent::Initialize(const std::string &val)
	{
	    if(m_bInitialized)
	    {
	        return m_bInitialized;
	    }
	
	    m_bInitialized = true;
	
	    gpvLogger->Init(val);
	
	    bool bRetFlag = false;
	
	    //1.初始化基础变量
	    bRetFlag = m_pHostStatusMgr->Initialize(E_SvsType::PCRF);
	    //2.初始化本地路径
	    bRetFlag = bRetFlag && m_pZNodePathMgr->Initialize();
	    //3.清除非本次会话临时节点（由于网络延迟等造成的非本次会话临时节点未及时释放掉情况）
	    bRetFlag = bRetFlag && m_pZNodePathMgr->DeleteEphemeralNode();
	    //4.同步路径节点到ZK服务器
	    bRetFlag = bRetFlag && m_pZNodePathMgr->SyncPathToZooKeeper();
	    //5.设置watcher和回调信息，如日志跟踪
	    bRetFlag = bRetFlag && m_pZNodeEventMgr->AddMonitoredEntity();
	
	    m_pZNodePathMgr->SetRequestModuleFunc([this]() { return this->RequestZKModuleInfo();});
	
	    return bRetFlag;
	}



###


	class TStatusEventBase
	{
	public:
	    TStatusEventBase(bool bCareChildren) :
	            m_bCareChildren(bCareChildren)
	    {
	    }
	    virtual ~TStatusEventBase()
	    {
	    }
	    bool CareChildren()
	    {
	        return m_bCareChildren;
	    }
	    virtual bool Execute(const TEventKeyEle event) = 0;
	
	private:
	    bool m_bCareChildren;
	};


	class TTraceLogEvent : public TTraceLogEventBase
	{
	public:
	    TTraceLogEvent(std::shared_ptr<THostStatusMgr> arg1, std::shared_ptr<TZNodePathMgr> arg2);
	    virtual ~TTraceLogEvent();
	
	public:
	    void CloseTraceLog() override;
	    void OpenTraceLog(const int32_t iLogLvl, const std::string &sNumber) override;
	};


	TZKStatusAgent::TZKStatusAgent()
	{
	    m_bInitialized = false;
	    mapStatusEventtype mapStatEvt;
	    m_pPcrfModuleAssign = std::make_shared<TPcrfModuleAssignMgr>(m_pZNodePathMgr);
	    
	    mapStatEvt[(int32_t) StatusPer::log] = std::make_shared<TTraceLogEvent>(m_pHostStatusMgr, m_pZNodePathMgr);
	
	    m_pZNodeEventMgr->SetStatusEvent(mapStatEvt);
	}


	void TZNodeEventMgr::SetStatusEvent(const mapStatusEventtype mapStatusEvent)
	{
	    m_mapStatusEvent = mapStatusEvent;
	}


	bool TZNodeEventMgr::AddMonitoredEntity()
	{
	    bool bRetFlag = true;
	    for (auto node : m_mapStatusEvent)
	    {
	        auto path = m_pZNodePathMgr->GetNodePath((int32_t) node.first);
	
	        //一个路径对应一个特性功能
	        m_mapEntityObj[path] = node.second;
	        SetNotifyCallBack(path, EventCallbackFunc, node.second->CareChildren());
	    }
	
	    return bRetFlag;
	}



	void TZNodeEventMgr::SetNotifyCallBack(const std::string& sPath, callback func, bool bCareChildren)
	{
	    VLOG_INFO("SetNotifyCallBack begin.path:[{}], bCareChildren is:[{}]", sPath.c_str(), bCareChildren);
	    m_mapCallbackFunc[sPath] = func;
	    if (bCareChildren)
	    {
	        std::set<std::string> setZNodeChildren;
	        m_pZNodePathMgr->GetChildren(sPath, false, setZNodeChildren);
	        m_pZNodePathMgr->SetChildrenLocal(sPath, setZNodeChildren, E_LocalChild::All);
	        m_pZNodePathMgr->SetChildrenLocal(sPath, setZNodeChildren, E_LocalChild::Add);
	    }
	    m_pZNodePathMgr->SetWatcher(sPath, bCareChildren);
	    VLOG_INFO("SetNotifyCallBack End.");
	}
	
	
	void TZNodeEventMgr::EventCallbackFunc(const TEventKeyEle event)
	{
	    //VLOG_INFO("status event, znode path is:\"{}\", event id:{}", event.sZNodePath.c_str(), (int32_t)event.eEventId);
	    auto obj = GetSelf()->m_mapEntityObj.find(event.sZNodePath);
	    if (obj != GetSelf()->m_mapEntityObj.end())
	    {
	        obj->second->Execute(event);
	    }
	    else
	    {
	        VLOG_INFO("ExecutCallbackFunc failded , znode path is:\"{}\", event id:{}", event.sZNodePath.c_str(), (int32_t)event.eEventId);
	    }
	}
	
	
主要是把zk作为 数据发布和订阅 ，提供给管理平台当前容器内的业务进程的一些信息。
第二是分布式协调通知，比如 号码跟踪功能，
之前单机的情况的下，通过管理进程发一条消息就可了，云化以后，各个容器都需要知道信息，
则云化管理模块的zk，就可以通过发布这样的一个变动，让各个容器进行处理 


zookeeper应用的典型场景 
	3.1　数据发布与订阅（配置中心） 
	3.2　命名服务 
	3.3　分布式协调服务/通知 
	3.4　Master选举 
	3.5　分布式锁 


这里主要用到了 
数据发布和订阅    --》 供云平台查看 
分布式协调服务/通知   --》号码跟踪，日志开启等命令  的发布 

##6 单元测试

gtest gmock的使用

perl生成，按照现在的目录层级，生成所有类的mock类

[TestCaseName，TestName]，而我对这两个参数的定义是：
[TestSuiteName，TestCaseName]，在下一篇我们再来看为什么这样定义


class为suit member为 case


7， 后期参与了一次代码重构，重构前的代码有一个历史遗留的全局变量的问题。
RatableEvent的问题，有很多属性，用于保存，请求消息中的avp，和下发消息中的avp， 这个类太臃肿了，导致有问题的时候，定位的时候影响解决问题的速度。不符合设计原则。

 重构之后，接口更加清晰。
 比如Gx，Sysp,Rx接口，和策略判定接口，
 
gx,sysp,rx等接口将必要的信息，设置给策略判定接口，策略判定后，各个接口再取的必要的数据。
 
 这样接口更加清晰， 
 而且数据和行为分离。
 数据和行为分离的。
    
8 现场问题定位和RT时间总是错，
rt参考的内容太多，策略计划的失效时间，时段策略的生效时间，回话失效时间，账本失效时间等等，
这个问题，总是出现，而且，这个时间的设定，分布于程序的各个地方，当RT时间，错误的时候，就需要不停的追踪RT参考了哪些值，这样很浪费时间。
后来我就提议，新增一个RT类，和参考时间的类型的枚举值，这样，每当有rt的参考时间的时候，就将其保存到该类中。
等到最后，下发响应消息的时候，在将该值，做运算。下发。




#为什么要跳槽

1 已经工作两年多了，对项目有了一定的认识，没有太多的激情了。
2 希望能接受更多更大的挑战，原来的公司还是偏轻松。
3 行业问题，电信行业是个传统的行业，如果在公司想继续发展，就需要学习3gpp的协议文档，了解电信方面的标准，
第这一块不太有兴趣。
4 工作地点的考虑。
