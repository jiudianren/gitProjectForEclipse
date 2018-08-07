/*
 * Employee.h
 *
 *  Created on: 2017Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_GTESTCODE_EMPLOYEE_H_
#define SRC_GTESTCODE_EMPLOYEE_H_
#include <string>
#include "Department.h"

class  Employee
{
public:

    Employee();
    Employee(Department tDepartment);
    std::string  getAllInfo() ;
    virtual Department&  getDep();

    virtual ~ Employee(){};

private:
    std::string sName;
    Department tDep;
};


#endif /* SRC_GTESTCODE_EMPLOYEE_H_ */
