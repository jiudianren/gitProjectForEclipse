/*
 * Mock_Deppartment.h
 *
 *  Created on: 2017��10��19��
 *      Author: Administrator
 */

#ifndef SRC_GTESTCODE_MOCK_DEPPARTMENT_H_
#define SRC_GTESTCODE_MOCK_DEPPARTMENT_H_
#include "gmock/gmock.h"
#include  "Department.h"
#include <string>

struct Mock_Department: public  Department
{
    MOCK_METHOD0(GetDepNo, int() );
};


#endif /* SRC_GTESTCODE_MOCK_DEPPARTMENT_H_ */

