
#ifndef SERVICE_LIB_SERIALIZE_DATA_TEST_H_
#define SERVICE_LIB_SERIALIZE_DATA_TEST_H_

#include "../IStructDataInfo.h"


struct TTestRuleReportInfo : public IStructData
{
    // Items Here
    TAsciiString sPccCode;
    TUnsignedInt iPccStatus;
    // TODO Add New Elements

    DELCARE_STRUCT_REGISTER(TTestRuleReportInfo, "ErrRule");
};

typedef IStructArraryData<TTestRuleReportInfo>  TTestRuleReportInfoArray;

struct TTestAcmCalcInfo : public IStructData
{
    TUnsignedInt iAcmId;
    TUnsignedInt iResourceId;
    TAsciiString sLastTime;
    // TODO Add New Elements


    DELCARE_STRUCT_REGISTER(TTestAcmCalcInfo, "ACalInfo");
};

typedef IStructArraryData<TTestAcmCalcInfo>     TTestAcmCalcInfoArray;

struct TTestULIInfo : public IStructData
{
    TAsciiString sLAC;
    TAsciiString sMCC;
    TAsciiString sMNC;
    // TODO Add New Elements

    DELCARE_STRUCT_REGISTER(TTestULIInfo, "ULI");
};

struct TTestGxRefData : public IStructData
{
    TAsciiString              sRatType[2];
    TTestULIInfo              tULInfo[3];
    TTestAcmCalcInfoArray     tAcmCalcInfoArray[2];
    TTestRuleReportInfoArray  tRuleReportArray;

    DELCARE_STRUCT_REGISTER(TTestGxRefData, "RootGx");
};

typedef TSerializeMentor<TTestGxRefData>   TTestGxRefDataMgr;


#endif /* SERVICE_LIB_SERIALIZE_DATA_TEST_H_ */
