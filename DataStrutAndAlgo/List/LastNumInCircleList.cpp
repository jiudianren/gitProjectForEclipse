/*
 * LastNumInCircleList.cpp
 *
 *  Created on: 2018��11��5��
 *      Author: Administrator
 */




/*
 * todo:
 *
 * ԲȦ�����һ������
 *n ������ ���һ��Ȧ �� ÿ��ɾ�� ��m���� �����һ����ɾ��������
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
        context.erase(itbegin); //�����vector�Ļ�����һ���е�next��it�����Ѿ�ʧЧ
        itbegin= next;
    }

    return  (*itbegin);
}
