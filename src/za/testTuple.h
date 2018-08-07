/*
 * testTuple.h
 *
 *  Created on: 2017Äê11ÔÂ6ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_ZA_TESTTUPLE_H_
#define SRC_ZA_TESTTUPLE_H_

#include <tuple>
#include <vector>
#include <iostream>

struct TBalInfo
{
    unsigned long iBalId;
    unsigned long iAcctResId;
    unsigned long iPreBalance;
    unsigned long iCharge;
    unsigned long iBalance;

    friend std::ostream & operator << (std::ostream &os, TBalInfo pVal)
    {
        os << "======TBalInfo ======" << std::endl;
        os <<"iBalId        "   <<  pVal.iBalId<<std::endl;
        os <<"iAcctResId    "  <<   pVal.iAcctResId<<std::endl;
        os <<"iPreBalance   "  <<   pVal.iPreBalance<<std::endl;
        os <<"iCharge       "  <<   pVal.iCharge<<std::endl;
        os <<"iBalance      "  <<   pVal.iBalance<<std::endl;
        return os;
    }

};


typedef  std::tuple<bool, std::vector<TBalInfo> & >  tuple_Param;

int mainTupel();
#endif /* SRC_ZA_TESTTUPLE_H_ */
