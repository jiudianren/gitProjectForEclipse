#ifndef DATASTRUTANDALGO_STACK_MYSTACK_H_
#define DATASTRUTANDALGO_STACK_MYSTACK_H_

#include <vector>
#define my_value_type int
#define my_reference int
//#define const_reference  (const int)


class MyStack
{
public:
    int m_local;
    int m_curSize;
    int * m_head;
    MyStack()
    {
        m_curSize = 0;
        m_local =-1;
        m_head = NULL;
    }

    //注意 参数类型 和返回类型
    //如果随手写成    void push ( value_type& val); 就会有问题 会被鄙视的
    void push (const my_value_type& val);
    void push (my_value_type&&  val);
    void pop ();
    my_reference & top();
    const int & top() const;
};

void TestVoidVector();
void  TestMyStack();
#endif /* DATASTRUTANDALGO_STACK_MYSTACK_H_ */
