#include <iostream>
#include <string>
#include "CallBack.h"
#include <functional>
#include <typeinfo>
using namespace std;


/*�ص����������ã�
 *
 * ���÷���Ҫ���ĳЩ���������ö�����ҪһЩ�������Ϣ����Щ�������Ϣ�����÷���ȫ��֪�����������÷�֪����Щ��Ϣ��
 * �������÷���֪����ʱִ�б���������ֻ��ͨ�����÷����������ñ�����������������ִ�У��������Щ������
 * 1����Щ��Ϣ���÷���֪�����������÷�֪����
 * 2���������÷�����֪����ʱִ�иú�����
 *
 *	����Gx �յ�CCR_i ������
 *	SySp   �յ�SLA�󣬸�֪ Gx���� ����� CCR_i
 *
 *	����Ϳ�����һ���ص�
 *
 * */


//Test �Ǳ���������
// LetRun�ǵ��ú����������ú���ִ�е�ʱ�򣬱���������ִ�У�������������ִ�е�ʱ����Ҫ���ú���������������Ϣ��
void  Test(int n, string str)
{
    cout<<" function called "<<str<<endl;
    cout<<n<<" "<<str<<endl;
}

void mainCallBack()
{
    Call call;
    CalledClass called;
    call.SetFun((MyFun)Test);    //���ص������Ľӿڣ�������һ��������Ϊ����
    call.LetRun(10,"1+1=?");

    //	std::bind(&Test::callback,this,_1,_2);

    //	Fun fun=std::bind(&Test::callback,this,_1,_2);
    //���Ա����������һ��thisָ�룬������ҪһЩ�ֶβ���ת����  �ص������� ��ָ��
    //	MyFun cfun=(MyFun) &called.CalledFun;

    auto cfun= std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    cfun(1,"what is the quesitino");

    std::function<void(int,string)> functional = std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    //    call.SetFun((MyFun) functional);    //���ص������Ľӿڣ�������һ��������Ϊ����
    //    call.LetRun(10,"1+1=?");
    functional(1,"tell me the anwser");


    std::function<void(void)> functional1=std::bind(&CalledClass::CalledFun,called,(int)1000,"tell me the anwser ");
    call.SetFun2(functional1);


    call.SetFun3( &called,& CalledClass::CalledFun);
    call.LetRun3(1, "tell me the anwser");



    std::function<void(int n ,string str)> functional2=std::bind(&CalledClass::CalledFun,called,std::placeholders::_1,std::placeholders::_2);
    call.SetFun4( functional2);
    call.LetRun4(1, "tell me the anwser");


    call.SetFun5( functional2);
    call.LetRun4(1, "tell me the anwser");

}
