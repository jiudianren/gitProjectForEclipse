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

    //ע�� �������� �ͷ�������
    //�������д��    void push ( value_type& val); �ͻ������� �ᱻ���ӵ�
    void push (const my_value_type& val);
    void push (my_value_type &&  val);
    void pop ();
    my_reference & top();
    //ΪʲôҪ�����������
    /*
    Ϊ�� �� const ���εĶ����ܹ�����ʹ��  top������

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

���stackͷ�ļ������const T& top(void) const;����ע�͵����������ܸ��ұ������
��const�Ķ���ֻ�ܵ���const���������ǻ�����ʶ������
     * */
    const int & top() const;
};

void TestVoidVector();
void  TestMyStack();
#endif /* DATASTRUTANDALGO_STACK_MYSTACK_H_ */
