/*
 * Department.h
 *
 *  Created on: 2017��10��19��
 *      Author: Administrator
 */

#ifndef SRC_GTESTCODE_DEPARTMENT_H_
#define SRC_GTESTCODE_DEPARTMENT_H_


class Department
{

public:
    Department();
   virtual  int GetDepNo();
   virtual ~Department(){};
private:
    int iDepNo;
};


#endif /* SRC_GTESTCODE_DEPARTMENT_H_ */
