/*
 * ThroweExpected.cpp
 *
 *  Created on: 2018年11月1日
 *      Author: Administrator
 */




/*
 * 抛出一个表达式，引发一个异常
 *
 *
 *析构函数不应该抛出自身不能的异常，stl中的类析构函数不抛出异常。

 表达式的静态类型，决定了异常对象的类型。

 *
 *
 c++代码中用throw抛出异常  如果不补货会崩溃吗
答：调用set_terminate()中设定的终止函数。然而，这只是表面现象，实际上是调用默认的unexpected()函数，
然而这个默认的unexpected()调用了set_terminate()中设定的终止函数。可以用set_unexpected()来设置 unexpected,
就像set_terminate()一样的用法，但是在设定了新的“unexpected()”之后，就不会再调用 set_terminater中设定的终止函数了。
不做处理，程序出终止退出
 * */

#include <exception>
#include <iostream>

#include <stdio.h>
#include <cstdio>



void f1(int i)
{

    if( i < 0)
    throw std::logic_error(" chu shu is zero");
    std::cout  << "10/" <<i  << " = " << ( 10/i);
}
void f2()
{
    f1(-45);
}
void f3()
{
    f2();
}
void f4()
{
    f3();
}
int mainExecption()
{
    try{
        f4();
    }
    catch (std::logic_error   & e )
    {
        std::cout <<  "erro reason is : " << e.what();
    }
    return 0;
}
