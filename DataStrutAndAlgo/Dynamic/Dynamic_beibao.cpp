

#include "Dynamic_beibao.h"

#include <iostream>
#include <fstream>
using namespace std;
/*
 * https://www.cnblogs.com/sdjl/articles/1274312.html
 * */

/*
 * 这就是动态规划，
 * 具有“最优子结构”、“子问题重叠”、“边界”和“子问题独立”，
 * 当你发现你正在思考的问题具备这四个性质的话，
 * 那么恭喜你，你基本上已经找到了动态规划的方法
 *
 *       下面提供金矿问题的程序源代码帮助读者理解，并提供测试数据给大家练习。
       输入文件名为“beibao.in”，因为这个问题实际上就是背包问题，所以测试数据文件名就保留原名吧。
       输入文件第一行有两个数，第一个是国王可用用来开采金矿的总人数，第二个是总共发现的金矿数。
       输入文件的第2至n+1行每行有两个数，第i行的两个数分别表示第i-1个金矿需要的人数和可以得到的金子数。
       输出文件仅一个整数，表示能够得到的最大金子数。

       输入样例：

       100 5
       77 92
       22 22
       29 87
       50 46
       99 90

       输出样例：
       133
  */


const int max_n = 100;//程序支持的最多金矿数
const int max_people = 10000;//程序支持的最多人数


int n;//金矿数
int peopleTotal;//可以用于挖金子的人数
int peopleNeed[max_n];//每座金矿需要的人数
int gold[max_n];//每座金矿能够挖出来的金子数
int maxGold[max_people][max_n];//maxGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知

//初始化数据
void init()
{
    ifstream inputFile("beibao.in");
    inputFile>>peopleTotal>>n;
    for(int i=0; i<n; i++)
        inputFile>>peopleNeed[i]>>gold[i];

    inputFile.close();

    for(int i=0; i<=peopleTotal; i++)
        for(int j=0; j<n; j++)
            maxGold[i][j] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]

}

//获得在仅有people个人和前mineNum个金矿时能够得到的最大金子数，注意“前多少个”也是从0开始编号的
int GetMaxGold(int people, int mineNum)
{

    cout<<"GetMaxGold start "<< "People : "<< people <<" minNum: "<< mineNum <<std::endl;
    //申明返回的最大金子数
    int retMaxGold;

    //如果这个问题曾经计算过  [对应动态规划中的“做备忘录”]
    if(maxGold[people][mineNum] != -1)
    {
        //获得保存起来的值
        retMaxGold = maxGold[people][mineNum];
    }
    else if(mineNum == 0)//如果仅有一个金矿时 [对应动态规划中的“边界”]
    {
        //当给出的人数足够开采这座金矿
        if(people >= peopleNeed[mineNum])
        {
            //得到的最大值就是这座金矿的金子数
            retMaxGold = gold[mineNum];
        }
        else//否则这唯一的一座金矿也不能开采
        {
            //得到的最大值为0个金子
            retMaxGold = 0;
        }
    }
    else if(people >= peopleNeed[mineNum])//如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]
    {
        //考虑开采与不开采两种情况，取最大值
        retMaxGold = max(
                          GetMaxGold(people - peopleNeed[mineNum],mineNum -1) + gold[mineNum],
                          GetMaxGold(people,mineNum - 1)
                         );
    }
    else//否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]
    {
        //仅考虑不开采的情况
        retMaxGold  = GetMaxGold(people,mineNum - 1);
    }

    //做备忘录
    maxGold[people][mineNum] = retMaxGold;

    cout<<"GetMaxGold end "<< "People : "<< people <<" minNum: "<< mineNum <<"retMaxGold: "<<retMaxGold <<std::endl;
    return retMaxGold;
}

int mainBeiBao()
{
    //初始化数据
    cout<<"mainBeiBao =============start "<<std::endl;
    init();
    //输出给定peopleTotal个人和n个金矿能够获得的最大金子数，再次提醒编号从0开始，所以最后一个金矿编号为n-1
    cout<<GetMaxGold(peopleTotal,n-1)<<std::endl;
    cout<<"mainBeiBao =============end"<<std::endl;
    return 0;
}
