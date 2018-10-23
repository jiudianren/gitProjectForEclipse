/*
 * MyString.cpp
 *
 *  Created on: 2018��10��23��
 *      Author: Administrator
 */


#include <iostream>
#include "MyString.h"
#include <string.h>

/*
 * ���C++ ��дString �Ĺ��캯�����������캯�������������͸�ֵ����
 * */
MyString::MyString(const char *str)
{
  if (str==NULL)
  {
    m_data=new char[1]; //�Կ��ַ����Զ������Ž�����־'\0'�Ŀռ�
    if (m_data==NULL)
    {//�ڴ��Ƿ�����ɹ�
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
    {//�ڴ��Ƿ�����ɹ�
      std::cout<<"Erro"<<std::endl;
      exit(1);
    }
    strcpy(m_data,str);
  }
}

//�������캯��
MyString::MyString(const MyString &other)
{ //�������Ϊconst��
  int length=strlen(other.m_data);
  m_data=new char[length+1];
  if (m_data==NULL)
  {//�ڴ��Ƿ�����ɹ�
    std::cout<<"Erro "<<std::endl;
    exit(1);
  }
  strcpy(m_data,other.m_data);
}


//��ֵ����
MyString& MyString::operator =(const MyString &other)
{//�������Ϊconst��
  if (this == &other) //����Ը�ֵ
  { return *this; }

  delete [] m_data;//�ͷ�ԭ�����ڴ���Դ

  int length=strlen(other.m_data);
  m_data= new char[length+1];
  if (m_data==NULL)
  {//�ڴ��Ƿ�����ɹ�
      std::cout<<"Erro "<<std::endl;
    exit(1);
  }
  strcpy(m_data,other.m_data);

  return *this;//���ر����������
}

//��������
MyString::~MyString()
{
  delete [] m_data;
}
