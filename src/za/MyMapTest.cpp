/*
 * MyMapTest.cpp
 *
 *  Created on: 2017年4月24日
 *      Author: Administrator
 */



#include "MyMapTest.h"
#include   <map>
#include   <vector>
#include <string>
#include <iostream>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
static RARRuleInfo g_RARRuleInfo[2] ={0};

//string s(char *)
int InitRARRuleConfig(const char * sRarInfoDetail,int iIndex, int iType)
{

    std::string sInfoDetail(sRarInfoDetail);

    int iLength = sInfoDetail.length();
    int iPos = 0;
    std::string sSubDetail;
    bool bOver = false;
    while( iPos < iLength)
    {
        int iFlagPos = sInfoDetail.find("|", iPos);

        if(bOver == true)
        {
            break;
        }

        if (iFlagPos < 0 )
        {
            sSubDetail = sInfoDetail.substr(iPos, iLength - iPos);
            bOver = true;
        }
        else
        {
            sSubDetail=sInfoDetail.substr(iPos, iFlagPos - iPos);
        }

        //去除空格
        if( !sSubDetail.empty())
        {
            //去除 空格
            size_t iTemp = 0;
            while( (iTemp = sSubDetail.find(' ',iTemp)) !=std::string::npos)
            {
                sSubDetail.erase(iTemp,1);
            }
        }

        iPos = iFlagPos + 1 ;

        {
            int iInnerPos = sSubDetail.find(",", 0);
            std::string  sBeforEqual=sSubDetail.substr(0, iInnerPos);
            std::string sAfterEqual=sSubDetail.substr(iInnerPos+1, sSubDetail.length()-iInnerPos-1);


            //int型avp
            if(iType == 1)
            {
                printf("%d,%d \n",atoi(sBeforEqual.c_str()),atoi(sAfterEqual.c_str()));
                //                g_RARRuleInfo[iIndex].mapIntAttr.insert(
                //                        std::pair<int,int>( atoi(sBeforEqual.c_str()), atoi(sAfterEqual.c_str()))
                //                        );
                g_RARRuleInfo[iIndex].mapIntAttr[atoi(sBeforEqual.c_str())]=atoi(sAfterEqual.c_str());
            }
            else
            {
                //                g_RARRuleInfo[iIndex].mapStringAttr.insert(
                //                        std::pair<int,std::string>( atoi(sBeforEqual.c_str()), sAfterEqual)
                //                        );
                g_RARRuleInfo[iIndex].mapStringAttr[atoi(sBeforEqual.c_str())]=sAfterEqual;
            }
            cout<<sBeforEqual<<":"<<sAfterEqual<<endl;
        }
    }

    return 0;
}



void TestMap()
{

    const char * intTemp="10,1|11,111|12,222|13,333";
    const char * stTemp="10,ss|11,  bb|12, cc |13,dd  ";
    InitRARRuleConfig(intTemp,0,1);
    InitRARRuleConfig(stTemp,0,2);


    cout<<"===="<<endl;
    cout<<g_RARRuleInfo[0].AsInt(10)<<endl;
    cout<<g_RARRuleInfo[0].AsInt(14)<<endl;

    cout<<"====test"<<endl;
    cout<<g_RARRuleInfo[0].AsString(10)<<endl;
    g_RARRuleInfo[0].mapStringAttr[10]="test";
    cout<<g_RARRuleInfo[0].AsString(10)<<endl;
    map<int,string>::iterator key = g_RARRuleInfo[0].mapStringAttr.find(10);
    if(key != g_RARRuleInfo[0].mapStringAttr.end())
    {
        g_RARRuleInfo[0].mapStringAttr.erase(key);
    }
    cout<<g_RARRuleInfo[0].AsString(10)<<endl;
    cout<<"====test end"<<endl;


    if(g_RARRuleInfo[0].AsString(14) != NULL)
    {
        cout<<g_RARRuleInfo[0].AsString(14)<<endl;
    }

    cout<<"AA"<<endl;
    cout<<"===="<<endl;
    for (int i = 0; i < 2; i++)
    {
        map<int,int>::iterator iter;
        for(iter = g_RARRuleInfo[i].mapIntAttr.begin(); iter !=g_RARRuleInfo[i].mapIntAttr.end(); ++iter)
        {
            cout<<iter->first<<":"<<iter->second<<endl;
        }
        map<int,string>::iterator iter2;
        for(iter2 = g_RARRuleInfo[i].mapStringAttr.begin(); iter2 !=g_RARRuleInfo[i].mapStringAttr.end(); ++iter2)
        {
            cout<<iter2->first<<":"<<iter2->second<<endl;
            printf("%d %s \n",iter2->first,(iter2->second).c_str());
        }
    }

}



//去除 空格
//int index = 0;
//if( !suntemp.empty())
//{
//    while( (index = suntemp.find(' ',index)) != string::npos)
//    {
//        suntemp.erase(index,1);
//    }
//}

//        if( !suntemp.empty() )
//        {
//            suntemp.erase(0,suntemp.find_first_not_of(" "));
//            suntemp.erase(suntemp.find_last_not_of(" ") + 1);
//        }

//int index = 0;
//if( !suntemp.empty())
//{
//    while( (index = suntemp.find(' ',index)) != string::npos)
//    {
//        suntemp.erase(index,1);
//    }
//}
//
////        if( !suntemp.empty() )
////        {
////            suntemp.erase(0,suntemp.find_first_not_of(" "));
////            suntemp.erase(suntemp.find_last_not_of(" ") + 1);
////        }
//std::vector<std::string> split(const  std::string& s, const std::string& delim)
//{
//    std::vector<std::string> elems;
//    size_t pos = 0;
//    size_t len = s.length();
//    size_t delim_len = delim.length();
//    if (delim_len == 0) return elems;
//    while (pos < len)
//    {
//        int find_pos = s.find(delim, pos);
//        if (find_pos < 0)
//        {
//            elems.push_back(s.substr(pos, len - pos));
//            break;
//        }
//        elems.push_back(s.substr(pos, find_pos - pos));
//        pos = find_pos + delim_len;
//    }
//    return elems;
//                                }

