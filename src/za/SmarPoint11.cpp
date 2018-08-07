
/*
 * c++ 11 ����ָ��
 *
 * */

#include <memory>
#include <iostream>
#include "SmarPoint11.h"

using namespace std;

void  TestUnAndShPtr()
{
	unique_ptr<int> up1(new int(11));  //�޷����Ƶ�unique_ptr
	/*unique_ptr  û��Ĭ�ϵĿ������캯�� ֻ���ƶ����캯�� */
//	unique_ptr<int> up2 = up1;         //����ͨ������

	cout << *up1 << endl;        //11

	/*�ƶ������up1���������ڣ���Ȼû�н�����������е���Դ�Ѿ���ת��*/
	unique_ptr<int> up3 = move(up1);  //����up3������Ψһ��unique_ptrֻ��ָ��

	cout << *up3 << endl;       //11
//	cout << *up1 << endl;       //����ʱ����
	up3.reset();                //��ʾ�ͷ��ڴ�
	up1.reset();                //���ᵼ������ʱ����

//	cout << *up3 << endl;       //����ʱ����

	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;   //OK

	cout << *sp1 << endl;       //22
	cout << *sp2 << endl;       //22

	sp1.reset();
	cout << *sp2 << endl;       //22
}


void Check(weak_ptr<int> & wp)
{
	shared_ptr<int> sp = wp.lock();  //ת��Ϊshare_ptr<int>
	if(sp != nullptr)
	{
		cout << "still" << *sp << endl;
	}
	else
	{
		cout << "pointer is invalid." << endl;
	}
}

void TestWptr()
{
	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;
	weak_ptr<int> wp = sp1;//ָ��share_ptr<int> ��ָ����

	cout << *sp1 << endl;  //22
	cout << *sp2 << endl;  //22
	Check(wp);             //still 22

	sp1.reset();
	cout << *sp2 << endl;  //22
	Check(wp);       //still 22

	sp2.reset();
	Check(wp);       //pointer is invalid.


}


void mainSMP11()
{
	cout<<"mainSMP11====================="<<endl;
	TestUnAndShPtr();
	TestWptr();
	cout<<"mainSMP11====================="<<endl;
}
