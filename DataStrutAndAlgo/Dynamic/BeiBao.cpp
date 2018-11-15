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

将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），那么就可以转化为一个只牵扯前i-1件物品的问题。如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”；如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，
此时能获得的最大价值就是f [i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。


*/


void BeiBao()
{

    int m = 120;
    int n = 5;
    std::vector<int> w = { 0, 40, 50, 70, 40, 20 };
    std::vector<int> v = { 0, 10, 25, 40, 20, 10 };
    vector< vector<int> > vec(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ( w[i] > j)
                vec[i][j] = vec[i - 1][j];
            else
            {
                int tmp1 = v[i] + vec[i - 1][j - w[i]];
                int tmp2 = vec[i - 1][j];
                vec[i][j] = tmp1 > tmp2 ? tmp1 : tmp2;
            }
        }
    }
}


