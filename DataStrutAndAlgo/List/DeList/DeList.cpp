/*
 * DeList.cpp
 *
 *  Created on: 2018��10��21��
 *      Author: Administrator
 */


#include<iostream>
using std::cout;
using std::endl;

template<typename T> class Node{  //�ڵ�Ķ���
public:
	Node(T t):item(t),previous(0),next(0){}
	T item;
	Node* previous;
	Node* next;
};

template<typename T> class TwoWayLinkedList{  //˫������Ķ���
public:
	TwoWayLinkedList():length(0),head(0),tail(0){};
	~TwoWayLinkedList();
	int getLength(){return length;}
	void add(T t);
	T get(int i);
	void insert(int i,T t);
	void del(int i);
	void display();
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
};

template <typename T> void TwoWayLinkedList<T>::add(T t){  //������Ľ�β�����Ԫ��
	if(head==0){  //�������Ϊ��
		head=new Node<T>(t);
		tail=head;
	}
	else {
		Node<T>* q=new Node<T>(t);  //�½�һ���ڵ㴢����Ԫ��
		tail->next=q;  //�ӵ���ǰ����Ľ�β
		q->previous=tail;  //����ǰ��Ϊ��ǰ�Ľ�β
		tail=tail->next;  //�ѽ�β�Ƶ������Ԫ��
	}
	length++;
}

template<typename T> T TwoWayLinkedList<T>::get(int i){  //�����±�Ϊi��Ԫ��
	if(i>=length||i<0) return 0;  //���û������±귵��0
	int j=0;
	Node<T>* p=head;
	while(j<i){  //�ҵ��±���ָ�Ľڵ�
		p=p->next;
		j++;
	}
	T item=(p->T);
	return item;
}

template<typename T> void TwoWayLinkedList<T>::insert(int i, T t){  //���±�Ϊi������һ����Ԫ��
	if(i<=0){  //����±�С�ڵ���0��������ǰ��
		Node<T>* p=new Node<T>(t);
		p->next=head;
		head->previous=p;
		head=p;
		length++;
	}
	else if(i>=length) add(t);  //����±��������±���������
	else{
		Node<T>* n=new Node<T>(t);
		int j=0;
		Node<T>* t=head;
		while(j<i-1){  //�ҵ�����λ��ǰ���Ԫ��
			t=t->next;
			j++;
		}
		n->next=t->next;
		n->previous=t;
		(t->next)->previous=n;
		t->next=n;
		length++;
	}
}

template<typename T> void TwoWayLinkedList<T>::del(int i){  //ɾ���±�Ϊi��Ԫ��
	if(i<0||i>=length) return; // ���û������±�ֱ���˳�
	else{
		if(length==0) return;  //�������Ϊ���Ƴ�
		else if(length==1){  //���ֻ��һ��Ԫ��
			delete head;
			head=0;
			tail=0;
		}
		else if(i==0){ // ���Ҫɾ����һ��Ԫ��
			Node<T>* t=head;
			head=head->next;  //�ѵ�һ��������һ��
			head->previous=0;
			delete t;
		}
		else if(i==length-1){  //���Ҫɾ�����һ��Ԫ��
			Node<T>* t=tail;
			tail=tail->previous;  //�����һ����ǰ�ƶ�һλ
			tail->next=0;
			delete t;
		}
		else{
			Node<T>* t=head;
			while(i>1){  //�ҵ�Ҫɾ��Ԫ�ص�ǰһ��
				t=t->next;
				i--;
			}
			Node<T>* p=t->next;
			t->next=p->next;
			(p->next)->previous=t;
			delete p;
		}
		length--;
	}
}

template<typename T> TwoWayLinkedList<T>::~TwoWayLinkedList(){  //�𹹺���
	Node<T>* t=head;
	Node<T>* p;
	while(t!=0){  //����ÿһ���ڵ�Ŀռ�
		p=t;
		t=t->next;
		delete p;
	}
}

template<typename T> void TwoWayLinkedList<T>::display(){  //��˳����ʾȫ��Ԫ��
	T item;
	int i=0;
	while(i<length){
		item=this->get(i);
		i++;
		cout<<item<<" ";
	}
	cout<<endl;
}
