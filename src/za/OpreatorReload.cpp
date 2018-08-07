/*
 * OpreatorReload.cpp
 *
 *  Created on: 2017年6月30日
 *      Author: Administrator
 */




// 数组类的重载操作
#include<iostream>
#include<cstdlib>
using namespace std;
// 数组类
class Array
{
private:
    int *ptr;
    int size;
public:
    Array(int *, int);
    // 重载[]操作符，使得可以像数组一样访问这个类
    int &operator[] (int);
    void print() const;
};

// []操作符的重载实现。这个函数必须返回引用，且不能为const，因为可能会用作左值。例如arr[] = xxx;
int &Array::operator[](int index)
{
    if (index >= size)
    {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return ptr[index];
}

// 构造函数
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


// 第一个是  []取数组，第二个是重载操作符  分清楚
    arr[1][2]=7;
    arr[1].print();

    arr1[2] = 6;
    arr1.print();
//    arr1[8] = 6;
    cout<<"mainOpreat ==========="<<endl;
}
