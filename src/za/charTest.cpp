/*
 * charTest.cpp
 *
 *  Created on: 2018Äê9ÔÂ27ÈÕ
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
