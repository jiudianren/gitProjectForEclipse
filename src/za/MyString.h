/*
 * MyString.h
 *
 *  Created on: 2018年10月23日
 *      Author: Administrator
 */

#include <stdio.h>


class MyString
{
public:
    MyString(const char *str = NULL); // 普通构造函数
    MyString(const MyString &other); // 拷贝构造函数
    ~ MyString(void); // 析构函数
    MyString & operator=(const MyString &other); // 赋值函数
private:
    char *m_data; // 用于保存字符串
};
