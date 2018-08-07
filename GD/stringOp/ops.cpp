



#include <string>
#include <iostream>
using namespace std;


/*
 * ops:operatingString
 * jdr:完成对字符串的创建，
 * 		修改
 * 		删除
 * 		查找
 * 		比较
 * */

void tips();//提示
void opearation(string  & os,int opn);
void modify(string & aimStr);
void remove(string &aimStr);
void find(string & aimStr);
void compare(string &aimStr);
int main()
{
	string ys;//jdr:yourstring
	printf("请输入一个字符串\n");
	getline(cin,ys);
	cout<<"你输入的字符串为"<<ys<<endl;
	int selectN=1000;//jdr:select opearation
	while(1)
	{
		cout<<"请输入你选择操作的序列号："<<endl;
		tips();
		cin>>selectN;
		if(selectN !=0)
		{
			opearation(ys,selectN );
			cout<<"操作后字符串为："<<ys<<endl;
		}else
		{
			break;
		}
	}
}

void tips()
{
	printf("0，退出操作\n");
	printf("1:修改\n");
	printf("2:删除，后重新输入\n");
	printf("3:查找\n");
	printf("4:和字符串比较\n");
}

void opearation(string  & os,int opn)
{

	switch(opn)
	{
	case 1:
		modify(os);
		break;
	case 2:
		remove(os);
		break;
	case 3:
		find(os);
		break;
	case 4:
		compare(os);
		break;
	}
}



void modify(string  &aimStr)
{
	int 	location;
	int 	replaceFlag=0;
	string  replaceStr;
	int 	replaceStrLen;
	int     aimStrLen;
	int 	maxReplaceLen;
	aimStrLen=aimStr.size();

	cout<<"目标字符串长度为："<<aimStr.size()<<endl;

	cout<<"选择你要修改的位置：（》=1）"<<endl;
	cin>>location;
	location=location-1;//string的编号从0,开始的
	maxReplaceLen=aimStrLen-1-location;//jdr:从修改位置到源字符串末尾的长度

	cout<<"是否替代到字符串末尾:选择数字就可以(1,yes,0,no)"<<endl;
	cin>>replaceFlag;

	cout<<"输入你需要修改成为的内容"<<endl;
	cin>>replaceStr;
	replaceStrLen=replaceStr.size();


	if(replaceFlag==1)
	{
		string temp=aimStr.substr(0,location);
		temp.append(replaceStr);
		aimStr=temp;
	}
	else
	{
		if(maxReplaceLen>replaceStrLen )
		{
			aimStr.replace(location,replaceStrLen,replaceStr);
		}
		else
		{
			string temp=aimStr.substr(0,location);
			temp.append(replaceStr);
			aimStr=temp;
		}
	}

	cout<<"修改后的字符串为："<<aimStr<<endl;
	cout<<"修改结束。"<<endl;
}



void remove(string &aimStr)
{
	cout<<"输入你想重新输入的内容："<<endl;
	cin>>aimStr;
	cout<<"重新输入结束。"<<endl;
}

void find(string &aimStr)
{
	string findStr;
	int location;
	cout<<"输入你需要查找内容："<<endl;
	cin>>findStr;
	if(location=aimStr.find(findStr)>=0)
	{
		cout<<"你查找的内容出现在："<<location+1<<"!"<<endl;
	}
	else
	{
		cout<<"你查找的内容不在该字符串中!"<<endl;
	}
	cout<<"查找结束。"<<endl;
}

void compare(string &aimStr)
{
	string compareStr;
	int location;
	int leng;
	cout<<"输入你需要和源字符串比较的内容："<<endl;
	cin>>compareStr;
	cout<<"输入开始比较的位置："<<endl;
	cin>>location;
	cout<<"输入比较的长度："<<endl;
	cin>>leng;
	cout<<"比较的结果为："<<endl;

	if(aimStr.compare(location,leng,compareStr)==1)
	{
		cout<<"你比较的内容相同！"<<endl;
	}
	else
	{
		cout<<"你比较的内容好像不相同！"<<endl;
	}


	cout<<"比较结束。"<<endl;

}
