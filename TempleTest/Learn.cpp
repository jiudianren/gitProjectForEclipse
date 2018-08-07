
/**
 *
 *
 * *默认模板参数  是一个模板类
 *
 * */


template <typename T>
class TCreateUnmsImpl
{
public:
    static T * Create()
    {
        return new T;
    }
    static std::shared_ptr<T> SharePtrCreate()
    {
        return std::make_shared<T>();
    }
    static void Destroy(T *&p)
    {
        if(p == nullptr)
        {
            return ;
        }
        delete p;
        p = nullptr;
    }
};

class TUnmsBase
{
public:
    virtual ~TUnmsBase(){}

public:
    virtual uint32_t  GetUnmsInterval(bool bDefault = false) = 0;
    virtual void SetUnmsInterval(uint32_t iValue) = 0;
};

/*默认模板参数  是一个模板类 */
template <class T, class D, template <class> class Creator = TCreateUnmsImpl>
class TUnmsCommon : public TUnmsBase
{
public:
    TUnmsCommon ()
    {
          m_iUnmsStatTime = UNMS_STAT_TIME_INTERVAL;
          m_pUnmsKpiImpl = Creator<T>::SharePtrCreate();
    }

    virtual
    ~TUnmsCommon (){}

public:
    bool Initialize()
    {
        return m_pUnmsKpiImpl->Initialize(this);
    }

    uint32_t  GetUnmsInterval(bool bDefault = false)
    {
        return bDefault ? UNMS_STAT_TIME_INTERVAL : m_iUnmsStatTime;
    }
    void SetUnmsInterval(uint32_t iValue)
    {
        m_iUnmsStatTime = iValue;
    }

    T &GetKpiImpl(void)
    {
        return *m_pUnmsKpiImpl;
    }

public:
    bool Write(uint16_t iProcPno, const std::string sProcName, D &refData)
    {
        return m_pUnmsKpiImpl->Write(iProcPno, sProcName, refData);
    }

public:
    const uint32_t UNMS_STAT_TIME_INTERVAL = 300; // 默认间隔

private:
    uint32_t m_iUnmsStatTime;
    std::shared_ptr<T> m_pUnmsKpiImpl;
};


class TUnmsKpi200
{
public:
    TUnmsKpi200();

public:
    bool Initialize(TUnmsBase *);

public:
    const int m_iUnmsServiceKey = 200; //Service Key

private:
    std::string m_sUnmsStatInfoFileName;

private:
    TUnmsBase      *m_pUnmsBase;
};


struct TPDEUnmsKpiData
{
    void Clear()
    {
    }
};
TUnmsCommon<TUnmsKpi200, TPDEUnmsKpiData> m_tUnms200;

