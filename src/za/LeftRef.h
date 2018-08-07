/*
 * LeftRef.h
 *
 *  Created on: 2017年5月19日
 *      Author: Lian
 */

#ifndef LEFTREF_H_
#define LEFTREF_H_



#include <string>
#include <iostream>
using namespace std;
class HasPot
{

public:

	HasPot():d(new int (0))
{
		cout <<"n_g"<<n_g++<<endl;
}

//	HasPot(const HasPot & temp):d(new int (*temp.d))
//	{
//		cout <<"n_c"<<n_c++<<endl;
//	}

	//移动构造函数
	/* 何时被调用
	 * 用到临时变量的时候，移动构造函数就会被调用*/
	HasPot(HasPot &&  h):d(h.d)
	{
		h.d=nullptr;
		cout <<"n_yg"<<n_yg++<<endl;
	}
	~ HasPot()
	{
		cout <<"n_d"<<n_d++<<endl;
		delete d;
	}
 static int n_g;
 static int n_c;
 static int n_yg;
 static int n_d;
	int * d;

};



void mainLeftRef();
#endif /* LEFTREF_H_ */
