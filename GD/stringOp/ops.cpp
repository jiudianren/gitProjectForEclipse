



#include <string>
#include <iostream>
using namespace std;


/*
 * ops:operatingString
 * jdr:��ɶ��ַ����Ĵ�����
 * 		�޸�
 * 		ɾ��
 * 		����
 * 		�Ƚ�
 * */

void tips();//��ʾ
void opearation(string  & os,int opn);
void modify(string & aimStr);
void remove(string &aimStr);
void find(string & aimStr);
void compare(string &aimStr);
int main()
{
	string ys;//jdr:yourstring
	printf("������һ���ַ���\n");
	getline(cin,ys);
	cout<<"��������ַ���Ϊ"<<ys<<endl;
	int selectN=1000;//jdr:select opearation
	while(1)
	{
		cout<<"��������ѡ����������кţ�"<<endl;
		tips();
		cin>>selectN;
		if(selectN !=0)
		{
			opearation(ys,selectN );
			cout<<"�������ַ���Ϊ��"<<ys<<endl;
		}else
		{
			break;
		}
	}
}

void tips()
{
	printf("0���˳�����\n");
	printf("1:�޸�\n");
	printf("2:ɾ��������������\n");
	printf("3:����\n");
	printf("4:���ַ����Ƚ�\n");
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

	cout<<"Ŀ���ַ�������Ϊ��"<<aimStr.size()<<endl;

	cout<<"ѡ����Ҫ�޸ĵ�λ�ã�����=1��"<<endl;
	cin>>location;
	location=location-1;//string�ı�Ŵ�0,��ʼ��
	maxReplaceLen=aimStrLen-1-location;//jdr:���޸�λ�õ�Դ�ַ���ĩβ�ĳ���

	cout<<"�Ƿ�������ַ���ĩβ:ѡ�����־Ϳ���(1,yes,0,no)"<<endl;
	cin>>replaceFlag;

	cout<<"��������Ҫ�޸ĳ�Ϊ������"<<endl;
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

	cout<<"�޸ĺ���ַ���Ϊ��"<<aimStr<<endl;
	cout<<"�޸Ľ�����"<<endl;
}



void remove(string &aimStr)
{
	cout<<"��������������������ݣ�"<<endl;
	cin>>aimStr;
	cout<<"�������������"<<endl;
}

void find(string &aimStr)
{
	string findStr;
	int location;
	cout<<"��������Ҫ�������ݣ�"<<endl;
	cin>>findStr;
	if(location=aimStr.find(findStr)>=0)
	{
		cout<<"����ҵ����ݳ����ڣ�"<<location+1<<"!"<<endl;
	}
	else
	{
		cout<<"����ҵ����ݲ��ڸ��ַ�����!"<<endl;
	}
	cout<<"���ҽ�����"<<endl;
}

void compare(string &aimStr)
{
	string compareStr;
	int location;
	int leng;
	cout<<"��������Ҫ��Դ�ַ����Ƚϵ����ݣ�"<<endl;
	cin>>compareStr;
	cout<<"���뿪ʼ�Ƚϵ�λ�ã�"<<endl;
	cin>>location;
	cout<<"����Ƚϵĳ��ȣ�"<<endl;
	cin>>leng;
	cout<<"�ȽϵĽ��Ϊ��"<<endl;

	if(aimStr.compare(location,leng,compareStr)==1)
	{
		cout<<"��Ƚϵ�������ͬ��"<<endl;
	}
	else
	{
		cout<<"��Ƚϵ����ݺ�����ͬ��"<<endl;
	}


	cout<<"�ȽϽ�����"<<endl;

}
