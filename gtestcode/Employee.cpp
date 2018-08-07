/*
 * Employee.cpp
 *
 *  Created on: 2017Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */


#include "Employee.h"
#include <iostream>

Employee::Employee():sName("Employee1"),tDep()
{

}

Employee::Employee(Department tDepartment ):sName("Employee1"),tDep(tDepartment)
{

}


std::string Employee:: getAllInfo()
{
    std::string rt="getAllInfo";
    Department & t = getDep();
    int iDepNO=   t.GetDepNo();
    std::cout<<iDepNO<<std::endl;

    rt += "100";
    rt += sName;
    return rt;
};


Department&  Employee:: getDep()
{
    return tDep;
}

