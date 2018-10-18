#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


void MyStack::push (const my_value_type & val)
{
    if( m_local == -1)
    {
        m_curSize = 2;
        m_head  = new int [m_curSize];
    }

    m_local++;
    if( m_local == m_curSize )
    {
        m_curSize =  m_curSize * 2;
        int * pre_head =  m_head;
        m_head  = new int [m_curSize];
        memcpy ( m_head , pre_head , m_local * sizeof(my_value_type) );
        delete [] pre_head;
    }
    m_head[m_local] = val;
}


void MyStack::push (my_value_type&&  val)
{
    if( m_local == -1  && m_curSize ==0)
    {
        m_curSize = 2;
        m_head  = new int [m_curSize];
    }

    m_local++;
    if( m_local == m_curSize )
    {
        m_curSize =  m_curSize * 2;
        int * pre_head =  m_head;
        m_head  = new int [m_curSize];
        memcpy ( m_head , pre_head , m_local * sizeof(my_value_type) );
        delete [] pre_head;
    }
    (m_head+ m_local) = val;
}


my_reference & MyStack::top()
{
    return  *(m_head+m_local ) ;
}

const_reference& MyStack::top() const
{
    return  *(m_head+m_local ) ;
}
void MyStack::pop ()
{
    if( m_local == -1)
    {
        return ;
    }
    m_local --;
}


void TestVoidVector()
{

    std::vector<int> myvec;
    std::cout<< "void vector<int> back :"  <<  myvec.back();
    std::cout<< "void vector<int> front :" <<  myvec.front();

    myvec.push_back(1);
    std::cout<< " push_bakc  1 .";
    std::cout<< " vector<int> back :"  <<  myvec.back();
    std::cout<< " vector<int> front :" <<  myvec.front();

    myvec.pop_back();
    std::cout<< " pop_back   .";
    std::cout<< " vector<int> back :"  <<  myvec.back();
    std::cout<< " vector<int> front :" <<  myvec.front();

    myvec.pop_back();
    std::cout<< " pop_back   .";
    std::cout<< " vector<int> back :"  <<  myvec.back();
    std::cout<< " vector<int> front :" <<  myvec.front();


}

void  TestMyStack()
{

    TestVoidVector();

    MyStack mystack;
    mystack.push( 1);
    mystack.push( 2);
    mystack.push( 3);
    mystack.push( 4);
    mystack.push( 5);

    int a = mystack.top();
    std::cout<< "top :" <<  a;

    const int b = mystack.top();
    std::cout<< "top :" <<  b;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );
    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );


    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( );

    int push = 1;
    mystack.push(1);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( );

    push = 2;
    mystack.push(push);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( );

    push = 3;
    mystack.push(push);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( );

    push = 4;
    mystack.push(push);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( );
}
