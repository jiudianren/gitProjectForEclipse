
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
using namespace std;
class Observer
{
public :
	virtual void update(float pressure){};
	virtual ~Observer(){};
};
class Subject
{

public:
	virtual void regisgterObserver(Observer & o){};
	virtual void removeObserver(Observer o){};
	virtual void notifyObserver(){};
	virtual ~Subject(){};
};


class CurrentDisplay :public  Observer
{
private:
    float pressure;
    Subject subject;
public:
    CurrentDisplay() { pressure = 0;};
//    CurrentDisplay(Subject  & subject):subject(subject){
//    	this->subject.regisgterObserver(*this);
//    };
	void update(float pressure)
	{
		this->pressure=pressure;
		cout<<"pressure is now"<<pressure<<endl;
	};
};
class WeatherData :public Subject
{
private:
	list<Observer> lObserver;
    float pressure;

public:
    void regisgterObserver(Observer & o)
    {
    	lObserver.push_back(o);
    };
	void removeObserver(Observer o)
	{
		cout<<"it is remove"<<endl;

	};
	void notifyObserver()
	{
		list<Observer>::iterator observerIterator;
		for(observerIterator=lObserver.begin();observerIterator!=lObserver.end();++observerIterator)
		{
			(*observerIterator).update(this->pressure);
			cout<<"update"<<endl;
		}
	}

	void measurementsChanged()
	{
		notifyObserver();
	};

	void setMeasurments(float pressure)
	{
		this->pressure=pressure;
		measurementsChanged();
	}
};



void mainTestStatMod();
