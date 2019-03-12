#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include "base64.h"
using namespace std;
#define LENG_MAX 100000

#define SPACELINE      cout<< endl


void trim(string &s)
{
    int index = 0;
    if( !s.empty())
    {
        while( (index = s.find(' ',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }
}


void Bytes2HexString(const unsigned char* input, unsigned int length, string& output)
{
    output.reserve(length << 1);
    output.clear();
    char b[3];
    for (unsigned int i = 0; i < length; i++)
    {
        sprintf(b, "%02X", input[i]);
        output.append(1, b[0]);
        output.append(1, b[1]);
    }
}


bool HexStr2Bytes(string src, unsigned char * out ,int & length )
{
    char *strEnd;
    int m=0;
    if( length <   src.length()/2)
    {
        return false;
    }
    int  len = src.length()/2;
    for(int i= 0 ; i < len; i++)
    {
        m = i*2;
        string subs = src.substr(m,2);
        out[i] = strtoul(subs.c_str(),&strEnd,16);
    }

    length = len;
    return true;
}

bool CheckHexStr(const string &s)
{
    bool bRet= true;
    for( auto it = s.begin(); it != s.end(); it ++)
    {
        bool oneToNine =  ( (*it) >= '0'  && (*it) <=  '9') ;
        bool aTof =  (   (*it) >= 'a'  && (*it) <=  'f');
        bool rs = aTof || oneToNine;
        if( !rs )
        {
            bRet = false;
            break;
        }
    }
    return bRet;
}


int main()
{
	string command;
	cout<<"  Decode your string   ,pleast input   :1  "<<endl;
	cout<<"  Encode your string   ,pleast input   :2  "<<endl;
    cout<<"  ASCII to HEX string  ,pleast input   :3  "<<endl;
    cout<<"  HEX string to ASCII  ,pleast input   :4  "<<endl;
    cout<<"  Encode HEX string    ,pleast input   :5  "<<endl;
    cout<<"  Exist program input  ,pleast input   :6  "<<endl;
	cin.clear();

	while(getline(std::cin, command))
	{
	    if (command == "1")
	    {
	        cout<<"input the str to decode :"<<endl;
	        cout<<"======================"<<endl;

	        string src;
	        cin.clear();
	        getline(std::cin, src);
	        unsigned char dst[LENG_MAX];
	        int len= LENG_MAX;
	        base64_decode((unsigned char *)src.c_str(), src.length(),dst,&len);

	        dst[len]='\0';
	        cout<<" Decode result: "<<endl;
	        cout<<"======================"<<endl;
	        cout<<dst << endl;
	        SPACELINE;

	        cout<<" hex resut:"<<endl;
	        cout<<"======================"<<endl;
	        string sHexStr;
	        Bytes2HexString(dst,len , sHexStr);
	        cout<<sHexStr << endl;
	        SPACELINE;

	    }
	    else if (command == "2")
	    {
	        string src;
	        cout<< "input the str to encode :"<<endl;
	        cout<<"======================"<<endl;
	        cin.clear();
	        getline(std::cin, src);
	        unsigned char dst[LENG_MAX];
	        int len= LENG_MAX;
	        base64_encode((unsigned char *)src.c_str(),src.length(),dst,&len);
	        dst[len]='\0';
	        cout<<" Encode result: "<<endl;
	        cout<<"======================"<<endl;
	        cout<<dst<<endl;
	    }
	    //string to hex string ;
	    else if (command == "3")
	    {
	        string src;
	        cout<< "input the ascii str to Hex  :"<<endl;
	        cout<<"======================"<<endl;
	        cin.clear();
	        getline(std::cin, src);
            trim(src);
            //std::transform( src.begin(), src.end(),src.begin() , [](char c) {return tolower(c); });
            cout<< "the input str: " << src <<endl;
            int length = src.length();
            cout<< "hex string is " <<endl;
            for(int i =0 ; i < length ; i++)
            {
                printf("%02x", src[i]);
            }
            printf("\n");

	    }
	    //hex string to string;
        else if (command == "4")
        {
            string hexsrc;
            cout<< "input the hex str to ascii :"<<endl;
            cout<<"======================"<<endl;
            cin.clear();
            getline(std::cin, hexsrc);
            trim(hexsrc);//È¥µô¿Õ¸ñ
            std::transform( hexsrc.begin(), hexsrc.end(),hexsrc.begin() , [](char c) {return tolower(c); });

            if(!CheckHexStr(hexsrc))
            {
                cout<< "check char: 0-9,a-f :" << hexsrc <<endl;
                cout<< hexsrc <<endl;
            }
            else if(hexsrc.length()%2!=0)
            {
                cout<<"length of hexstring must be even number"<<endl;
            }
            else
            {
                cout<<"the hex str you input is :"<<endl;
                for(int i=1;i<=hexsrc.length();i=i+2)
                {
                    cout<<hexsrc[i-1]<<hexsrc[i];
                    if(i%16==0 && i%32!=0)
                        cout<<"  ";
                    else if (i%32 == 0 && i!=0)
                        cout<<endl;
                    else
                        cout<<" ";
                }
                cout<<endl;
                int length = hexsrc.length()/2;
                unsigned char dest[length];
                HexStr2Bytes(hexsrc, dest , length);
                cout<< "string is " <<dest;
                cout<<endl;
            }
        }
        else if (command == "5")
        {
            string src;
            cout<< "input the HEX str to encode  :"<<endl;
            cout<<"======================"<<endl;
            cin.clear();
            getline(std::cin, src);
            cout<< "your string is :"<<endl;
            cout<< src <<endl;

            trim(src);
            std::transform( src.begin(), src.end(),src.begin() , [](char c) {return tolower(c); });
            if(!CheckHexStr (src))
            {
                cout<< "check char:0-9,a-f,A-F:" << src <<endl;
                cout<< src <<endl;
            }
            else
            {
                int length = src.length()/2;
                unsigned char dest[length];
                HexStr2Bytes(src, dest , length);
                cout<< "Hex string is " <<endl;
                for(int i =0 ; i < length ; i++)
                {
                    printf("%02x", dest[i]);
                }
                printf("\n");

                unsigned char dst[LENG_MAX];
                int len= LENG_MAX;
                base64_encode( dest,length,dst,&len);
                dst[len]='\0';
                cout<<" Encode result: " << endl;
                cout<< dst << endl;
                SPACELINE;
            }

        }
        else if (command == "6")
        {
            cout<< "exit this program , bye!!!!"<<endl;
            exit(0);
        }
        else
        {
            cout<<"please review the tips above!"<<endl;
        }

	    cout<<"======================"<<endl;
	    cout<<"please input your action again: "<<endl;
	    cout<<"  Decode your string   ,pleast input   :1  "<<endl;
        cout<<"  Encode your string   ,pleast input   :2  "<<endl;
        cout<<"  ASCII to HEX string  ,pleast input   :3  "<<endl;
        cout<<"  HEX string to ASCII  ,pleast input   :4  "<<endl;
        cout<<"  Encode HEX string    ,pleast input   :5  "<<endl;
        cout<<"  Exist program input  ,pleast input   :6  "<<endl;
	    SPACELINE;
	}
	return 0;
}
