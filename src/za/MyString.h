/*
 * MyString.h
 *
 *  Created on: 2018��10��23��
 *      Author: Administrator
 */

#include <stdio.h>


class MyString
{
public:
    MyString(const char *str = NULL); // ��ͨ���캯��
    MyString(const MyString &other); // �������캯��
    ~ MyString(void); // ��������
    MyString & operator=(const MyString &other); // ��ֵ����
private:
    char *m_data; // ���ڱ����ַ���
};
