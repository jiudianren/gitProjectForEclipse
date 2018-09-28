

//https://mp.weixin.qq.com/s/0AgJmQNYAKzVOyigXiKQhA

/*
 * BlackRedTree.h
 *
 *  Created on: 2017年11月9日
 *      Author: Administrator
 */


//分阶段 求解问题  大事化小，小事化了


/*
 * 有一座高度是10级台阶的楼梯，从下往上走，每跨一步只能向上1级或者2级台阶。要求用程序来求出一共有多少种走法。



比如，每次走1级台阶，一共走10步，这是其中一种走法。我们可以简写成 1,1,1,1,1,1,1,1,1,1。

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
