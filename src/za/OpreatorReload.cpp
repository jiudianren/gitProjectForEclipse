/*
 * OpreatorReload.cpp
 *
 *  Created on: 2017��6��30��
 *      Author: Administrator
 */




// ����������ز���
#include<iostream>
#include<cstdlib>
using namespace std;
// ������
class Array
{
private:
    int *ptr;
    int size;
public:
    Array(int *, int);
    // ����[]��������ʹ�ÿ���������һ�����������
    int &operator[] (int);
    void print() const;
};

// []������������ʵ�֡�����������뷵�����ã��Ҳ���Ϊconst����Ϊ���ܻ�������ֵ������arr[] = xxx;
int &Array::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return ptr[index];
}

// ���캯��
Array::Array(int *p = NULL, int s = 0)
{
    size = s;
    ptr = NULL;
    if (s != 0)
    {
        ptr = new int[s];
        for (int i = 0; i < s; i++)
            ptr[i] = p[i];
    }
}

void Array::print() const
{
    for(int i = 0; i < size; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}



class Ptt
{
public:
    Ptt();
    Ptt(int ax, int ay);
   friend ostream & operator<<(ostream &output, const Ptt &thiz) ;
 ~Ptt() {}
private:
    int x;
    int y;

};

Ptt::Ptt():x(0),y(0){

};
Ptt::Ptt(int ax, int ay) {
    x = ax;
    y = ay;
};

ostream & operator<<(ostream &output, const Ptt &thiz) {
    cout << "ppt reload opreater << : (" << thiz.x << ", " << thiz.y << ")" << endl;
    return output;
}


void mainReloadOpr() {
    Ptt a( 3, 4 );
    cout << a;
}

void mainOpreat()
{

    cout<<"mainOpreat ==========="<<endl;
    int a[] = {1, 2, 4, 5};

    Array arr1(a, 4);
    Array arr[2]={ Array(a,4), Array(a,4)};


// ��һ����  []ȡ���飬�ڶ��������ز�����  �����
    arr[1][2]=7;
    arr[1].print();

    arr1[2] = 6;
    arr1.print();
//    arr1[8] = 6;
    cout<<"mainOpreat ==========="<<endl;
}
