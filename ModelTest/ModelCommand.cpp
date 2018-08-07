/*
 * ModelCommand.cpp
 *
 *  Created on: 2017Äê7ÔÂ9ÈÕ
 *      Author: Lian
 */



#include "ModelCommand.h"


void mainModelComm()
{
	Barbecuer ba;
	BMuttonComm bmu( &ba);
	BWingComm  bwin(&ba);
	Waiter waiter;


	waiter.SetOrder( &bmu);
	waiter.SetOrder(&bwin);
	waiter.Notify();

	waiter.SetOrder( &bmu);
	waiter.SetOrder(&bwin);
	waiter.Notify();
}
