

/*
 *
 * 动态规划（ Dynamic Programming, DP）是最优化问题的一种解决方法，本质上状态空间的状态转移。
 * 所谓状态转移是指每个阶段的最优状态（对应于子问题的解）可以从之前的某一个或几个阶段的状态中得到，这个性质叫做最优子结构。
 * 而不管之前这个状态是如何得到的，这被称之为无后效性。

DP问题中最经典的莫过于01背包问题:

有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

用子问题定义状态：即f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值；则其状态转移方程：

f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
“将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），
那么就可以转化为一个只牵扯前i-1件物品的问题。如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”，
价值为f[i-1][v]；如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，
此时能获得的最大价值就是f[i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。



有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 *
 * */

#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {

    		vector<int> newnum;
    		newnum.push_back(1);
    		for(int i =0; i<nums.size(); i++)
    		{
    			newnum.push_back( nums[i] );
    		}
    		newnum.push_back(1);

    		int length= newnum.size();

           int coins[length][length] = {{0}};
           for(int i=0;i <length; i++)
           {
        	   for(int j=0;j <length; j++)
        	   {
        		   coins[i][j] =0;
        	   }
           }

           for(int i=2; i<newnum.size(); i++) {
        	   //控制 每次计算的开始和结束范围的大小

        	   //当 i =2;  经过下面一轮遍历
        	   //则所有的距离相差为2的数值都计算出来了
        	   //包括 val（0-2） 1-3 2-4,3-5这些相乘的结果，都变得已知
        	   //当 i=3 则计算 0-3,1-4,2-5，
        	   //其中0-3计算时， val(0-3)= max（ val( 0-2)+ 3， 0+ val(1-3) ）
               for(int j=0; j+i< newnum.size(); j++) {
                   for(int k=j+1; k<j+i; k++) {

                       coins[j][j+i] =
                    		   std::max(coins[j][j+i], coins[j][k] + coins[k][j+i] +
                    		   newnum[j] * newnum[k] * newnum[j+i]);

                       cout<< i <<","<<k <<","<< j<<","<<j+i<<","<<coins[j][j+i]<<endl;
                   }
               }
           }
           return coins[0][length-1];

    }
};

int main()
{

	vector<int> pre;
	pre.push_back(3);
	pre.push_back(1);
	pre.push_back(5);
	pre.push_back(8);

	cout<<"result"<<Solution().maxCoins(pre);


}
