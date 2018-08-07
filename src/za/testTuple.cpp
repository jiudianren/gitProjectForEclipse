/*
 * TestTuple.cpp
 *
 *  Created on: 2017Äê11ÔÂ6ÈÕ
 *      Author: Administrator
 */




#include <tuple>
#include <vector>
#include <iostream>
#include "testTuple.h"

int mainTupel()
{


    std::cout<<"mainTupel =====================start "<<std::endl;

    TBalInfo balinfo1;
    balinfo1.iAcctResId=1;

    TBalInfo balinfo2;
    balinfo2.iAcctResId=2;

    std::vector<TBalInfo> vecBal;

    vecBal.push_back(balinfo1);
    vecBal.push_back(balinfo2);


    tuple_Param tuple1(true, vecBal);
    tuple_Param tuple2(false, vecBal);

    std::vector<tuple_Param> vec_tuple;

    vec_tuple.push_back(tuple1);
    vec_tuple.push_back(tuple2);

    for(auto it : vec_tuple)
    {
        std::cout<<"bool"<< std::get<0>(it)<<std::endl;
        std::vector<TBalInfo>  & aa = std::get<1>(it);
        for(auto innerit  : aa)
        {
            std::cout<<"iAcctResId "<< innerit.iAcctResId<<std::endl;
        }
    }


    std::cout<<"mainTupel =====================start "<<std::endl;

    return 1;
}



