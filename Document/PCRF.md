#1 PCRF
PCRF����һ�� imp���൱��һ��hub������������Ԫ����Ϣ��Ȼ��ת����PCRF��
Ϊʲô��Ҫ���hub����Ϊ��ʱ����Ҫ�ԽӲ�ͬ��ϵͳ�����⻹ά����Diamater�����ӡ���diamterת��zxos��Ϣ��

OLC�䵱OCS����ⲿ���߼Ʒ��ϱ���Ԫ�Ľӿڣ�������Ԫ���͵����߼Ʒ���ص�����ת����OCS�ڲ�ʹ�õĵ�Э�飨DCCЭ�飩�����͸�OCS��
����OCS���ص�CCA��ת���ɸ���Ԫʹ�õ�Э�飬���͵���Ԫ


PCRF��һ������̵ĳ���
�������̹�����̺�ҵ����̡� zxinit ��zxmonitor �ȸ��������̵������ͼ�أ����̵�����

ͨ������ʵ��

��Ϣ�ַ����̺���Ϣ������̡�
PDis��Ϣ�ַ����̣������簴����ַ��ȣ�
���ж��PDE��ʱ��
��������Rulecache�����ڴ������� �����û����ϼ��أ�����ķ��ʡ���̬���ϡ�

���а��������ڴ�汾���� ���� �½��ʷѼƻ��������ڴ���½���ˢ�£�PDE�ԷѰ汾���л�
��PDE�����̴������ܲ�����ʱ�򣬿��Զ���������PDE���̴���

#imp

##ƽ̨��
�ɲ���ϵͳ��ص�ϵͳ�����ܹ��ɣ��������˲�ͬ����ϵͳ��ϸ�ڣ�ΪӦ���ṩͳһ�ĵ���ϵͳAPI�Ľӿڣ����ṩ����ͨ�õķ���͹�����򣺼�ء�������ֹͣ�ȡ���Ҫ������
1��	�̹߳���OLC���û��ڶ��߳�Э������ļܹ��������̵߳Ĵ��������١���������
2��	��·������OLC���ⲿ��Ԫ��OLC��OCS����·���й����綨ʱ�����·�Ƿ�
��������·�Ƿ��ѹ�����������ȡ�֧��TCP��UDP��SSL��
3��	��Ϣ���й����߳�֮��ʹ����Ϣ���н���ͨ��
4��	�����ڴ��������OLCƽ̨�еĹ����ڴ�������Լ���service�ӿڵĹ����ڴ�
�����Ĵ���
5��	��ʱ������Ϊ������Ҫ��ʱ�������¼��ṩ�����綨ʱ���ͳ�����ݵ�
6��	��־�����ṩͳһ����־����ӿڣ�������־�ļ����ɵĸ�������С��
7��	���ù������������ļ��Ķ�ȡ��д��
8��	ϵͳ�ں���Դ�������߳������ź�����


##imp�ļܹ��������ģ�

OLC���ö��̼ܹ߳������бȽ���Ҫ��һ���ǣ���socket�շ����ݵĲ���������ҵ��
�����߼��Ƿ���ģ����ϵͳ����Ҫ�������̣߳�
1��	socket�̡߳�һ��socket�����������̣߳�socket�����̸߳���ӶԶ�recv���ݣ�
socket�����̸߳���send���ݵ��Զˡ�
2��	ҵ�����̡߳���ͨ��������service380��service366�ȡ�
socket�����߳��յ���Ԫ����Ϣ����Ҫ������Ϣת����ҵ���߳�������ҵ���̴߳�
������Ϣ����Ҫ����Ϣת����socket�����̣߳��Ӷ����͵���Ԫ��

�ŵ�����Ϣ��������


zxos��ϢЭ���һЩ���ݣ�

//zxos��Ϣͷ�ṹ����Ϣͷ���������Ϣ�������
typedef struct
{
  		UINT16  pno         //�̣߳�����̣���zxos�ڵ��ڵ��߼����
  		UINT8   module;     //zxos�ڵ��ģ���
  		UINT8   postOffice; //�ֺţ�û����ô���������Ҫ��������һ��
} PID;


typedef struct
{
  		PID     sender;   //��Ϣ���ͷ���PID
  		PID     receiver; //��Ϣ���շ���PID
  		UINT16  event;    //���͵���Ϣ���¼�ID
  		UINT16  len;      //��Ϣ����ֽ���
} MSG_HEAD;


���������һ�������ӡ�Diamater�� DWR ��DWA��Ϣά���������������ʱ��ʹ�õ� ��Ϣͷ����������Ϣ�ķ�ʽ��


�õ���msgget systemv��Ϣ����

OLCһ����3����Ϣ���У�

1��	��Ϣ����0
�����ߣ�Ϊsocket�����̣߳����յ��Զˣ�OCS���ⲿ��Ԫ�������ݺ󣬽����ݷ��뵽
��Ϣ����0
�����ߣ�Ϊҵ�����̣߳���service380������Ϣ����0ȡ��Ϣ���д���
2��	��Ϣ����1
�����ߣ�Ϊҵ�����̣߳���service380����������Ϣ�󣬽���ת������Ԫ����Ϣ����
����Ϣ����1
�����ߣ�Ϊsocket�����̣߳��Ӹö���ȡ��Ϣ��ͨ��socket���͵���Ԫ
3��	��Ϣ����2
����impmonitor���̶�OLC�ĸ��߳̽��н�����飬һ�㲻��Ҫ��ע

���͵���Ϣ���е���Ϣ��ʵ����Ϊһ��ָ�룬��ָ��ָ���������ݣ�����zxos��Ϣ
ͷ�Լ�zxos������


# �ҵĹ���

�Ӳ��������Ŀ��������Ҫ���Ĺ���������
##1��ǰ���˽���Ŀ���롣���һЩϵͳ��bug.

�����bug�ĸ������ֶ��У�������������ж�����Ĵ�������һЩ�˽⡣

##2, ����һ������ͳ�ƽ��̡����������̡�  
PDE���̣���pde��ҵ����̣������ڲ����������ҵ����Ϣ��ͨ����Ϣ�����͵ı���ͳ�ƽ��̡�
����ͳ�ƽ��̣����ݷ��࣬ʱ�䣬�Ƚ���Щ��Ϣ�����и�ʽ������� csv��ʽ������������س��ļ���
���������̣�����غ���ļ������ж�ȡ���������ݿ⡣

##bypass ���ֽ���

bypass�����Ǹ�������ܣ���pde������߹ҵ������ߴ�������ĵ�����£�
�� olc ������̼򵥴�������ظ�Ĭ���ײͣ���ظ�������ȡ�
����������֮�󣬻�û���ֳ�ʹ�á�


##5  �ƻ����� ��dockerfile�ı�д
dockerfile�ı�д�� ��ԭ���Ĵ���ת��Ϊ����

��ѧϰ����zk��һЩ����֪ʶ����һЩapi��
����zk��ʹ�ã����ֳ��ˣ�zk���������飬������Щapi�����˰�װ��
zk�����ӹ����ࡣ  ---- ������ͻ�ȡzk�����ӵľ��
zk��·��������   ---����ʼ��·��
zk���¼�������    ---�� ��zk�ڵ�仯��ʱ����д��� ����zk����init��ʱ��ע��


##��һ��Ҫ����� todo


###����� �¼��У�
	void TZNodeEventMgr::fun_watch(zhandle_t *zhandle, 
								const int iEvent, 
									int iState, 
									const char* sPath, 
									void* context)
	{
	
		    // ʹ����ֻ��ע�����¼�
	    const std::set<int> &refEventCare = GetSelf()->GetEventCare();
	    if(!refEventCare.empty())
	    {
	        bProcEvent = refEventCare.find(iEvent) != refEventCare.end();
	        VLOG_INFO("TZNodeEventMgr::fun_watch In Event Only Care,  Event is {}", iEvent);
	    }
	    if (iEvent == ZOO_SESSION_EVENT) 
	    //�ỰʧЧ�¼����ͻ��������˶Ͽ�������ʱ����
	    {
	    }
	    else if (iEvent == ZOO_CHANGED_EVENT) 
	    //�ڵ����ݸı��¼�����watchͨ��zoo_exists()��zoo_get()����
	    {
	            if(bProcEvent)
		        {
		            ProZooChangedEvent(zhandle, sPath);
		        }
	    }
	    else if (iEvent == ZOO_CREATED_EVENT) 
	    //�ڵ㴴���¼�����Ҫwatchһ�������ڵĽڵ㣬���ڵ㱻����ʱ��������watchͨ��zoo_exists()����
	    {
	    }
	    else if (iEvent == ZOO_DELETED_EVENT) 
	    //�ڵ�ɾ���¼�����watchͨ��zoo_exists()��zoo_get()����
	    {
	    }
	    else if (iEvent == ZOO_CHILD_EVENT) 
	    //�ӽڵ��б�ı��¼�����watchͨ��zoo_get_children()��zoo_get_children2()����
	    {
	    }
	}
	
	

### ProZooChangedEvent ʾ��

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
	
	    //1.��ʼ����������
	    bRetFlag = m_pHostStatusMgr->Initialize(E_SvsType::PCRF);
	    //2.��ʼ������·��
	    bRetFlag = bRetFlag && m_pZNodePathMgr->Initialize();
	    //3.����Ǳ��λỰ��ʱ�ڵ㣨���������ӳٵ���ɵķǱ��λỰ��ʱ�ڵ�δ��ʱ�ͷŵ������
	    bRetFlag = bRetFlag && m_pZNodePathMgr->DeleteEphemeralNode();
	    //4.ͬ��·���ڵ㵽ZK������
	    bRetFlag = bRetFlag && m_pZNodePathMgr->SyncPathToZooKeeper();
	    //5.����watcher�ͻص���Ϣ������־����
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
	
	        //һ��·����Ӧһ�����Թ���
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
	
	
��Ҫ�ǰ�zk��Ϊ ���ݷ����Ͷ��� ���ṩ������ƽ̨��ǰ�����ڵ�ҵ����̵�һЩ��Ϣ��
�ڶ��Ƿֲ�ʽЭ��֪ͨ������ ������ٹ��ܣ�
֮ǰ������������£�ͨ��������̷�һ����Ϣ�Ϳ��ˣ��ƻ��Ժ󣬸�����������Ҫ֪����Ϣ��
���ƻ�����ģ���zk���Ϳ���ͨ������������һ���䶯���ø����������д��� 


zookeeperӦ�õĵ��ͳ��� 
	3.1�����ݷ����붩�ģ��������ģ� 
	3.2���������� 
	3.3���ֲ�ʽЭ������/֪ͨ 
	3.4��Masterѡ�� 
	3.5���ֲ�ʽ�� 


������Ҫ�õ��� 
���ݷ����Ͷ���    --�� ����ƽ̨�鿴 
�ֲ�ʽЭ������/֪ͨ   --��������٣���־����������  �ķ��� 

##6 ��Ԫ����

gtest gmock��ʹ��

perl���ɣ��������ڵ�Ŀ¼�㼶�������������mock��

[TestCaseName��TestName]�����Ҷ������������Ķ����ǣ�
[TestSuiteName��TestCaseName]������һƪ����������Ϊʲô��������


classΪsuit memberΪ case


7�� ���ڲ�����һ�δ����ع����ع�ǰ�Ĵ�����һ����ʷ������ȫ�ֱ��������⡣
RatableEvent�����⣬�кܶ����ԣ����ڱ��棬������Ϣ�е�avp�����·���Ϣ�е�avp�� �����̫ӷ���ˣ������������ʱ�򣬶�λ��ʱ��Ӱ����������ٶȡ����������ԭ��

 �ع�֮�󣬽ӿڸ���������
 ����Gx��Sysp,Rx�ӿڣ��Ͳ����ж��ӿڣ�
 
gx,sysp,rx�Ƚӿڽ���Ҫ����Ϣ�����ø������ж��ӿڣ������ж��󣬸����ӿ���ȡ�ı�Ҫ�����ݡ�
 
 �����ӿڸ��������� 
 �������ݺ���Ϊ���롣
 ���ݺ���Ϊ����ġ�
    
8 �ֳ����ⶨλ��RTʱ�����Ǵ�
rt�ο�������̫�࣬���Լƻ���ʧЧʱ�䣬ʱ�β��Ե���Чʱ�䣬�ػ�ʧЧʱ�䣬�˱�ʧЧʱ��ȵȣ�
������⣬���ǳ��֣����ң����ʱ����趨���ֲ��ڳ���ĸ����ط�����RTʱ�䣬�����ʱ�򣬾���Ҫ��ͣ��׷��RT�ο�����Щֵ���������˷�ʱ�䡣
�����Ҿ����飬����һ��RT�࣬�Ͳο�ʱ������͵�ö��ֵ��������ÿ����rt�Ĳο�ʱ���ʱ�򣬾ͽ��䱣�浽�����С�
�ȵ�����·���Ӧ��Ϣ��ʱ���ڽ���ֵ�������㡣�·���




#ΪʲôҪ����

1 �Ѿ�����������ˣ�����Ŀ����һ������ʶ��û��̫��ļ����ˡ�
2 ϣ���ܽ��ܸ���������ս��ԭ���Ĺ�˾����ƫ���ɡ�
3 ��ҵ���⣬������ҵ�Ǹ���ͳ����ҵ������ڹ�˾�������չ������Ҫѧϰ3gpp��Э���ĵ����˽���ŷ���ı�׼��
����һ�鲻̫����Ȥ��
4 �����ص�Ŀ��ǡ�
