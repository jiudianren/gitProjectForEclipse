/*
 * IntegralType.cpp
 *
 *  Created on: 2018��10��25��
 *      Author: Administrator
 */



/*
 *                             ��С�ߴ�
 * bool     δ����
 * char     8
 * short   16
 * int     16
 * long    32
 * long long   64
 * float       6λ��Ч����
 * double       10λ��Ч����
 * long double  10λ��Ч����
 *
 * ����float��double��˵���������� Խ��������ֻ���� ���ȵ�����
 *
 * */

#include <string>
#include <vector>


/*
 * ����cmp��Ӳ�̵���������һ���ĸ��ʣ��ڸ���������̨������ѡ��һ���������ظ�����
 *
 * */


/*���� Ӳ������ ��vol����������ѡ�񣬲�Ӧѡ��int ���ʾ��Χ̫С
 * Ӧѡ�� double*/
struct Cmp
{
std::string sIp;
double   lVol;
};


/* ���� ��Σ�Ӧ����const���� ��
 * ��֤ GetIp�����޸� ���
 * �ڶ��㣬���������϶࣬������� Ӧ��ʹ�� &
 * */
std::string GetIp( std::vector<Cmp> cmps)
{
    std::string sRet;
    return sRet;
}


/*�Ż�*/
std::string GetIp(const std::vector<Cmp> & cmps)
{
	std::string sRet;
	return sRet;

}
