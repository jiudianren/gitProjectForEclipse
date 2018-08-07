/*
 * const_cast_test.cpp
 *
 *  Created on: 2017年10月31日
 *      Author: Administrator
 */


/*
 *
 *
 *
 *如果我们不想修改const变量的值，那我们又为什么要去const呢？

原因是，我们可能调用了一个参数不是const的函数，而我们要传进去的实际参数确实const的，
但是我们知道这个函数是不会对参数做修改的。
于是我们就需要使用const_cast去除const限定，以便函数能够接受这个实际参数。
 *
 * const_cast使用：
（1）const_cast只能改变运算对象的底层const
（2）如果对象本身不是一个常量，使用强制类型转换获得写权限是合法的行为
    （下面的示例程序，便说明这种情况）
（3）如果对象是一个常量，再使用const_cast执行写操作就会产生未定义的后果
    （注：未定义行为 https://zh.wikipedia.org/wiki/%E6%9C%AA%E5%AE%9A%E4%B9%89%E8%A1%8C%E4%B8%BA）
（4）只有const_cast能改变表达式的常量属性
（5）const_cast只能改变常量属性，不能改变表达式的类型
 *
 *https://www.cnblogs.com/ider/archive/2011/07/22/cpp_cast_operator_part2.html
 *
 * */
#include <iostream>

using namespace std;

int mainConstCast()
{

long iTemp=0;
  std::cout<<(iTemp == 0 ? 0 : ( iTemp > 0 ? 1:-1)) <<std::endl;
iTemp=1;
std::cout<<(iTemp == 0 ? 0 : ( iTemp > 0 ? 1:-1)) <<std::endl;

iTemp=-1;
std::cout<<(iTemp == 0 ? 0 : ( iTemp > 0 ? 1:-1)) <<std::endl;


return 0;
}
