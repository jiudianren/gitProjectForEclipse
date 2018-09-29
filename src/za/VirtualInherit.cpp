/*
 * VirtualTest2.cpp
 *
 *  Created on: 2017Äê6ÔÂ12ÈÕ
 *      Author: Administrator
 */


#include <string>
#include <iostream>

#include "VirtualInherit.h"
using namespace std;



void mainVirtual2 ()
{
	cout<<"mainVirtual2 ===================star "<<endl;
	TTPoint tp;
	tp.FunGx();
	tp.FunSy();

	tp.IIGx::FunGx();

	IIGx * iigx= &tp;
	iigx->IIGx::FunGx();

	cout<<"==================="<<endl;
	TTGx * pGx =& tp;
	pGx->FunGx();
	cout<<"mainVirtual2 ===================end "<<endl;
}
