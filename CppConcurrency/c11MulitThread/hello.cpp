
#include <iostream>
#include <thread> //��
void hello() //��
{
	std::cout << "Hello Concurrent World\n";
}
int main()
{
	std::thread t(hello); //��
	t.join(); //��

	/*
	 *
	 * �µ��߳�����֮��ۣ���ʼ�̼߳���ִ�С���������ȴ����߳̽��������ͽ��Թ��Եؼ�����
�е�main()�Ľ������Ӷ��������򡪡��п��ܷ��������߳�����֮ǰ�������Ϊʲô�ڢ�����
���� join() ��ԭ�򡪡������2�£���ᵼ�µ����߳�(��main()��)�ȴ��� std::thread ����
��������̣߳�����������е�t*/
}
