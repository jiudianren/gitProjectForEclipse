/*
 * Test_Employee.cpp
 *
 *  Created on: 2017年10月19日
 *      Author: Administrator
 */

#include  "gmock/gmock.h"

#include "Mock_Employee.h"
#include "Mock_Department.h"

using ::testing::Return; // 值返回
using ::testing::ReturnRef;

class TEST_Employee : public  Mock_Employee
{
public:
    std::string getAllInfo()
    {
        return  Employee::getAllInfo();
    }
};


TEST(TEST_Employee, getAllInfo__001)
{
    TEST_Employee tEmp;
    Mock_Department tDep;
    int iDepartNO =101;
    EXPECT_CALL(tEmp, getDep()).Times(1).WillOnce( ReturnRef(tDep) );
    EXPECT_CALL(tDep, GetDepNo()).Times(1).WillOnce( Return(iDepartNO) );
    EXPECT_EQ(tEmp.getAllInfo(), std::string("getAllInfo100Employee1"));
}


