/*
 * ModelCommand.cpp
 *
 *  Created on: 2017��7��9��
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
