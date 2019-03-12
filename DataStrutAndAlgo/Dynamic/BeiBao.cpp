/*
 * BeiBao.cpp
 *
 *  Created on: 2017年10月12日
 *      Author: Administrator
 */




#include <vector>
using namespace std;

/*
有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。

则其状态转移方程便是：f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}。

将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），
那么就可以转化为一个只牵扯前i-1件物品的问题。

如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”；
如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，
此时能获得的最大价值就是f [i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。
*/


#include<iostream>
using namespace std;

#define N 5 // N件宝贝
#define V 10 // C是背包的总capacity

void BeiBao()
{
	int value[N + 1]  = {0, 6, 3, 5, 4, 6}; // 钱啊
	int weight[N + 1] = {0, 2, 2, 6, 5, 4}; // 重量
	int f[N + 1][V + 1] = {0}; // f[i][j]表示在背包容量为j的情况下， 前i件宝贝的最大价值

	int i = 1;
	int j = 1;
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= V; j++)
		{
			// 递推关系式出炉
			if(j < weight[i])
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = std::max(f[i - 1][j] /*不放*/, f[i - 1][j - weight[i]] + value[i] /*放*/);
			}
		}
	}

	for(i = N; i >= 1; i--)
	{
		for(j = 1; j <= V; j++)
		{
			printf("%4d ", f[i][j]);
		}

		cout << endl;
	}

	return 0;
}


