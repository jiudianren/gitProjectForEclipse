/*
 * CppFile.cpp
 *
 *  Created on: 2018��5��24��
 *      Author: Administrator
 */


#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int main ()
{
    ifstream pF( "/proc/1/cpuset");
    if ( pF)
    {
        string sContaner;
        getline(pF,sContaner );
        cout<<sContaner <<endl;
        std::size_t iPos=  sContaner.find_last_of("/");
        if( iPos  != std::string::npos)
            cout<<sContaner.substr( iPos+1);
    }

}
