/*
 * ThroweExpected.cpp
 *
 *  Created on: 2018��11��1��
 *      Author: Administrator
 */




/*
 * �׳�һ�����ʽ������һ���쳣
 *
 *
 *����������Ӧ���׳������ܵ��쳣��stl�е��������������׳��쳣��

 ���ʽ�ľ�̬���ͣ��������쳣��������͡�

 *
 *
 c++��������throw�׳��쳣  ����������������
�𣺵���set_terminate()���趨����ֹ������Ȼ������ֻ�Ǳ�������ʵ�����ǵ���Ĭ�ϵ�unexpected()������
Ȼ�����Ĭ�ϵ�unexpected()������set_terminate()���趨����ֹ������������set_unexpected()������ unexpected,
����set_terminate()һ�����÷����������趨���µġ�unexpected()��֮�󣬾Ͳ����ٵ��� set_terminater���趨����ֹ�����ˡ�
���������������ֹ�˳�
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
