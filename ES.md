# 多线程
asio和多线程的关系。

一个asio一个线程
一个asio多个线程。
多个asio多个线程； 每个线程有用自己的io_service;

#异步和同步

异步文件IO也就是重叠IO。在同步文件IO中，线程启动一个IO操作然后就立即进入等待状态，直到IO操作完成后才醒来继续执行。而异步文件IO方式中，线程发送一个IO请求到内核，然后继续处理其他的事情，内核完成IO请求后，将会通知线程IO操作完成了。如果IO请求需要大量时间执行的话，异步文件IO方式可以显著提高效率，因为在线程等待的这段时间内，CPU将会调度其他线程进行执行，如果没有其他线程需要执行的话，这段时间将会浪费掉（可能会调度操作系统的零页线程）。如果IO请求操作很快，用异步IO方式反而还低效，还不如用与方式。同步IO在同一时刻只允许一个IO操作，也就是说对于同一个文件句柄的IO操作是序列化的，即使使用两个线程也不能同时对同一个文件句柄同时发出读写操作。重叠IO允许一个或多个线程同时发出IO请求


#异步工作
Post 
strand


这个部分岗接手了一个多月，asio和beast使用这一块，之前有个RSp，项目用过，我就参考了他的代码。
由于他做的也是基于http的协议的，很多地方可以借鉴。也我做的这个，考虑了 一下我的做的这个业务流程，和他的那个比较接近。


#
IPC部分创建几个io——service和线程，直接将线程和io_service进行绑定。

一次http请求，就在相关的socket，所在的按个线程，进行处理，就可以了。
一些公共资源，写成了thread_local .

1 启动work_service_ptr，主要是为了绑定 wokr-service和io_service.并没有建立任何链接。但work_service决定了其将会建立什么类型的网络连接，acceptor ， connect .

2 通过work_service_name去启动 ，改work_service绑定 net_service的类型。tcp，udp。
     acceptor或者  connect.去启动net_service;  
     
3 以acceptor为例， 这个时候启动net_service start 进入 acceptor 
4 当接到一个连接，就会建立一个对应的，socket，并新建一个处理对象，持有该socket，这个时候，所有的业务业务逻辑就可以展开。

为什么要这么做，这样可以动态的启动多个链接， 
 


#业务部分

了解协议文档， 

1 数据和动作相分离.  
2 动作注册.方便扩展动作。

动作之前有setdata.
动作run之后，有getResponse.

有diamater的交互。当发送完dimater，请求之后，需要等待其回复。并且与当前的http会话类，不能析构，
这个时候，使用共享指针，dimater发送了之后，会绑定一个响应处理函数。 这个时候，将http的回话类的共享指针，作为
lambda的捕获参数，传入 。保持http会话类不被析构。
完成与AAA的交互。
EAP_AKA请求。




