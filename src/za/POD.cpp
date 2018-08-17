/*
 * POD.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: Administrator
 */



/*
 *


啥是POD类型？
POD全称Plain Old Data。通俗的讲，一个类或结构体通过二进制拷贝后还能保持其数据不变，那么它就是一个POD类型。

平凡的定义
1.有平凡的构造函数
2.有平凡的拷贝构造函数
3.有平凡的移动构造函数
4.有平凡的拷贝赋值运算符
5.有平凡的移动赋值运算符
6.有平凡的析构函数
7.不能包含虚函数
8.不能包含虚基类



 *
 * */

#include <iostream>
#include <type_traits>

struct A {
    int m;
};

struct B {
    int m1;
private:
    int m2;
};

struct C {
    virtual void foo();
};

void mainPod()
{
    std::cout << std::boolalpha;
    std::cout << std::is_pod<A>::value << '\n';
    std::cout << std::is_pod<B>::value << '\n';
    std::cout << std::is_pod<C>::value << '\n';
}
