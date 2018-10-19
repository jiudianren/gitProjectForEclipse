/*
 * MyQuenu.cpp
 *
 *  Created on: 2018Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */




#include<iostream>
using namespace std;
#define MAXSIZE 10
class queue
{
public:
        queue();
        bool IsFull();
        bool IsEmpty();
        bool EnQueue(int);
        bool DeQueue(int&);
private:
        int buf[MAXSIZE];
        int rear;
        int front;
};
queue::queue()
{
        this->rear=0;
        this->front=0;
}
bool queue::IsEmpty()
{
        if(this->rear==this->front)
                return true;
        else
                return false;
}
bool queue::IsFull()
{
        if((this->rear+1)%MAXSIZE==this->front)
                return true;
        else
                return false;
}
bool queue::EnQueue(int data)
{
        if(IsFull())
                return false;
        this->buf[this->rear]=data;
        this->rear=(this->rear+1)%MAXSIZE;
        return true;
}
bool queue::DeQueue(int& data)
{
        if(IsEmpty())
                return false;
        data=this->buf[this->front];
        this->front=(this->front+1)%MAXSIZE;
}
int main()
{
        queue q;
        int i=0;
        while(i<20)
        {
                if(q.EnQueue(i))
                        cout<<"success "<<i<<endl;
                else
                        cout<<"fail "<<i<<endl;
                i++;
        }
        while(q.DeQueue(i))
                cout<<i<<" ";
        cout<<endl;
        return 0;
}
