

#include "TSerializeDataTest.h"


void TTestRuleReportInfo::registerall(void)
{
    ADD_REGISGER_LEAF_NODE(sPccCode, "cd");
    ADD_REGISGER_LEAF_NODE(iPccStatus, "st");
}

void TTestAcmCalcInfo::registerall(void)
{
    ADD_REGISGER_LEAF_NODE(iAcmId, "ai");
    ADD_REGISGER_LEAF_NODE(iResourceId, "ri");
    ADD_REGISGER_LEAF_NODE(sLastTime, "lt");
}

void TTestULIInfo::registerall(void)
{
    ADD_REGISGER_LEAF_NODE(sLAC, "lc");
    ADD_REGISGER_LEAF_NODE(sMCC, "mc");
    ADD_REGISGER_LEAF_NODE(sMNC, "mn");
}

void TTestGxRefData::registerall(void)
{
    ADD_REGISGER_LEAF_NODE(sRatType[0], "rat");
    ADD_REGISGER_LEAF_NODE_X(sRatType[1], "rat", 1);

    ADD_REGISGER_STRUCT_NODE(tULInfo[0]);
    ADD_REGISGER_STRUCT_NODE_X(tULInfo[1], 1);
    ADD_REGISGER_STRUCT_NODE_X(tULInfo[2], 2);

    ADD_REGISGER_ARRAY_NODE(tAcmCalcInfoArray[0], "ArAcmInfo");
    ADD_REGISGER_ARRAY_NODE_X(tAcmCalcInfoArray[1], "ArAcmInfo", 1);
    ADD_REGISGER_ARRAY_NODE(tRuleReportArray, "ArErrorReport");
}



