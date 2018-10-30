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

    ~MyStack()
    {
        if( m_head != NULL)
        {
            delete [] m_head;
        }
    }

    //注意 参数类型 和返回类型
    //如果随手写成    void push ( value_type& val); 就会有问题 会被鄙视的
    void push (const my_value_type& val);
    void push (my_value_type &&  val);
    void pop ();
    my_reference & top();
    //为什么要定义这个函数
    /*
    为了 将 const 修饰的对象能够正常使用  top函数；

     void output(const stack<int>& s)
{
    cout << s.top() << endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    output(s);
    return 0;
}

你把stack头文件里面的const T& top(void) const;函数注释掉看看，你能给我编译过？
对const的对象只能调用const函数，这是基本常识！！！
     * */
    const int & top() const;
};

void TestVoidVector();
void  TestMyStack();
#endif /* DATASTRUTANDALGO_STACK_MYSTACK_H_ */
