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
    *(m_head+ m_local) = val;
}


my_reference & MyStack::top()
{
    return  *(m_head+m_local ) ;
}

const int & MyStack::top() const
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
    //vector 如果为空的话，访问back和 frone 会 core 。
//    std::cout<< "void vector<int> back :"  <<  myvec.back();
//    std::cout<< "void vector<int> front :" <<  myvec.front();

    myvec.push_back(1);
    std::cout<< " push_bakc  1 .";
    std::cout<< " vector<int> back :"  <<  myvec.back() << std::endl;
    std::cout<< " vector<int> front :" <<  myvec.front() << std::endl;


    myvec.pop_back();
    //pop以后， 再访问back 和 front会有问题，在使用back和 front前必须要确保  有效性
    std::cout<< " pop_back   ."  << std::endl ;
    std::cout<< " vector empty or not: "  << myvec.empty() << std::endl;
    std::cout<< " vector<int> back :"  <<  myvec.back() << std::endl;
    std::cout<< " vector<int> front :" <<  myvec.front() << std::endl;

    myvec.pop_back();
    std::cout<< " vector empty or not: "  << myvec.empty() << std::endl;
    std::cout<< " pop_back   ." << std::endl ;
    std::cout<< " vector<int> back :"  <<  myvec.back() << std::endl;
    std::cout<< " vector<int> front :" <<  myvec.front() << std::endl;


}

void  TestMyStack()
{

    TestVoidVector();
    std::cout<< " ================ TestMyStack ." << std::endl;
    MyStack mystack;
    mystack.push( 1);
    mystack.push( 2);
    mystack.push( 3);
    mystack.push( 4);
    mystack.push( 5);

    int a = mystack.top();
    std::cout<< "top :" <<  a << std::endl;

    const int b = mystack.top();
    std::cout<< "top :" <<  b << std::endl ;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;
    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( )<< std::endl ;


    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;

    mystack.pop();
    std::cout<< "after pop, top  :" <<  mystack.top( ) << std::endl;

    int push = 1;
    mystack.push(1);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( ) << std::endl;

    push = 2;
    mystack.push(push);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( ) << std::endl;

    push = 3;
    mystack.push(push) ;
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( ) << std::endl;

    push = 4;
    mystack.push(push);
    std::cout<< "after push:"  <<push << ",top is " <<  mystack.top( ) << std::endl;

    std::cout<< " ================ TestMyStack ." << std::endl;
}
