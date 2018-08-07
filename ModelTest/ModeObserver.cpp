//============================================================================
// Name        : 观察者模式.cpp
// Author      : lian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<list>
#include "ModeObserver.h"
using namespace std;


void  mainTestObsMod() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	WeatherData weatherData;
	CurrentDisplay currentDisplay;
	float pressure=0;
	weatherData.regisgterObserver(currentDisplay);
	weatherData.setMeasurments(pressure);

}

