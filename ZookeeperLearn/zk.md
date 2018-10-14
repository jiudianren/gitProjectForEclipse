https://www.cnblogs.com/haippy/archive/2013/02/21/2920241.html

��һ���Դ�����One-time trigger

�����ü��ӵ����ݷ����ı�ʱ���ü����¼��ᱻ���͵��ͻ��ˣ����磬����ͻ��˵����� getData("/znode1", true) �����Ժ� /znode1 �ڵ��ϵ����ݷ����˸ı���߱�ɾ���ˣ��ͻ��˽����ȡ�� /znode1 �����仯�ļ����¼�������� /znode1 ��һ�η����˱仯�����ǿͻ����ٴζ� /znode1 ���ü��ӣ�����ͻ��˲����յ��¼�֪ͨ��

���������ͻ��ˣ�Sent to the client

Zookeeper �ͻ��˺ͷ������ͨ�� socket ����ͨ�ŵģ�����������ڹ��ϣ����Լ����¼����п��ܲ���ɹ��ص���ͻ��ˣ������¼����첽�����������ߵģ�Zookeeper �����ṩ�˱�����(ordering guarantee)�����ͻ���ֻ�����ȿ����˼����¼��󣬲Ż��֪���������ü��ӵ� znode �����˱仯(a client will never see a change for which it has set a watch until it first sees the watch event). �����ӳٻ����������ؿ��ܵ��²�ͬ�Ŀͻ����ڲ�ͬ��ʱ�̸�֪ĳһ�����¼������ǲ�ͬ�Ŀͻ�����������һ�о���һ�µ�˳��

�������� watch �����ݣ�The data for which the watch was set

����ζ�� znode �ڵ㱾����в�ͬ�ĸı䷽ʽ����Ҳ�������� Zookeeper ά�������������������ݼ��Ӻ��ӽڵ����(data watches and child watches) getData() and exists() �������ݼ��ӣ�getChildren() �����ӽڵ���ӡ� ���ߣ���Ҳ�������� Zookeeper ���õĲ�ͬ���ӷ��ز�ͬ�����ݣ�getData() �� exists() ���� znode �ڵ�������Ϣ���� getChildren() �����ӽڵ��б���ˣ� setData() �ᴥ��������ĳһ�ڵ��������õ����ݼ���(�ٶ��������óɹ�)����һ�γɹ��� create() ������������ǰ�ڵ��������õ����ݼ����Լ����ڵ���ӽڵ���ӡ�һ�γɹ��� delete() �������ᴥ����ǰ�ڵ�����ݼ��Ӻ��ӽڵ�����¼���ͬʱҲ�ᴥ���ýڵ㸸�ڵ��child watch��



zk�����ýڵ� ��ʱ�ڵ�


1 ·����֯��
2 ������֯

	
	    bool TZNodePathMgr::Initialize()
	{
	    bool bRetFlag = true;
	
	    //��ʼ�������ڵ�·��
	    InitPermanentPath();
	    //��ʼ����ʱ�ڵ�·��
	    InitEphemeralPath();
	    //��ʼ��ZK�ڵ�·��ȡֵ
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
	    //AssignEphemeralPath((int32_t) StatusEph::E_Test,             (int32_t) StatusPer::testing /* + "/" + sHostName*/); //zxos����
	    AssignEphemeralPath((int32_t) StatusEph::E_LinkNum,          (int32_t) StatusPer::linker_num, "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_CpuUsage,         (int32_t) StatusPer::cpu_usage, "/" + sHostName);
	    //AssignEphemeralPath((int32_t) StatusEph::E_Module,           (int32_t) StatusPer::module/* , "/" + sHostName*/); //ҵ�񴴽�
	    AssignEphemeralPath((int32_t) StatusEph::E_RuleCacheVersion, (int32_t) StatusPer::rulecache, "/" + sHostName); //��ǰRuleCache�汾
	    AssignEphemeralPath((int32_t) StatusEph::E_PhubModule, (int32_t) StatusPer::phubmodule, "/" + sHostName);
	    AssignEphemeralPath((int32_t) StatusEph::E_ShubModule, (int32_t) StatusPer::shubmodule, "/" + sHostName);
	}
    


# ͬ�����첽����



ͬ�����ã�
ZOOAPI int zoo_create(zhandle_t * zh, const char *path,
                      const char *value, int valuelen,
                      const struct ACL_vector *acl, int flags,
                      char *path_buffer, int path_buffer_len);
                      
�첽�������£�                      
zoo_acreate����ԭ�����£�

ZOOAPI int zoo_acreate(zhandle_t * zh, const char *path,
                       const char *value, int valuelen,
                       const struct ACL_vector *acl, int flags,
                       string_completion_t completion, const void *data);
���в��� string_completion_t completion �������ַ����Ļص���������ô�� zoo_acreate ���ý���ʱ���ᴥ�� completion �ص������ĵ��ã�ͬʱ���ݸ� completion �� rc ����Ϊ: ZOK ������ɣ�ZNONODE ���ڵ㲻���ڣ�ZNODEEXISTS �ڵ��Ѵ��ڣ�ZNOAUTH �ͻ���û��Ȩ�޴����ڵ㡣ZNOCHILDRENFOREPHEMERALS ��ʱ�ڵ㲻�ܴ����ӽڵ㡣�� string_completion_t completion �� const char *value �������½ڵ��·������ע����� zoo_acreate ������ZOO_EPHEMERAL���򴴽��ڵ�ɹ��󣬽ڵ����Ʋ����� zoo_acreate �� path ������ָ�������ƣ����������� /xyz0000000001,/xyz0000000002... �����ƣ������⣬string_completion_t completion �� const void *data ������Ϊ zoo_acreate �е� const void *data��


�첽�����лص�����



## �ص�����  ��þ���󣬾�������ˣ����ѻص�������  zookeeper_init��ʱ�����ý�ȥ


    m_pZHandle = zookeeper_init(m_sConnectString.c_str(),
                                TZNodeEventMgr::fun_watch,
                                m_iConnectTimeout, 0, (void *)NULL, 0);
                                
                                

TZNodeEventMgr::fun_watch(

