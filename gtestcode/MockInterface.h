/*
 * MockInterface.h
 *
 *  Created on: 2017��10��18��
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
