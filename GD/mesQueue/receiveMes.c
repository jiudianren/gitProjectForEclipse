/*receive.c */  
#include <stdio.h>   
#include <sys/types.h>   
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <errno.h>   
  
#define MSGKEY 1024   
  

/*jdr:������Ϣ �߳������ȷ�˳�*/
struct msgstru  
{  
   long msgtype;  
   char msgtext[2048];  
};  
  
/*�ӽ��̣�������Ϣ����*/  
void childproc(){  
  struct msgstru msgs;  
  int msgid,ret_value;  
  char str[512];  
  int count=0;
  while(1){  
     msgid = msgget(MSGKEY,IPC_EXCL );/*�����Ϣ�����Ƿ���� */  
     if(msgid < 0){  
        printf("msq not existed! errno=%d [%s]\n",errno,strerror(errno));  
        sleep(2);  
        _exit(0);
//        continue;
     }  

     /*������Ϣ����*/  
     ret_value = msgrcv(msgid,&msgs,sizeof(struct msgstru),0,0);  
     count++;
//     printf("count=%d \n",count);
     printf("text=[%s] pid=[%d] count=%d\n",msgs.msgtext,getpid(),count);
  }  
  return;  
}  
  
void main()  
{  
  int i,cpid;  
  
  /* create 5 child process */  
  for (i=0;i<5;i++){  
     cpid = fork();  
     if (cpid < 0)  
        printf("fork failed\n");  
     else if (cpid ==0) /*child process*/  
        childproc();  
  }  
}
