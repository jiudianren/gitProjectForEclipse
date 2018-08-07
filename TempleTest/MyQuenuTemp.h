
#ifndef SRC_TEMPLETEST_MYQUENUTEMP_H_
#define SRC_TEMPLETEST_MYQUENUTEMP_H_


//http://blog.csdn.net/csfreebird/article/details/44888757
//http://blog.csdn.net/puttytree/article/details/6056205


/* ģ��Ҫ����������һ���ļ���  */

#include <iostream>
#include <string.h>

template <class Type> class MyQueue;
template <class Type> std::ostream & operator<<(std::ostream & os,const MyQueue<Type> & myqueue );

template <class Type>
class MyQueueItem
{
public:
	/* Ϊ�� ����һ����   MyqueueItem Ҳ��Ҫ ��  ������ ����Ϊ�Լ�����Ԫ  */
	friend  std::ostream & operator<< <Type> (std::ostream & os,const MyQueue<Type> & myqueue );
	MyQueueItem(const Type &t):item(t),next(0){};
	Type item;
	MyQueueItem * next;
};


template <class Type>
class MyQueue
{
public:
	friend  std::ostream & operator<< < Type > (std::ostream & os,const MyQueue<Type> & myqueue );

	MyQueue():head(0),tail(0){};
	MyQueue(const MyQueue & Q):head(0),tail(0){
		copy_elem(Q);
	};


	template <class It> MyQueue(It beg ,It end):head(0),tail(0) { copy_elem(beg,end);};

	template <class It> void assign(It beg, It end);
	MyQueue & operator= (const MyQueue & val)
	{
		if( this != &val )
		{
			this->destroy();
		}
		else
		{
			return *this;
		}

		this->copy_elem(val);
		return *this;
	};

	~ MyQueue(){ destroy();}
	Type front(){ return head->item;};
	const Type  & front() const {return head->item; };


	void pop()
	{
		MyQueueItem<Type> * p = head;
		head = head->next;
		delete p;
	};
	bool empty() const
	{
		return head == 0;
	};

	void push(const Type & val)
	{
		MyQueueItem<Type> * temp = new MyQueueItem<Type>(val);

		if( empty())
		{
			head = tail= temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	};


private:
	MyQueueItem<Type> *head;
	MyQueueItem<Type> * tail;
	void destroy()
	{
		while (! empty() )
		{
			pop();
		}
	};
	void copy_elem(const MyQueue & val)
	{
		for ( MyQueueItem<Type> * pt = val.head; pt; pt = pt->next)
		{
			push(pt->item);
		}
	}
	template<class It >	void copy_elem( It beg,It end);
};

//���ⶨ���Աģ��
template<class Type> template<class It>
void MyQueue<Type>::assign(It beg,It end)
{
	destroy();
	copy_elem(beg, end);
}

template<class Type> template<class It>
void MyQueue<Type>::copy_elem(It beg,It end)
{
	while( beg != end)
	{
		push( *beg);
		++beg;
	}
}

//�ػ����� ����ػ�ʵ��Ҳ��ͷ�ļ��У��Ͳ���Ҫ������
//template <> void MyQueue<const char *>::push(const char * const & val);
//�ػ���Ա����

template <>
void MyQueue<const char *>::push(const char * const & val)
{
    char * new_item = new char[strlen(val)+1];
    strncpy(new_item,val, strlen(val)+1);
    MyQueueItem<const char * > * pt =  new MyQueueItem<const char *>(new_item);

    if( empty())
    {
        head = tail = pt;

    }
    else
    {
        tail->next =pt;
        tail = pt;
    }
}

template <class Type > std::ostream &  operator<<(std::ostream & outstream, const MyQueue<Type> & myqueue)
{
	outstream <<"<";

	MyQueueItem<Type> *p;

	for( p = myqueue.head; p ; p = p->next)
	{
		outstream<< p->item <<" ";
	}
	outstream<< ">";
	return outstream;

}

#endif /* SRC_TEMPLETEST_MYQUENUTEMP_H_ */
