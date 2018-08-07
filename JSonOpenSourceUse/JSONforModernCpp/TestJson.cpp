/*
 * TestJson.cpp
 *
 *  Created on: 2018年4月17日
 *      Author: Administrator
 */



#include "../JSonOpenSourceUse/TestJson.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include "../JSonOpenSourceUse/json.hpp"

using namespace std;
using json = nlohmann::json;

//json最重要的还是设计config文件
int main()
{

    json j2 = {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                    {"everything", 42}
            }},
            {"list", {1, 0, 2}},
            {"object", {
                    {"currency", "USD"},
                    {"value", 42.99}
            }}
    };

    std::cout<<"json2： "<< j2.dump() <<std::endl;

    std::ifstream i("file.json",std::ifstream::in);
    json j;
    i >> j;
    std::string s = j.dump();
    std::cout<<"json from file：";
    cout<<s<<std::endl;

    i.close();
}
