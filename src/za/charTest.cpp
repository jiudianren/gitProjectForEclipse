/*
 * charTest.cpp
 *
 *  Created on: 2018��9��27��
 *      Author: Administrator
 */


#include <string>
#include <iostream>

using namespace std;

void TestChar()
{
    std::string sPayload {"1ce84f0001c2.3gppnetwork.org"};

 std::cout <<  "sing char:" <<sPayload.c_str();
 std::cout << "using char :" << (unsigned char *)sPayload.c_str();

}
