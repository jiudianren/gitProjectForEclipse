

#include "IStructDataInfo.h"
#include <string.h>
#include <stdlib.h>
#include <sstream>

namespace TOOLS
{
    std::string id_times(const char *p0, int iIdx)
    {
        std::ostringstream os;
        os << p0 << iIdx;
        return os.str();
    }

    std::string id_times(std::string p0, int iIdx)
    {
        std::ostringstream os;
        os << p0 << iIdx;
        return os.str();
    }
}

void IStructUnknow::adjust()
{
    switch(_object)
    {
        case (E_OBJECT_STRUCT):
        {
            IStructData *p1 = (IStructData*)this;
            if(!p1->soncleared())
            {
                return;
            }
            m_bEmpty = true;
            if(GetParent())
            {
                GetParent()->adjust();
            }
        }
        break;
        case (E_OBJECT_ARRAY):
        {
            IStructArraryBase *p1 = (IStructArraryBase*)this;
            if(!p1->soncleared())
            {
                return;
            }
            m_bEmpty = true;
            if(GetParent())
            {
                GetParent()->adjust();
            }
        }
        break;
        default:
        break;
    }
}

//
// id : variant name
// value: variant value object
//
bool IStructItemType::serialize(Json::Value &value)
{
    bool bRetFlag = true;

    if(IsEmpty())
    {
        return bRetFlag;
    }

    switch(type)
    {
        case (E_TYPE_SIGNEDCHAR):
        {
            TSignedChar *p = (TSignedChar*) this;
            value = p->get();
        }
        break;
        case (E_TYPE_UNSIGNEDCHAR):
        {
            TUnsignedChar *p = (TUnsignedChar*) this;
            value = p->get();
        }
        break;
        case (E_TYPE_SIGNEDINT):
        {
            TSignedInt *p = (TSignedInt*) this;
            value = p->get();
        }
        break;
        case (E_TYPE_UNSIGNEDINT):
        {
            TUnsignedInt *p = (TUnsignedInt*) this;
            value = p->get();
        }
        break;
        case (E_TYPE_SIGNEDINT64):
         {
             TSignedInt64 *p = (TSignedInt64*) this;
             value = (double)p->get();
         }
         break;
         case (E_TYPE_UNSIGNEDINT64):
         {
             TUnsignedInt64 *p = (TUnsignedInt64*) this;
             value = (double)p->get();
         }
         break;
        case (E_TYPE_AsciiString):
        {

        }
        break;
        case (E_TYPE_BinaryString):
        {

        }
        break;
        default:
        {
          bRetFlag = false;
        }
        break;
    }

    return bRetFlag;
}

//
// id : variant name
// value: variant value object
//
bool IStructItemType::unserialize(Json::Value &value)
{
    bool bRetFlag = true;

    switch(type)
    {
        case (E_TYPE_SIGNEDCHAR):
        {
            TSignedChar *p = (TSignedChar*) this;
            p->set((char)value.asInt());
        }
        break;
        case (E_TYPE_UNSIGNEDCHAR):
        {
            TUnsignedChar *p = (TUnsignedChar*) this;
            p->set((unsigned char)value.asInt());
        }
        break;
        case (E_TYPE_SIGNEDINT):
        {
            TSignedInt *p = (TSignedInt*) this;
            p->set((int)value.asInt());
        }
        break;
        case (E_TYPE_UNSIGNEDINT):
        {
            TUnsignedInt *p = (TUnsignedInt*) this;
            p->set((unsigned int)value.asUInt());
        }
        break;
        case (E_TYPE_SIGNEDINT64):
        {
            TSignedInt64 *p = (TSignedInt64*) this;
            p->set((int64_t)value.asInt());
        }
        break;
        case (E_TYPE_UNSIGNEDINT64):
        {
            TUnsignedInt64 *p = (TUnsignedInt64*) this;
            p->set((uint64_t)value.asUInt());
        }
        break;
        case (E_TYPE_AsciiString):
        {

        }
        break;
        case (E_TYPE_BinaryString):
        {
        }
        break;
        default:
        {
          bRetFlag = false;
        }
        break;
    }

    return bRetFlag;
}




//
// structure include  sub levels as below:
// 1: structure 2: array 3: leaf variant
bool IStructData::serialize(Json::Value &value)
{
    bool bRetFlag = true;

    iterIUnknow it;
    for(it = m_mapNodes.begin(); it != m_mapNodes.end(); it ++)
    {
        if(it->second->IsEmpty())
        {
            continue;
        }
        Json::Value &refSubValue = value[it->first.c_str()];
        switch(it->second->_object)
        {
            case (E_OBJECT_VARIANT):
            {
                IStructItemType *p1 = (IStructItemType*)it->second;
                p1->serialize(refSubValue);
            }
            break;
            case (E_OBJECT_STRUCT):
            {
                IStructData *p1 = (IStructData*)it->second;
                p1->serialize(refSubValue);
            }
            break;
            case (E_OBJECT_ARRAY):
            {
                IStructArraryBase *p1 = (IStructArraryBase*)it->second;
                p1->serialize(refSubValue);
            }
            break;
            default:
            {
              bRetFlag = false;
            }
            break;
        }
    }

    return bRetFlag;
}

bool IStructData::unserialize(Json::Value &value)
{
    bool bRetFlag = true;
    /*
     * "struct":
     *
     * {"val1":"8","substruct":{"val1":"9","val2":"10"},"array1":[{"val1":"10"}{"val1":"11"}]}
     */
    std::string valname ;
    Json::Value::Members member = value.getMemberNames();
    Json::Value::Members::iterator it ;

    for(it = member.begin(); it != member.end(); it ++)
    {
        valname = *it;
        Json::Value &refItValue = value[valname];
        Json::ValueType type = refItValue.type();
        iterIUnknow itStruct = m_mapNodes.find(valname);
        if(itStruct == m_mapNodes.end())
        {
            continue;
        }
        if(type == Json::nullValue)
        {
            continue;
        }
        switch(itStruct->second->_object)
        {
            case (E_OBJECT_VARIANT):
            {
                if(type == Json::stringValue ||
                    type == Json::uintValue ||
                    type == Json::realValue ||
                    type == Json::intValue ||
                    type == Json::booleanValue)
                {
                    IStructItemType *p1 = (IStructItemType*)itStruct->second;
                    p1->unserialize(refItValue);
                }
            }
            break;
            case (E_OBJECT_STRUCT):
            {
                if(type == Json::objectValue)
                {
                    IStructData *p1 = (IStructData*)itStruct->second;
                    p1->unserialize(refItValue);
                }
            }
            break;
            case (E_OBJECT_ARRAY):
            {
                if(type == Json::arrayValue)
                {
                    IStructArraryBase *p1 = (IStructArraryBase*)itStruct->second;
                    p1->unserialize(refItValue);
                }
            }
            break;
            default:
            {
                bRetFlag = false; // at least one unserialize failed!
            }
            break;
        }
    }

    return bRetFlag;
}

void IStructData::clear()
{
    if(IsEmpty())
    {
        return;
    }

    // sub level clear
    cursubclear();
}

void IStructData::adjust(IStructUnknow *pParent)
{
    if(pParent == NULL)
    {
        return;
    }
    switch(pParent->_object)
    {
        case (E_OBJECT_STRUCT):
        {
            IStructData *p1 = (IStructData*)pParent;
            if(!p1->soncleared())
            {
                return;
            }
            adjust(p1->GetParent());
        }
        break;
        case (E_OBJECT_ARRAY):
        {
            IStructArraryBase *p1 = (IStructArraryBase*)pParent;
            if(!p1->soncleared())
            {
                return;
            }
            adjust(p1->GetParent());
        }
        break;
        default:
        break;
    }
}

bool IStructData::soncleared(void)
{
    bool bSonCleared = true;
    for(iterIUnknow it = m_mapNodes.begin(); it != m_mapNodes.end(); it++)
    {
        if(!it->second->IsEmpty())
        {
            bSonCleared = false;
        }
    }
    return bSonCleared;
}

void IStructData::cursubclear()
{
    for(iterIUnknow it = m_mapNodes.begin(); it != m_mapNodes.end(); it++)
    {
        if(it->second->IsEmpty())
        {
            continue;
        }
        it->second->clear();
#if 0
        switch(it->second->_object)
        {
            case (E_OBJECT_VARIANT):
            {
                IStructItemType *p1 = (IStructItemType*)it->second;
                p1->clear();
            }
            break;
            case (E_OBJECT_STRUCT):
            {
                IStructData *p1 = (IStructData*)it->second;
                p1->clear();
            }
            break;
            case (E_OBJECT_ARRAY):
            {
                IStructArraryBase *p1 = (IStructArraryBase*)it->second;
                p1->clear();
            }
            break;
            default:
            break;
        }
#endif
    }

    // current level clear
    IStructUnknow::clear();
}
