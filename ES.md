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



#框架部分是别人写的

IPC部分创建一个io_service池，和线程
1 启动work_service_ptr，主要是为了绑定 wokr-service和io_service.并没有建立任何链接。work_service 
2 通过work_service_name去启动 ，改work_service绑定 net_service的类型。tcp，udp。
     acceptor或者  connect.去启动net_service;  
     
3 以acceptor为例， 这个时候启动net_service start 进入 acceptor 
4 当接到一个连接，就会建立一个对应的，socket，并新建一个处理对象，持有该socket，这个时候，所有的业务业务逻辑就可以展开。 
 


#业务部分全部由我负责


数据和动作相分离
动作注册

有diamater的交互。




