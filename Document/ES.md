# ���߳�
asio�Ͷ��̵߳Ĺ�ϵ��

һ��asioһ���߳�
һ��asio����̡߳�
���asio����̣߳� ÿ���߳������Լ���io_service; 

���̵߳������첽�����ڱ��߳����첽����


#�첽��ͬ��

ͬ�����첽�����Ӧ�ó�����ں˵Ľ������Եģ�ͬ��ָ�����û����̴���IO�������ȴ�������ѯ��ȥ�鿴IO�����Ƿ������
���첽��ָ�û����̴���IO�����Ժ�㿪ʼ���Լ������飬����IO�����Ѿ���ɵ�ʱ���õ�IO��ɵ�֪ͨ���첽���ص����֪ͨ����

�������ͷ�����������ڽ����ڷ������ݵ�ʱ�򣬸���IO�����ľ���״̬����ȡ�Ĳ�ͬ��ʽ��˵������һ�ֶ�ȡ����д�����������ʵ�ַ�ʽ��������ʽ�¶�ȡ����д�뺯����һֱ�ȴ�������������ʽ�£���ȡ����д�뺯������������һ��״ֵ̬��  

һ����˵I/Oģ�Ϳ��Է�Ϊ��ͬ��������ͬ�����������첽�������첽������IO



#�첽����
Post 
strand

������ָڽ�����һ�����£�asio��beastʹ����һ�飬֮ǰ�и�RSp����Ŀ�ù����ҾͲο������Ĵ��롣
����������Ҳ�ǻ���http��Э��ģ��ܶ�ط����Խ����Ҳ����������������� һ���ҵ��������ҵ�����̣��������Ǹ��ȽϽӽ���


#IPC���ִ�������io����service���̣߳�ֱ�ӽ��̺߳�io_service���а󶨡�

workserver��io_service ���Լ��� io_context,
�����������̴߳�С.

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




2 ����net����workservice

  	
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

net����worksercie��io ����service �� workservice�Ĳ�һ��


���������������׽����ϣ�---������������ �Ѿ����ӵ��׽����ϡ�



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

������Http���󣬾ͽ�����������߳��ϡ�
             
             auto new_connection(make_tcp_service_ptr_());
             new_connection->socket() = std::move(*socket_tmp);
             //new_connection->socket() ������  io_context_2 
             //socket_tmp               ������  io_context_1
             // std::move �Ժ������й�socket_tmp ���첽���������������  io_context_2 ���������̲߳���
                    
һ��http���󣬾�����ص�socket���ͳ��и�socket�Ķ���
���ڵİ����̣߳����д����Ϳ����ˡ�
һЩ������Դ��д����thread_local .

�ܱ�֤һ��io_server�Ķ�����ͬһ���߳��б����á�


    bool ret =  ns->cb_insert( sHopByHopId , [sp](shared_mutable_buffer_1& buffer , cb_additional_agrs *  pArg)  {

        sp->io_context().post(  [sp , buffer]() mutable {
            sp->DealAAAResp(buffer);
        });
    });

1 ����work_service_ptr����Ҫ��Ϊ�˰� wokr-service��io_service.��û�н����κ����ӡ���work_service�������佫�Ὠ��ʲô���͵��������ӣ�acceptor �� connect .

2 ͨ��work_service_nameȥ���� ����work_service�� net_service�����͡�tcp��udp��
     acceptor����  connect.ȥ����net_service;  
     
3 ��acceptorΪ���� ���ʱ������net_service start ���� acceptor 
4 ���ӵ�һ�����ӣ��ͻὨ��һ����Ӧ�ģ�socket�����½�һ��������󣬳��и�socket�����ʱ�����е�ҵ��ҵ���߼��Ϳ���չ����

ΪʲôҪ��ô�����������Զ�̬������������ӣ� 
 


#ҵ�񲿷�

�˽�Э���ĵ��� 

1 ���ݺͶ��������.  
2 ����ע��.������չ������

����֮ǰ��setdata.
����run֮����getResponse.

��diamater�Ľ�������������dimater������֮����Ҫ�ȴ���ظ��������뵱ǰ��http�Ự�࣬����������
���ʱ��ʹ�ù���ָ�룬dimater������֮�󣬻��һ����Ӧ�������� ���ʱ�򣬽�http�Ļػ���Ĺ���ָ�룬��Ϊ
lambda�Ĳ������������ ������http�Ự�಻��������
�����AAA�Ľ�����
EAP_AKA����



1 �첽����ĵ��ԣ�



