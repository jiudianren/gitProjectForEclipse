

#include "TSerializeDataTest.h"
#include <iostream>

void fillvalue_static(TTestGxRefData &obj)
{
    obj.sRatType[0] = "Rat0";
    obj.sRatType[1] = "Rat1";

    obj.tULInfo[0].sLAC.set("0AC");
    obj.tULInfo[0].sMCC.set("VMCC");
    obj.tULInfo[0].sMNC.set("VMNC");

    obj.tULInfo[1].sLAC.set("K8A");
    obj.tULInfo[1].sMCC.set("K9B");

    obj.tULInfo[2].sLAC.set("KfFFFF");

    TTestAcmCalcInfo *pNew1 = obj.tAcmCalcInfoArray[0].NewNode();
    pNew1->iAcmId = 88;
    pNew1->iResourceId = 89;
    pNew1->sLastTime = "999";

    TTestAcmCalcInfo *pNew2 = obj.tAcmCalcInfoArray[1].NewNode();
    pNew2->iAcmId = 188;
    pNew2->iResourceId = 189;
    pNew2->sLastTime = "1999";

    TTestRuleReportInfo *pNew3 = obj.tRuleReportArray.NewNode();
    pNew3->sPccCode = "pcc1";
    pNew3->iPccStatus = 0;
}

void test_gx_serialize(std::string &retstring, TTestGxRefData &obj, bool bFill = true)
{
    if(bFill)
    {
        fillvalue_static(obj);
    }

    TTestGxRefDataMgr tRefDataMgr(obj);
    std::string sOut = tRefDataMgr.serialize();

    std::cout << "test serialize value:" << sOut;

    retstring = sOut;
}

void test_gx_unserialize(std::string &str, TTestGxRefData &obj)
{
    TTestGxRefDataMgr tRefDataMgr(obj);
    tRefDataMgr.unserialize(str);
}

int main()
{
    TTestGxRefData serialize_obj, unserialize_obj;

    serialize_obj.clear();
    unserialize_obj.clear();

    std::string serilize_str, unserialize_str;

    test_gx_serialize(serilize_str, serialize_obj);

    test_gx_unserialize(serilize_str, unserialize_obj);

#if 0
    unserialize_obj.tULInfo2.sLAC.clear();
    unserialize_obj.tAcmCalcInfo.clear();
    unserialize_obj.tRuleReportArray.clear();
    unserialize_obj.tULInfo1.clear();
#endif

    test_gx_serialize(unserialize_str, unserialize_obj, false);


    return 0;
}
