/*
 * TestTinyXml.cpp
 *
 *  Created on: 2018Äê5ÔÂ24ÈÕ
 *      Author: Administrator
 */




#include "tinyxml2.h"
#include <iostream>
#include <stdio.h>

#include "TestTinyXml.h"
using namespace tinyxml2;
using namespace std;



int main()
{
    TestPrint();
    TestWrit();

    return 0;
}

void TestPrint()
{
    XMLDocument doc;
    XMLError   errXml = doc.LoadFile( "./my.xml" );
    XMLPrinter printer;
    doc.Print( &printer);

    cout<<"ALL: "<< printer.CStr() <<endl;

    if (XML_SUCCESS == errXml)
    {
        XMLElement* elmtRoot = doc.RootElement();

        cout<<"root"<< elmtRoot->GetText() <<endl;
        cout<<"root"<< elmtRoot->GetLineNum()  <<endl;

        cout.flush();

        XMLElement * elmtHead = elmtRoot->FirstChildElement("head");
        if (elmtHead)
        {
            const char* pContent= elmtHead->GetText();
            cout<<"f head"<< pContent <<endl;
        }
        XMLElement *elmtAge = elmtHead->NextSiblingElement();
        if ( elmtAge )
        {
            const char* pContent= elmtAge->GetText();
            cout<<" NextSiblingElement"<< pContent <<endl;
        }
    }
    //print all
}


void TestWrit()
{
    FILE * fp = fopen("./new.xml","r+");
    XMLPrinter printer2( fp );
    printer2.OpenElement( "foo" );
    printer2.PushAttribute( "foo", "bar" );
    printer2.CloseElement();
}

