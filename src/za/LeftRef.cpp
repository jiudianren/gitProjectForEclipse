/*
 * LeftRef.cpp
 *
 *  Created on: 2017Äê5ÔÂ19ÈÕ
 *      Author: Lian
 */


#include "LeftRef.h"
#include <type_traits>
#include <utility>

int HasPot::n_c=0;
int HasPot::n_g=0;
int HasPot::n_yg=0;
int HasPot::n_d=0;
using namespace std;
HasPot getHasptr()
{
    return HasPot();
}
HasPot getHasptr2()
{
    HasPot h;
    return h;
}
void mainLeftRef()
{
    HasPot a= getHasptr();
    cout<<"================2"<<endl;
    HasPot b( getHasptr2());
    HasPot && c = getHasptr2();
    HasPot d;

    cout<<&d.d<<endl;
    std::move(d);
    cout<<&d.d<<endl;
    //	cout<<std::is_reference<string &&>::value;
}
