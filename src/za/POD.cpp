/*
 * POD.cpp
 *
 *  Created on: 2018��8��12��
 *      Author: Administrator
 */



/*
 *


ɶ��POD���ͣ�
PODȫ��Plain Old Data��ͨ�׵Ľ���һ�����ṹ��ͨ�������ƿ������ܱ��������ݲ��䣬��ô������һ��POD���͡�

ƽ���Ķ���
1.��ƽ���Ĺ��캯��
2.��ƽ���Ŀ������캯��
3.��ƽ�����ƶ����캯��
4.��ƽ���Ŀ�����ֵ�����
5.��ƽ�����ƶ���ֵ�����
6.��ƽ������������
7.���ܰ����麯��
8.���ܰ��������



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
