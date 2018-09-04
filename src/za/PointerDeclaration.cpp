/*
 * PointerDeclaration.cpp
 *
 *  Created on: 2018Äê8ÔÂ29ÈÕ
 *      Author: Administrator
 */


/*
 * https://en.cppreference.com/w/cpp/language/pointer#Pointers_to_data_members
 * */

#include <iostream>
struct Base {};
struct Derived : Base { int m; };

int mainPDDD()
{
    int Derived::* dp = &Derived::m;
    int Base::* bp = static_cast<int Base::*>(dp);

    Derived d;
    d.m = 7;
    std::cout << d.*bp << '\n'; // okay: prints 7

    Base b;
    std::cout << b.*bp << '\n'; // undefined behavior

    return 0;
}
