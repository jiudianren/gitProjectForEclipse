https://www.cnblogs.com/haippy/archive/2013/02/21/2920241.html

（一次性触发）One-time trigger

当设置监视的数据发生改变时，该监视事件会被发送到客户端，例如，如果客户端调用了 getData("/znode1", true) 并且稍后 /znode1 节点上的数据发生了改变或者被删除了，客户端将会获取到 /znode1 发生变化的监视事件，而如果 /znode1 再一次发生了变化，除非客户端再次对 /znode1 设置监视，否则客户端不会收到事件通知。

（发送至客户端）Sent to the client

Zookeeper 客户端和服务端是通过 socket 进行通信的，由于网络存在故障，所以监视事件很有可能不会成功地到达客户端，监视事件是异步发送至监视者的，Zookeeper 本身提供了保序性(ordering guarantee)：即客户端只有首先看到了监视事件后，才会感知到它所设置监视的 znode 发生了变化(a client will never see a change for which it has set a watch until it first sees the watch event). 网络延迟或者其他因素可能导致不同的客户端在不同的时刻感知某一监视事件，但是不同的客户端所看到的一切具有一致的顺序。

（被设置 watch 的数据）The data for which the watch was set

这意味着 znode 节点本身具有不同的改变方式。你也可以想象 Zookeeper 维护了两条监视链表：数据监视和子节点监视(data watches and child watches) getData() and exists() 设置数据监视，getChildren() 设置子节点监视。 或者，你也可以想象 Zookeeper 设置的不同监视返回不同的数据，getData() 和 exists() 返回 znode 节点的相关信息，而 getChildren() 返回子节点列表。因此， setData() 会触发设置在某一节点上所设置的数据监视(假定数据设置成功)，而一次成功的 create() 操作则会出发当前节点上所设置的数据监视以及父节点的子节点监视。一次成功的 delete() 操作将会触发当前节点的数据监视和子节点监视事件，同时也会触发该节点父节点的child watch。



zk的永久节点 临时节点


1 路径组织，
2 代码组织

	
	    bool TZNodePathMgr::Initialize()
	{
	    bool bRetFlag = true;
	
	    //初始化持续节点路径
	    InitPermanentPath();
	    //初始化临时节点路径
	    InitEphemeralPath();
	    //初始化ZK节点路径取值
	    SetInitNodePathVal();
	
	    return bRetFlag;
	}
	void TZNodePathMgr::InitPermanentPath()
	{
	    //switcher
	    m_mapPermanentPath[(int32_t)SwitcherPer::hostname] = "/pcrf_root/switcher/hostname";

    //status
    std::string root = "/pcrf_root/host_status";
    m_mapPermanentPath[(int32_t) StatusPer::type] = root + "/type";
    m_mapPermanentPath[(int32_t) StatusPer::status] = root + "/status";
    m_mapPermanentPath[(int32_t) StatusPer::log] = root + "/log";
    m_mapPermanentPath[(int32_t) StatusPer::rtt] = root + "/rtt";
    m_mapPermanentPath[(int32_t) StatusPer::linker_num] = root + "/linker_num";
    m_mapPermanentPath[(int32_t) StatusPer::cpu_usage] =root + "/cpu_usage";
    m_mapPermanentPath[(int32_t) StatusPer::cloud_app_id] = root + "/cloud_app_id";

    if (m_sHostType == "PDE" || m_sHostType == "SPR" || m_sHostType == "ABN")
    {
        m_mapPermanentPath[(int32_t) StatusPer::tps] = root + "/tps";
        m_mapPermanentPath[(int32_t) StatusPer::rulecache] = root + "/rulecache";
    }

 
 
	}
	
	void TZNodePathMgr::InitEphemeralPath()
	{
	    const std::string sHostName = getenv("HOSTNAME");
	    //1. /pcrf_root/switcher/hostname/$HOSTNAME
	    AssignEphemeralPath((int32_t)SwitcherEph::E_HostName, (int32_t)SwitcherPer::hostname, "/" + sHostName);
	    //2./pcrf_root/host_status/?/$hostname
	    AssignEphemeralPath((int32_t) StatusEph::E_Type,             (int32_t) StatusPer::type,   "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_Status,           (int32_t) StatusPer::status, "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_Tps,              (int32_t) StatusPer::tps,    "/" + sHostName);
	    //AssignEphemeralPath((int32_t) StatusEph::E_Log,              (int32_t) StatusPer::log,    "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_Rtt,              (int32_t) StatusPer::rtt,    "/" + sHostName);
	    //AssignEphemeralPath((int32_t) StatusEph::E_Olp,              (int32_t) StatusPer::olp,    "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_CloudAppId,       (int32_t) StatusPer::cloud_app_id, "/" + sHostName);
	    //AssignEphemeralPath((int32_t) StatusEph::E_Test,             (int32_t) StatusPer::testing /* + "/" + sHostName*/); //zxos创建
	    AssignEphemeralPath((int32_t) StatusEph::E_LinkNum,          (int32_t) StatusPer::linker_num, "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_CpuUsage,         (int32_t) StatusPer::cpu_usage, "/" + sHostName);
	    //AssignEphemeralPath((int32_t) StatusEph::E_Module,           (int32_t) StatusPer::module/* , "/" + sHostName*/); //业务创建
	    AssignEphemeralPath((int32_t) StatusEph::E_RuleCacheVersion, (int32_t) StatusPer::rulecache, "/" + sHostName); //当前RuleCache版本
	    AssignEphemeralPath((int32_t) StatusEph::E_PhubModule, (int32_t) StatusPer::phubmodule, "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_ShubModule, (int32_t) StatusPer::shubmodule, "/" + sHostName);
	}
    


# 同步和异步调用



同步调用：
ZOOAPI int zoo_create(zhandle_t * zh, const char *path,
                      const char *value, int valuelen,
                      const struct ACL_vector *acl, int flags,
                      char *path_buffer, int path_buffer_len);
                      
异步调用如下：                      
zoo_acreate函数原型如下：

ZOOAPI int zoo_acreate(zhandle_t * zh, const char *path,
                       const char *value, int valuelen,
                       const struct ACL_vector *acl, int flags,
                       string_completion_t completion, const void *data);
其中参数 string_completion_t completion 即返回字符串的回调函数，那么当 zoo_acreate 调用结束时将会触发 completion 回调函数的调用，同时传递给 completion 的 rc 参数为: ZOK 操作完成；ZNONODE 父节点不存在；ZNODEEXISTS 节点已存在；ZNOAUTH 客户端没有权限创建节点。ZNOCHILDRENFOREPHEMERALS 临时节点不能创建子节点。而 string_completion_t completion 中 const char *value 参数即新节点的路径名（注：如果 zoo_acreate 设置了ZOO_EPHEMERAL，则创建节点成功后，节点名称并不是 zoo_acreate 中 path 参数所指定的名称，而是类似与 /xyz0000000001,/xyz0000000002... 的名称）。另外，string_completion_t completion 中 const void *data 参数即为 zoo_acreate 中的 const void *data。


异步调用有回调函数



## 回调函数  获得句柄后，就随便用了，并把回调函数在  zookeeper_init的时候，设置进去


    m_pZHandle = zookeeper_init(m_sConnectString.c_str(),
                                TZNodeEventMgr::fun_watch,
                                m_iConnectTimeout, 0, (void *)NULL, 0);
                                
                                

TZNodeEventMgr::fun_watch(

