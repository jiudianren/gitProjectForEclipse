

#include <iostream>

#include "MyQuenuTemp.h"
#include "MyQuenu.h"
using namespace std;


void TestQueueTemp()
{

	MyQueue<int> myQInt;

	myQInt.push(5);
	myQInt.push(4);
	myQInt.push(3);
	myQInt.push(2);

	std::ostream & outos = std::cout;
	outos<< myQInt;
}
