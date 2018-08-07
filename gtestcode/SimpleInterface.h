/*
 * MockSimple.h
 *
 *  Created on: 2017Äê10ÔÂ18ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_GTESTCODE_SIMPLEINTERFACE_H_
#define SRC_GTESTCODE_SIMPLEINTERFACE_H_


class TestInterface
{
public:
    virtual ~TestInterface(){}
public:
    virtual int GetId()=0;
};


#endif /* SRC_GTESTCODE_SIMPLEINTERFACE_H_ */
