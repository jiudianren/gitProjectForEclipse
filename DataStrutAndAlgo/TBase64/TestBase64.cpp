/*
 * TestBase64.cpp
 *
 *  Created on: 2018Äê5ÔÂ16ÈÕ
 *      Author: Administrator
 */


/*
 * https://blog.csdn.net/langeldep/article/details/6265609
 *
 *
 *http://www1.tc711.com/tool/BASE64.htm
 * */

#include "TBase64.h"

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    char number[]= "15077889999";
    cout<<"0001  "<<number << "  "<< (int)strlen(number)<<endl;
    char * ss =TBase64::Encode( number  );
    cout<<"0002  "<< ss <<endl;
    std::string mystr(ss);
    auto re =TBase64::Decode( mystr.c_str()  );
    cout<<"0003  "<<  re  << "  "<<std::endl;



    char number2[]= "a1234567890bbb";
    cout<<"0001  "<<number2 << "  "<< (int)strlen(number2)<<endl;
    char * ss2 =TBase64::Encode( number2  );
    cout<<"0002  "<< ss2 <<endl;
    std::string str( ss2 );
     auto re2 =TBase64::Decode( str.c_str()  );
     cout<<"0003  "<<  re2  << "  "<<std::endl;



}
