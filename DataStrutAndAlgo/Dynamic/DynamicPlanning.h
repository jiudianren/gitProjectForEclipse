

//https://mp.weixin.qq.com/s/0AgJmQNYAKzVOyigXiKQhA

/*
 * BlackRedTree.h
 *
 *  Created on: 2017��11��9��
 *      Author: Administrator
 */


//�ֽ׶� �������  ���»�С��С�»���


/*
 * ��һ���߶���10��̨�׵�¥�ݣ����������ߣ�ÿ��һ��ֻ������1������2��̨�ס�Ҫ���ó��������һ���ж������߷���



���磬ÿ����1��̨�ף�һ����10������������һ���߷������ǿ��Լ�д�� 1,1,1,1,1,1,1,1,1,1��

F(1) =1;
F(2)= 2;
F(N)= F(n-1)+F(n-2)

 * */

//https://www.cnblogs.com/sdjl/articles/1274312.html
#ifndef DATASTRUTANDALGO_DYNA_H_
#define DATASTRUTANDALGO_DYNA_H_

#include <map>
using namespace std;
int GetClimbWays(int n);
int GetClimbWays2(int n, std::map<int ,int >  & alreadMap  );
void mainDynmaicPlan();

#endif /* DATASTRUTANDALGO_BLACKREDTREE_H_ */
