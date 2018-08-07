/*
 * cppstring.c
 *
 *  Created on: 2016年8月12日
 *      Author: Administrator
 */


#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s1("this is ");
	string s2(s1);
	string s3;
	string s4("a string ");
	string s5(5,'c');
	string inputs;
	getline(cin,inputs);
	cout<<"你的输入是（忽略开头空格，并结束于第一个空格）"<<inputs;
	cout<<"s1,"<<s1<<"s2,"<<s2<<"s3,"<<s3<<"s4,"<<s4<<"s5,"<<s5<<endl;

	cout<<"s1,empty："<<s1.empty()<<endl;
	cout<<"s1.size()："<<s1.size()<<endl;
	cout<<"s1+s2："<<s1+s2<<endl;
	cout<<"s1==s2："<<(s1==s2)<<endl;

	//second
	cout<<"s1[1].isalnum"<<isalnum(s1[1])<<endl;
//	cout<<":"<< <<endl;


	char * cp="HIYA";
	char  c_arry[]="it is a string to operaterWorkdl!!!!!!!";
	char no_null[]={'h','i'};
	string st(c_arry,7);
	cout<<"st:"<<st<<endl;
	string s(st ,0,1);
	cout<<"s:"<<s<<endl;
	st.insert(2,3,'f');
	cout<<"st:"<<st<<endl;
	s.assign(st);
	cout<<"s:"<<s<<endl;
	s.append("it is something to append");
	cout<<"s:"<<s<<endl;
	cout<<"s.find(it)"<<s.find("to")<<endl;
	

	string st1("aabbccddeeff");
	string st2("bbcc");
	cout<<"compare st1 : "<<st1<<"  st2:"<<st2<<endl;
	cout<<"st.compare(s2):"<<st1.compare(st2)<<endl;
	cout<<"st.compare(2,4,st2)"<<st1.compare(2,4,st2)<<endl;




//	return 0;
}
