#ifndef MYMAPTEST_H_
#define MYMAPTEST_H_

#include <map>
#include <string>
typedef struct
{
    int iMediaType;
    //可以把某些avp 提到这里来

    std::map<int,int>   mapIntAttr;
    std::map<int,std::string>   mapStringAttr;

    int AsInt(int iAttrId)
    {
        std::map<int,int>::iterator it= mapIntAttr.find(iAttrId);
        if( it != mapIntAttr.end())
        {
            return it->second;
        }
        else
        {
            return -1;
        }
    }


    //这个程序，能够一直正常工作吗
    const char * AsString(int iAttrId)
    {
        std::map<int,std::string>::iterator it= mapStringAttr.find(iAttrId);
        if( it != mapStringAttr.end())
        {

            //如果 asstring赋值指针后，指针指向的map元素，已经被删除，那么指针将为空了，
            //如果这样的意思不符合你的意思。
            return ( (std::string) it->second).c_str() ;

            //拷贝一份，将其返回
        }
        else
        {
            return NULL;
        }
    }

} RARRuleInfo;


void TestMap();


#endif /* MYMAPTEST_H_ */
