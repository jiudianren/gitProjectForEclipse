/*
 * const_cast_test.cpp
 *
 *  Created on: 2017��10��31��
 *      Author: Administrator
 */


/*
 *
 *
 *
 *������ǲ����޸�const������ֵ����������ΪʲôҪȥconst�أ�

ԭ���ǣ����ǿ��ܵ�����һ����������const�ĺ�����������Ҫ����ȥ��ʵ�ʲ���ȷʵconst�ģ�
��������֪����������ǲ���Բ������޸ĵġ�
�������Ǿ���Ҫʹ��const_castȥ��const�޶����Ա㺯���ܹ��������ʵ�ʲ�����
 *
 * const_castʹ�ã�
��1��const_castֻ�ܸı��������ĵײ�const
��2�������������һ��������ʹ��ǿ������ת�����дȨ���ǺϷ�����Ϊ
    �������ʾ�����򣬱�˵�����������
��3�����������һ����������ʹ��const_castִ��д�����ͻ����δ����ĺ��
    ��ע��δ������Ϊ https://zh.wikipedia.org/wiki/%E6%9C%AA%E5%AE%9A%E4%B9%89%E8%A1%8C%E4%B8%BA��
��4��ֻ��const_cast�ܸı���ʽ�ĳ�������
��5��const_castֻ�ܸı䳣�����ԣ����ܸı���ʽ������
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
