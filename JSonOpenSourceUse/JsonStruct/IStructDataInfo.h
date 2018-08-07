

#ifndef SERVICELIB_SERIALIZE_ISTRUCTDATAINFO_H_
#define SERVICELIB_SERIALIZE_ISTRUCTDATAINFO_H_


#include <vector>
#include <string>
#include <map>
#include "jsoncpp/include/json/json.h"

/*
 * 层级结构 的时候，
 * 当某一层级，写入数据不为空时，需要逐级向上传递，都不为空
 * 当在某一层级，执行clear时，需要向下层级，全部，置空
 *
 * */


namespace TOOLS
{
    std::string id_times(const char *p0, int iIdx);
    std::string id_times(std::string p0, int iIdx);
}

//
// Structure Data Type
//
enum E_Data_Type
{
    E_TYPE_SIGNEDCHAR    = 1,
    E_TYPE_UNSIGNEDCHAR  = 2,
    E_TYPE_SIGNEDINT     = 3,
    E_TYPE_UNSIGNEDINT   = 4,
    E_TYPE_SIGNEDINT64   = 5,
    E_TYPE_UNSIGNEDINT64 = 6,
    E_TYPE_AsciiString   = 7,
    E_TYPE_BinaryString  = 9
    //TODO Add New Type
};

enum E_Object_Type
{
    E_OBJECT_STRUCT  = 1,
    E_OBJECT_VARIANT = 2,
    E_OBJECT_ARRAY   = 3
};

struct IStructUnknow
{
    const E_Object_Type _object;
    IStructUnknow(E_Object_Type id) :
      _object(id)
    {
        m_bEmpty = true;
        m_pParent = NULL;
    }

    virtual ~IStructUnknow()
    {
    }

    virtual const char *getid(void) = 0;
    virtual void clear(void)
    {
        if(IsEmpty())
        {
            return;
        }
        m_bEmpty = true;
        if(GetParent())
        {
            GetParent()->adjust();
        }
    }
    bool IsEmpty(void)
    {
        return m_bEmpty;
    }
    void HasValue(void)
    {
        m_bEmpty = false;
        RootHasValue();
    }
    void SetParent(IStructUnknow *val)
    {
        m_pParent = val;
    }

    IStructUnknow * GetParent()
    {
        return m_pParent;
    }

public:
    void adjust();

public:
    virtual bool serialize(Json::Value &value) = 0;
    virtual bool unserialize(Json::Value &value) = 0;

private:
    void RootHasValue()
    {
        IStructUnknow *pNode = this->GetParent();
        while(pNode != NULL && pNode->IsEmpty())
        {
            pNode->HasValue();
            pNode = pNode->GetParent();
        }
    }
private:
    bool m_bEmpty;
    IStructUnknow *m_pParent;
};

struct IStructItemType : public IStructUnknow
{
    const E_Data_Type type;

    IStructItemType(E_Data_Type t) :
      IStructUnknow(E_OBJECT_VARIANT), type(t)
    {
    }

    virtual ~IStructItemType()
    {
    }

    virtual bool serialize(Json::Value &value);
    virtual bool unserialize(Json::Value &value);
};


template <typename T, E_Data_Type T2>
struct TSerialNumberBase : public IStructItemType
{
    TSerialNumberBase() : IStructItemType(T2)
    {
        m_tValue = {};
    }
    const char *getid(void)
    {
        return m_sIden.c_str();
    }
    IStructUnknow * setid(const char *val)
    {
        m_sIden = val;
        return this;
    }
    T get()
    {
        return m_tValue;
    }
    void set(T val)
    {
        m_tValue = val;
        HasValue();
    }
    TSerialNumberBase &operator = (T val)
    {
        set(val);
        return *this;
    }
    void clear(void)
    {
        if(IsEmpty())
        {
            return ;
        }
        m_tValue = {};
        IStructUnknow::clear();
    }

private:
    std::string   m_sIden;
    T             m_tValue;
};

typedef TSerialNumberBase<int8_t, E_TYPE_SIGNEDCHAR> TSignedChar;
typedef TSerialNumberBase<uint8_t, E_TYPE_UNSIGNEDCHAR> TUnsignedChar;
typedef TSerialNumberBase<int32_t, E_TYPE_SIGNEDINT> TSignedInt;
typedef TSerialNumberBase<uint32_t, E_TYPE_UNSIGNEDINT> TUnsignedInt;
typedef TSerialNumberBase<int64_t, E_TYPE_SIGNEDINT64> TSignedInt64;
typedef TSerialNumberBase<uint64_t, E_TYPE_UNSIGNEDINT64> TUnsignedInt64;


struct TAsciiString : public IStructItemType
{
    TAsciiString() : IStructItemType(E_TYPE_AsciiString)
    {
    }
    const char *getid(void)
    {
        return m_sIden.c_str();
    }
    IStructUnknow *  setid(const char *val)
    {
        m_sIden = val;
        return this;
    }
    const char *get()
    {
        return (char*)m_tOctetString.c_str()();
    }
    unsigned int size()
    {
        return m_tOctetString.size();
    }

    void set(const char *val)
    {
        if(val != NULL)
        {
            unsigned int len = (unsigned int)strlen(val);
            m_tOctetString.clear();
            m_tOctetString.append(val);
            HasValue();
        }
    }

    TAsciiString &operator = (const char * val)
    {
        set(val);
        return *this;
    }

    TAsciiString &operator = (const std::string &str)
    {
        set(str.c_str());
        return *this;
    }

    void clear(void)
    {
        m_tOctetString.clear();
        IStructUnknow::clear();
    }
private:
    std::string   m_sIden;
    std::string  m_tOctetString;
};

//
// Structure Interface
//
struct IStructData  : public IStructUnknow
{
    IStructData(const char *id1)
    :  IStructUnknow(E_OBJECT_STRUCT), m_siden(id1)
    {
        m_mapNodes.clear();
    }
    virtual ~IStructData(){}

    const char *getid(void)
    {
        return m_siden.c_str();
    }

    IStructUnknow *  setid(const char *val)
    {
        m_siden = val;
        return this;
    }

    typedef std::map<std::string, IStructUnknow*>::iterator iterIUnknow;
    typedef std::map<std::string, IStructUnknow*>::const_iterator constiterIUnknow;

public:
    virtual bool serialize(Json::Value &value);
    virtual bool unserialize(Json::Value &value);

public:
    virtual void registerall(void) = 0;

    void add(IStructUnknow *pEles)
    {
        pEles->SetParent(this);
        m_mapNodes.insert(std::make_pair(pEles->getid(), pEles));
    }
    void clear(void);
    void adjust(IStructUnknow *pParent);
    void cursubclear(void);
    bool soncleared(void);

private:
    IStructData();

private:
    std::string m_siden;
    std::map<std::string, IStructUnknow*> m_mapNodes;
};

struct IStructArraryBase : public IStructUnknow
{
    IStructArraryBase() : IStructUnknow(E_OBJECT_ARRAY)
    {
    }

    const char *getid(void)
    {
      return m_sIden.c_str();
    }

    virtual void clear(void)
    {
        if(IsEmpty())
        {
            return;
        }

        // sub level clear
        cursubclear();
    }
    virtual void cursubclear(void) = 0;
    virtual bool soncleared(void) = 0;

    IStructUnknow *  setid(const char *val)
    {
        m_sIden = val;
        return this;
    }

private:
    std::string   m_sIden;
};

template <typename T>
struct IStructArraryData : public IStructArraryBase
{
    IStructArraryData()
    {
        m_vecNodes.clear();
        m_iUsedNodes = 0;
    }

    virtual ~IStructArraryData()
    {
        Destroy();
        m_iUsedNodes = 0;
    }

    unsigned int size(void)
    {
        return (unsigned int)m_iUsedNodes;
    }

    unsigned int capacity(void)
    {
        return (unsigned int)m_vecNodes.size();
    }

    T *get(unsigned int idx)
    {
        if(idx < capacity() && idx < size())
        {
            return m_vecNodes[idx];
        }
        return NULL;
    }

    T *NewNode(void)
    {
        T* p = NULL;
        if(m_iUsedNodes < capacity())
        {
            p = m_vecNodes[m_iUsedNodes];
        }
        else
        {
            p = new T();
            insert(p);
        }
        m_iUsedNodes ++;
        return p;
    }

    T * operator[](unsigned int idx)
    {
        return get(idx);
    }

    typedef typename std::vector<T*>::iterator vecArrayIter ;

public:
    bool serialize(Json::Value &value)
    {
        bool bRetFlag = true;
        vecArrayIter it = m_vecNodes.begin();
        for(it = m_vecNodes.begin(); it != m_vecNodes.end(); it ++)
        {
            IStructUnknow *pitem = (IStructUnknow*)(*it);
            if(pitem->IsEmpty())
            {
                continue;
            }
            Json::Value item;
            switch(pitem->_object)
            {
                case (E_OBJECT_STRUCT):
                {
                    IStructData *p1 = (IStructData*)(*it);
                    p1->serialize(item);
                }
                break;
                default:
                {
                  bRetFlag = false; // at least one unserialize failed!
                }
                break;
            }
            value.append(item);
        }
        return bRetFlag;
    }
    bool unserialize(Json::Value &value)
    {
        bool bRetFlag = false;
        for(unsigned int i = 0; i < value.size(); i ++)
        {
            Json::Value &refValue = value[i];
            Json::ValueType type  = refValue.type();

            if(type != Json::objectValue)
            {
                continue;
            }

            T* pNode = get(i);
            if(pNode == NULL)
            {
                pNode = NewNode();
            }

            IStructData *pStruct = (IStructData*) pNode;
            pStruct->unserialize(refValue);

            bRetFlag = true;
        }

        return bRetFlag;
    }

    void clear(void)
    {
        if(IsEmpty())
        {
            return;
        }

        // sub level clear
        cursubclear();

        m_iUsedNodes = 0;
    }


private:
    void insert(T *node)
    {
        node->SetParent(this);
        m_vecNodes.push_back(node);
    }

    void cursubclear(void)
    {
        vecArrayIter it;
        for(it = m_vecNodes.begin(); it != m_vecNodes.end(); it ++)
        {
            (*it)->cursubclear();
            switch((*it)->_object)
            {
                case (E_OBJECT_STRUCT):
                {
                    IStructData *p1 = (IStructData*)(*it);
                    p1->clear();
                }
                break;
                case (E_OBJECT_ARRAY):
                {
                    IStructArraryBase *p1 = (IStructArraryBase*)(*it);
                    p1->clear();
                }
                break;
                default:
                break;
            }
        }

        // current level clear
        IStructUnknow::clear();
    }

    bool soncleared(void)
    {
        bool bSonCleared = true;
        vecArrayIter it;
        for(it = m_vecNodes.begin(); it != m_vecNodes.end(); it ++)
        {
           if(!(*it)->IsEmpty())
           {
               bSonCleared = false;
           }
        }
        return bSonCleared;
    }

    void Destroy()
    {
        vecArrayIter it;
        for(it = m_vecNodes.begin(); it != m_vecNodes.end(); it ++)
        {
            delete *it;
        }
        m_vecNodes.clear();
    }

    std::vector<T*> m_vecNodes;
    uint32_t m_iUsedNodes;
};


template <typename T>
struct TSerializeMentor
{
    TSerializeMentor(T &obj)
    : _data(obj)
    {
    }

public:
    std::string & serialize(void)
    {
        sSerialized.clear();

        IStructUnknow *p = (IStructUnknow*)&get();

        Json::Value root ;
        Json::FastWriter writer ;

        if(!p->IsEmpty())
        {
            p->serialize(root[p->getid()]);
            //sSerialized = root.toStyledString();
            sSerialized =  writer.write(root);
        }

        return sSerialized;
    }
    bool unserialize(std::string &str)
    {
        IStructUnknow *p = (IStructUnknow*)&get();
        Json::Reader reader;
        Json::Value  value;

        if(reader.parse(str, value, false))
        {
            Json::Value::Members member = value.getMemberNames();
            Json::Value::Members::iterator it = member.begin();
            for(it = member.begin(); it != member.end(); it++)
            {
               if((*it) == p->getid())
               {
                   return p->unserialize(value[p->getid()]);
               }
            }
        }

        return false;
    }

    T &get(void)
    {
        return _data;
    }
    std::string &string(void)
    {
        return sSerialized;
    }

private:
    T &_data;
    std::string sSerialized;
};


#define DELCARE_STRUCT_REGISTER(NAME, ID) \
    NAME() : IStructData("T" ID) \
    { \
        registerall(); \
    } \
    virtual void registerall(void)

#define ADD_REGISGER_LEAF_NODE(NOD, NAME) \
    add(NOD.setid(NAME))

#define ADD_REGISGER_LEAF_NODE_X(NOD, NAME, TIMES) \
    add(NOD.setid(NAME #TIMES))

#define ADD_REGISGER_STRUCT_NODE(NODE) \
    add(&NODE)

#define ADD_REGISGER_STRUCT_NODE_NAME(NODE, NAME) \
    add(NODE.setid(NAME))

#define ADD_REGISGER_STRUCT_NODE_X(NODE, TIMES) \
    add(NODE.setid(TOOLS::id_times(NODE.getid(),TIMES).c_str()))

#define ADD_REGISGER_ARRAY_NODE(NODE, NAME) \
    add(NODE.setid(NAME));

#define ADD_REGISGER_ARRAY_NODE_X(NODE, NAME, TIMES) \
    add(NODE.setid(NAME #TIMES));

#endif /* SERVICELIB_SERIALIZE_ISTRUCTDATAINFO_H_ */
