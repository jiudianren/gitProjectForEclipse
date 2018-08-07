/*
 * Department.h
 *
 *  Created on: 2017Äê10ÔÂ19ÈÕ
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
