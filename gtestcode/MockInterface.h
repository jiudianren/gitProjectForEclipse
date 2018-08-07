/*
 * MockInterface.h
 *
 *  Created on: 2017Äê10ÔÂ18ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_GTESTCODE_MOCKINTERFACE_H_
#define SRC_GTESTCODE_MOCKINTERFACE_H_

#include "gmock/gmock.h"
#include <string>
#include "SimpleInterface.h"


class MockTestInterface: public TestInterface {
public:
        MOCK_METHOD0(GetId, int());
};


#endif /* SRC_GTESTCODE_MOCKINTERFACE_H_ */
