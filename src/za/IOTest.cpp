/*
 * IOTest.cpp
 *
 *  Created on: 2017Äê12ÔÂ28ÈÕ
 *      Author: Administrator
 */




#include <iostream>

using namespace std;

void CinTest()
{
    int i;
    //cin == true?
    if(cin)
    {
        cout<<"cin  opreat ()  in father class"<<std::endl;
    }
    while( !cin>>i )
    {
        cout<<"it is wrong "<<std::endl;
    }

}
void mainIOTest()
{
    CinTest();


}
