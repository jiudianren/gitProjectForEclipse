/*
	ȫ˫������ͨѶ����������ֱ�ͬ�������ڴ�(����)�໥�������ݣ�

   �ֱ���һ����д�̣߳���д����ͨѶ��������һ�����̶߳�Ӧ��һ�����̵�д�̣߳�
	������mailbox_a.c
*/



#define MAX 512		/*�����С*/
#define SIZE 80		/*����������С*/
#define BUFF_MAX ((MAX - 16)/2)	/*�����˫����������С*/

/*�ṹ��ģ������ṹ*/
struct mailbox{
		int iHead;
		int iTail;
		int kHead;
		int kTail;
		char cBuff[BUFF_MAX];
		char bBuff[BUFF_MAX];
};

/*����һ������ָ��*/
struct mailbox *my_box;



