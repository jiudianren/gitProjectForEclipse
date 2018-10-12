#1 PCRF
PCRF包括一个 imp，相当于一个hub。接受其他网元的消息。然后转发给PCRF。
为什么需要这个hub，因为有时候需要对接不同的系统，另外还维护的Diamater的链接。将diamter转成zxos消息。

OLC充当OCS与各外部在线计费上报网元的接口，处理网元发送的在线计费相关的请求，转换成OCS内部使用的的协议（DCC协议），发送给OCS；
接受OCS返回的CCA，转换成各网元使用的协议，发送到网元



PCRF是一个多进程的程序。包括进程管理的进程。消息分发进程和消息处理进程。
PDis消息分发进程，当有多个PDE的时候。
这其中有Rulecache共享内存 。将用户资料加载，更快的访问。静态资料。
当PDE单进程处理性能不够的时候，可以多启动几个PDE进程处理。


#imp

##平台层
由操作系统相关的系统级功能构成，它屏蔽了不同操作系统的细节，为应用提供统一的调用系统API的接口，并提供部分通用的服务和管理程序：监控、启动、停止等。主要包括：
1、	线程管理。OLC采用基于多线程协作处理的架构，负责线程的创建、销毁、健康监
测等
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
##2, 做了一个报表统计进程。  
PDE进程的当前的一些统计信息，发送到报表统计进程后，落地成文件。
##bypass 部分解释
##5  云化管理 和dockerfile的编写
zk的管理
zk的链接管理类。
zk的路径管理类
zk的事件处理类


##6 单元测试

gtest gmock的使用

perl生成，按照现在的目录层级，生成所有类的mock类

[TestCaseName，TestName]，而我对这两个参数的定义是：[TestSuiteName，TestCaseName]，在下一篇我们再来看为什么这样定义

class为suit member为 case


	class TEST_TCdrInDbStatInfo_Suit : public ::testing::Test  {
	protected:
	
	    static void SetUpTestCase()
	    {
	    
	
	    }
	
	    static void TearDownTestCase()
	    {
	    }
	
	    static std::vector<TBalInfo> m_vecBalInfo;
	
	};
	
	TEST( CLASS , member) //suit 和case 
	TEST(TEST_TCdrInDbStatInfo, SetCdrInDBStatMode_01)
	{
	    TCdrInDbStatInfo tObj;
	
	    bool bPara = true;
	    tObj.SetStaticOrNot( bPara);
	    EXPECT_EQ( bPara,  tObj.GetCdrInDBStatMode());
	}
	

    1. EXPECT_*  失败时，案例继续往下执行。

    2. ASSERT_* 失败时，直接在当前函数中返回，当前函数中ASSERT_*后面的语句将不会执行。


7， 后期参与了一次代码重构，重构前的代码有一个历史遗留的全局变量的问题。
    重构之后，接口更加清晰。比如Gx，Sysp,Rx接口。数据和行为分离的。
8 现场问题定位和

