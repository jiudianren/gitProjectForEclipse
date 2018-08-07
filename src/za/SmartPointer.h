/*
 * SmartPointer.h
 *
 *  Created on: 2017年4月8日
 *      Author: Lian
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <stddef.h>
class HasPtr
{

private:
	int * pMem;
	int iMem;
public:
	void setIMem(int temp){ iMem=temp; };
	void setPMem(int *temp){ pMem=temp; };
	int getIMem(){return iMem;};
	int * getPMem(){return pMem;};

};

class HasPtrCouter;
class U_Ptr
{
	friend class HasPtrCouter;
	int * p;
	int use;
	U_Ptr(int *p ):p(p),use(1){};
	~U_Ptr( )
	{
		delete p;
		p= NULL;
	};

};
//使用计数器管理指针
class HasPtrCouter
{

private:

	//lpf 针对智能指针，这里本来应该就是一个指针 ，所以声明为 非指针，是不对的，
//	U_Ptr up;
	U_Ptr*  up;

	int iMem;
public:
	void setIMem(int temp){ iMem=temp; };
	void setPMem(int *temp){ up->p=temp; };
	int getIMem(){return iMem;};
	int * getPMem(){return up->p;};
	int getCounter(){return up->use;};

	HasPtrCouter(int * p,int i):up(new U_Ptr(p)),iMem(i){};
	HasPtrCouter(const HasPtrCouter & hpc):up(hpc.up),iMem(hpc.iMem)
	{
		//这样复制构造函数，前后的两个对象，都指向了同一个指针，所以对哪个一个指针的计数器加一都是一样的
		up->use++;
	};
	HasPtrCouter& operator=(HasPtrCouter & hpc)
	{
		//赋值构造函数要麻烦一下，首先要把，自身的计数器减一，然后判断是否需要析构，最后再复制对象
		++hpc.up->use;
		up->use--;
		if(up->use==0)
		{
			delete up->p;
		}
		up=hpc.up;
		iMem=hpc.iMem;
		return *this;
	};
	~HasPtrCouter()
	{
		if(up->use==0)
		{
			up->~U_Ptr();
		}else
		{
			up->use--;
		}
	};
};

/*
 * test std::auto_ptr
 * 		std::shared_ptr
 *
 * 		等c++标准库提供的只能指针，
 * 		待做
 *
 * */


void mainSmartP();

#endif /* SMARTPOINTER_H_ */
