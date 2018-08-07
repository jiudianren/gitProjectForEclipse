/*
 * SmartPointer.h
 *
 *  Created on: 2017��4��8��
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
//ʹ�ü���������ָ��
class HasPtrCouter
{

private:

	//lpf �������ָ�룬���ﱾ��Ӧ�þ���һ��ָ�� ����������Ϊ ��ָ�룬�ǲ��Եģ�
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
		//�������ƹ��캯����ǰ����������󣬶�ָ����ͬһ��ָ�룬���Զ��ĸ�һ��ָ��ļ�������һ����һ����
		up->use++;
	};
	HasPtrCouter& operator=(HasPtrCouter & hpc)
	{
		//��ֵ���캯��Ҫ�鷳һ�£�����Ҫ�ѣ�����ļ�������һ��Ȼ���ж��Ƿ���Ҫ����������ٸ��ƶ���
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
 * 		��c++��׼���ṩ��ֻ��ָ�룬
 * 		����
 *
 * */


void mainSmartP();

#endif /* SMARTPOINTER_H_ */
