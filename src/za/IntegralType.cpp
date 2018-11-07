/*
 * IntegralType.cpp
 *
 *  Created on: 2018年10月25日
 *      Author: Administrator
 */



/*
 *                             最小尺寸
 * bool     未定义
 * char     8
 * short   16
 * int     16
 * long    32
 * long long   64
 * float       6位有效数字
 * double       10位有效数组
 * long double  10位有效数组
 *
 * 对于float和double来说，并不存在 越界的情况，只存在 精度的问题
 *
 * */

#include <string>
#include <vector>


/*
 * 按照cmp的硬盘的容量，和一定的概率，在给定的上万台主机中选择一个，并返回该主机
 *
 * */


/*考虑 硬盘容量 ，vol的数据类型选择，不应选择int 其标示范围太小
 * 应选择 double*/
struct Cmp
{
std::string sIp;
double   lVol;
};


/* 函数 入参，应该用const修饰 ，
 * 保证 GetIp不会修改 入参
 * 第二点，主机数量较多，函数入参 应该使用 &
 * */
std::string GetIp( std::vector<Cmp> cmps)
{
    std::string sRet;
    return sRet;
}


/*优化*/
std::string GetIp(const std::vector<Cmp> & cmps)
{
	std::string sRet;
	return sRet;

}
