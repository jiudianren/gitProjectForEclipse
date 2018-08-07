
/*
 * c++ 11 智能指针
 *
 * */

#include <memory>
#include <iostream>
#include "SmarPoint11.h"

using namespace std;

void  TestUnAndShPtr()
{
	unique_ptr<int> up1(new int(11));  //无法复制的unique_ptr
	/*unique_ptr  没有默认的拷贝构造函数 只有移动构造函数 */
//	unique_ptr<int> up2 = up1;         //不能通过编译

	cout << *up1 << endl;        //11

	/*移动构造后，up1的声明周期，虽然没有结束，但其持有的资源已经被转移*/
	unique_ptr<int> up3 = move(up1);  //现在up3是数据唯一的unique_ptr只能指针

	cout << *up3 << endl;       //11
//	cout << *up1 << endl;       //运行时错误
	up3.reset();                //显示释放内存
	up1.reset();                //不会导致运行时错误

//	cout << *up3 << endl;       //运行时错误

	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;   //OK

	cout << *sp1 << endl;       //22
	cout << *sp2 << endl;       //22

	sp1.reset();
	cout << *sp2 << endl;       //22
}


void Check(weak_ptr<int> & wp)
{
	shared_ptr<int> sp = wp.lock();  //转换为share_ptr<int>
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
	weak_ptr<int> wp = sp1;//指向share_ptr<int> 所指对象

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
