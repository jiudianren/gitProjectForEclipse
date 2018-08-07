#ifndef MYMAPTEST_H_
#define MYMAPTEST_H_

#include <map>
#include <string>
typedef struct
{
    int iMediaType;
    //���԰�ĳЩavp �ᵽ������

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


    //��������ܹ�һֱ����������
    const char * AsString(int iAttrId)
    {
        std::map<int,std::string>::iterator it= mapStringAttr.find(iAttrId);
        if( it != mapStringAttr.end())
        {

            //��� asstring��ֵָ���ָ��ָ���mapԪ�أ��Ѿ���ɾ������ôָ�뽫Ϊ���ˣ�
            //�����������˼�����������˼��
            return ( (std::string) it->second).c_str() ;

            //����һ�ݣ����䷵��
        }
        else
        {
            return NULL;
        }
    }

} RARRuleInfo;


void TestMap();


#endif /* MYMAPTEST_H_ */
