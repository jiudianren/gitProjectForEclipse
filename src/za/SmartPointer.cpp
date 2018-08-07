/*
 * SmartPointer.cpp
 *
 *  Created on: 2017��4��8��
 *      Author: Lian
 */



#include "SmartPointer.h"
#include <iostream>

using namespace std;
void mainSmartP()
{
	int  * outP= new int(1);
	HasPtr hp;
	int outI	=2;
	hp.setIMem(outI);
	//ָ���ֵ����
	hp.setPMem(outP);
	HasPtr hp2(hp);

	cout<<"hp.getIMEM: "<<hp.getIMem()<<endl;
	cout<<"hp.getPMEM: "<<*hp.getPMem()<<endl;
	cout<<"hp2.getIMEM: "<<hp2.getIMem()<<endl;
	cout<<"hp2.getPMEM: "<<*hp2.getPMem()<<endl;

	hp.setIMem(3);
	int outTemp=4;
	//����Ӱ�����������
	outP=&outTemp;
	cout<<"outp: "<< *outP<<endl;

	cout<<"hp.getIMEM: "<<hp.getIMem()<<endl;
	cout<<"hp.getPMEM: "<<*hp.getPMem()<<endl;
	cout<<"hp2.getIMEM: "<<hp2.getIMem()<<endl;
	cout<<"hp2.getPMEM: "<<*hp2.getPMem()<<endl;

	//������һƬ���ڴ棬���Բ����� delete
//	delete outP;


	cout<<"================"<<endl;
	int tempi=1;
	int tempp=2;
	HasPtrCouter hpc1(&tempp,tempi);
	cout<<"hpc1.getCounter "<<hpc1.getCounter()<<endl;


	HasPtrCouter hpc2(hpc1);
	cout<<"hpc1.getCounter "<<hpc1.getCounter()<<endl;

	HasPtrCouter hpc3(&tempp,tempi);
	cout<<"hpc3.getCounter "<<hpc3.getCounter()<<endl;

	{
		HasPtrCouter hpc4(hpc1);
		cout<<"hpc1.getCounter "<<hpc1.getCounter()<<endl;
	}

	cout<<"hpc1.getCounter "<<hpc1.getCounter()<<endl;


	hpc2=hpc3;
	cout<<"hpc1.getCounter "<<hpc1.getCounter()<<endl;
	cout<<"hpc3.getCounter "<<hpc3.getCounter()<<endl;

}
