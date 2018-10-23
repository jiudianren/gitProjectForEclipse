/*
 * MyString.cpp
 *
 *  Created on: 2018年10月23日
 *      Author: Administrator
 */


#include <iostream>
#include "MyString.h"
#include <string.h>

/*
 * 详解C++ 编写String 的构造函数、拷贝构造函数、析构函数和赋值函数
 * */
MyString::MyString(const char *str)
{
  if (str==NULL)
  {
    m_data=new char[1]; //对空字符串自动申请存放结束标志'\0'的空间
    if (m_data==NULL)
    {//内存是否申请成功
     std::cout<<"Erro !"<<std::endl;
     exit(1);
    }
    m_data[0]='\0';
  }
  else
  {
    int length=strlen(str);
    m_data=new char[length+1];
    if (m_data==NULL)
    {//内存是否申请成功
      std::cout<<"Erro"<<std::endl;
      exit(1);
    }
    strcpy(m_data,str);
  }
}

//拷贝构造函数
MyString::MyString(const MyString &other)
{ //输入参数为const型
  int length=strlen(other.m_data);
  m_data=new char[length+1];
  if (m_data==NULL)
  {//内存是否申请成功
    std::cout<<"Erro "<<std::endl;
    exit(1);
  }
  strcpy(m_data,other.m_data);
}


//赋值函数
MyString& MyString::operator =(const MyString &other)
{//输入参数为const型
  if (this == &other) //检查自赋值
  { return *this; }

  delete [] m_data;//释放原来的内存资源

  int length=strlen(other.m_data);
  m_data= new char[length+1];
  if (m_data==NULL)
  {//内存是否申请成功
      std::cout<<"Erro "<<std::endl;
    exit(1);
  }
  strcpy(m_data,other.m_data);

  return *this;//返回本对象的引用
}

//析构函数
MyString::~MyString()
{
  delete [] m_data;
}
