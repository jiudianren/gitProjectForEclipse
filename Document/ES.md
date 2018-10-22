# 多线程
asio和多线程的关系。

一个asio一个线程
一个asio多个线程。
多个asio多个线程； 每个线程有用自己的io_service; 

该线程的所有异步动作在本线程上异步处理


#异步和同步

同步和异步是针对应用程序和内核的交互而言的，同步指的是用户进程触发IO操作并等待或者轮询的去查看IO操作是否就绪，
而异步是指用户进程触发IO操作以后便开始做自己的事情，而当IO操作已经完成的时候会得到IO完成的通知（异步的特点就是通知）。

而阻塞和非阻塞是针对于进程在访问数据的时候，根据IO操作的就绪状态来采取的不同方式，说白了是一种读取或者写入操作函数的实现方式，阻塞方式下读取或者写入函数将一直等待，而非阻塞方式下，读取或者写入函数会立即返回一个状态值。  

一般来说I/O模型可以分为：同步阻塞，同步非阻塞，异步阻塞，异步非阻塞IO



#异步工作
Post 
strand

这个部分岗接手了一个多月，asio和beast使用这一块，之前有个RSp，项目用过，我就参考了他的代码。
由于他做的也是基于http的协议的，很多地方可以借鉴。也我做的这个，考虑了 一下我的做的这个业务流程，和他的那个比较接近。


#IPC部分创建几个io——service和线程，直接将线程和io_service进行绑定。

workserver，io_service 有自己的 io_context,
启动的是有线程大小.

	bool work_service_base::run(service_interface *ipc_service)
	{
	    std::lock_guard<std::mutex> guard(mtx_for_suspend_);
	    if (initialize(ipc_service) == false)
	    {
	        return false;
	    }
	    // Create a pool of threads_ to run all of the io_contexts.
	    for (std::size_t i = 0; i < thread_pool_size_; ++i)
	    {
	        threads_.push_back(std::make_shared<std::thread>([=]()
	        {
	            if (thread_local_initialize() == false)
	            {
	                return;
	            }
	            boost::system::error_code ec;
	            io_context_.run(ec);
	        }));
	    }
	
	    return true;
	}




2 启动net——workservice

  	
	 1std::pair<bool, std::string> operator()(const NS_Net_Link_Configurator::net_service_cmd &cmd) const;
	  
	  2---->
	               net_service_creator::make_net_service_handler_t<tcp_service_base> creator;
	                auto http_work_service = std::dynamic_pointer_cast<http_work_service_base>(work_service);
	                if (http_work_service)
	                {
	                    creator = http_work_service->http_service_creator();
	                }
	                else
	                {
	                    creator = net_service_creator::instance().tcp(work_service->net_service_name());
	                }
	
	                if (creator)
	                {
	                    if (service_->add_tcp_acceptor(cmd.ip, std::to_string(cmd.port),
	                            std::bind(creator, std::placeholders::_1, cmd.work_service_name, cmd_parameters),
	                            get_ssl_context(cmd_parameters, true)) != 0)
	                    {
	                        ret = true;
	                    }
	                }
                
                
                
	 3   std::shared_ptr<tcp_acceptor_service> ipc_controller::add_tcp_acceptor(const std::string &ip, const std::string &port,
	        add_net_service_handler_t<tcp_service_base> add_net_service_handle, tcp_service_base::ssl_context ctx)
	{
	    std::lock_guard<std::mutex> guard(mtx_for_ipc_controller_cmd_deal_);
	
	    boost::asio::io_context &io = io_context_pool_.get_io_context();
	    auto sp = tcp_acceptor_service::creator(io, ip, port, [&io, add_net_service_handle]()
	    {
	        return add_net_service_handle(io);
	    }, ctx);
	    if (sp->start(network_service_base::en_net_state::server))
	    {
	        return sp;
	    }
	    else
	    {
	        return nullptr;
	    }
	}

net——worksercie的io ——service 和 workservice的不一样


进而关联到监听套接字上，---》进而关联到 已经连接的套接字上。



	std::shared_ptr<tcp_acceptor_service> ipc_controller::add_tcp_acceptor(const std::string &ip, const std::string &port,
	        add_net_service_handler_t<tcp_service_base> add_net_service_handle, tcp_service_base::ssl_context ctx)
	{
	    std::lock_guard<std::mutex> guard(mtx_for_ipc_controller_cmd_deal_);
	 
	    auto sp = tcp_acceptor_service::creator(io_context_pool_.get_io_context()  , ip, port,   //lpf io_context_1
	            [this, add_net_service_handle]()
	            {
	                return add_net_service_handle(io_context_pool_.get_io_context());    // lpf io_context_2
	            }, ctx);
	    if (sp->start(network_service_base::en_net_state::server))
	    {
	        return sp;
	    }
	    else
	    {
	        return nullptr;
	    }
	}

后续的Http请求，就将关联在这个线程上。
             
             auto new_connection(make_tcp_service_ptr_());
             new_connection->socket() = std::move(*socket_tmp);
             //new_connection->socket() 归属于  io_context_2 
             //socket_tmp               归属于  io_context_1
             // std::move 以后，所有有关socket_tmp 的异步动作，将会归属于  io_context_2 所关联的线程操作
                    
一次http请求，就在相关的socket，和持有该socket的对象。
所在的按个线程，进行处理，就可以了。
一些公共资源，写成了thread_local .

能保证一个io_server的动作在同一个线程中被调用。


    bool ret =  ns->cb_insert( sHopByHopId , [sp](shared_mutable_buffer_1& buffer , cb_additional_agrs *  pArg)  {

        sp->io_context().post(  [sp , buffer]() mutable {
            sp->DealAAAResp(buffer);
        });
    });

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



1 异步网络的调试：



