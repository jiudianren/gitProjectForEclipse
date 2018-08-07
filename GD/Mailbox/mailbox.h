/*
	全双工邮箱通讯，两个程序分别同过共享内存(邮箱)相互传输数据，

   分别都有一个读写线程，读写个自通讯数据区域，一个读线程对应另一个进程的写线程；
	先运行mailbox_a.c
*/



#define MAX 512		/*邮箱大小*/
#define SIZE 80		/*读缓冲区大小*/
#define BUFF_MAX ((MAX - 16)/2)	/*邮箱半双工数据区大小*/

/*结构体模拟邮箱结构*/
struct mailbox{
		int iHead;
		int iTail;
		int kHead;
		int kTail;
		char cBuff[BUFF_MAX];
		char bBuff[BUFF_MAX];
};

/*定义一个邮箱指针*/
struct mailbox *my_box;



