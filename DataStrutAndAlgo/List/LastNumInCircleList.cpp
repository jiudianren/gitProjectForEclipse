/*
 * LastNumInCircleList.cpp
 *
 *  Created on: 2018年11月5日
 *      Author: Administrator
 */




/*
 * todo:
 *
 * 圆圈中最后一个数字
 *n 个数组 组成一个圈 ， 每次删除 第m个， 求最后一个被删除的数字
 * */

#include <assert.h>
#include <vector>
#include <list>

int GetLast(const int n , const int m)
{

    assert( n>=1);
    assert( m>=1);

    std::list<int> context;
    for(int i = 0; i < n; i++)
    {
        context.push_back(i);
    }

    auto itbegin = context.begin();
    while( context.size() > 1)
    {
        for(int j = 0; j < m; j++)
        {
            itbegin++;
            if( itbegin == context.end())
            {
                   itbegin= context.begin();
            }
        }

        auto next = itbegin++;
        if( next == context.end())
        {
            next= context.begin();
        }

        itbegin--;
        context.erase(itbegin); //如果是vector的话，下一步中的next的it可能已经失效
        itbegin= next;
    }

    return  (*itbegin);
}
