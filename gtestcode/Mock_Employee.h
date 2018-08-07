/*
 * Mock_Employee.h
 *
 *  Created on: 2017Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */


#ifndef SRC_GTESTCODE_MOCK_EMPLOYEE_H_
#define SRC_GTESTCODE_MOCK_EMPLOYEE_H_

#include <string>
#include "gmock/gmock.h"
#include "Employee.h"
#include "Mock_Department.h"
struct Mock_Employee: public  Employee
{
    MOCK_METHOD0(getAllInfo, std::string (void) );
    MOCK_METHOD0(getDep, Department & (void) );
};


#endif /* SRC_GTESTCODE_MOCK_EMPLOYEE_H_ */


