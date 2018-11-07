/*
 * QueueBy2Stack.h
 *
 *  Created on: 2018Äê11ÔÂ7ÈÕ
 *      Author: lian.pengfei
 */

#ifndef DATASTRUTANDALGO_QUEUE_QUEUEBY2STACK_H_
#define DATASTRUTANDALGO_QUEUE_QUEUEBY2STACK_H_

#include <stack>
#include  <assert.h>
#include  <iostream>

using namespace std;

template<typename T>  class QueueBy2Stack
{
public:

    void push(const T& data)
    {
        s1.push(data);
    }
    void pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "The queue is empty";
        }
        if (!s2.empty())
        {
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    T& Front()
    {
        assert(!s1.empty() || !s2.empty());
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    T& Back()
    {
        assert(!s1.empty() || !s2.empty());
        if (s1.empty() )
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    size_t size()
    {
        return s1.size() + s2.size();
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
private:
    stack<T> s1;
    stack<T> s2;
};



#endif /* DATASTRUTANDALGO_QUEUE_QUEUEBY2STACK_H_ */
