

/*�����ڴ����������������̽��̹���ͬһ���ڴ�(����ڴ��ӳ�䵽���������Լ������ĵ�ַ�ռ�)
  �Ӷ�ʹ����Щ���̿����໥ͨ�š�
  ��GNU/Linux�����еĽ��̶���Ψһ�������ַ�ռ䣬�������ڴ�Ӧ�ñ�̽ӿ�API����һ������ʹ
  �ù����ڴ����Ρ����Ƕ��ڴ�Ĺ�������临�Ӷ�Ҳ��Ӧ���ӡ������ڴ���ŵ��Ǽ����ԡ�
  ʹ����Ϣ����ʱ��һ������Ҫ�������д����Ϣ����Ҫ������û���ַ�ռ����ں˵�ַ�ռ��һ�θ��ƣ�
  ͬ��һ�����̽�����Ϣ��ȡʱҲҪ����һ�θ��ơ������ڴ���ŵ�����ȫʡȥ����Щ������
  �����ڴ��ӳ�䵽���̵������ַ�ռ䣬���̶������ֱ�ӷ��ʣ����������ݵĸ��ƹ��̡�
  ��ˣ������ڴ���GNU/Linux���ڿ��õ�����ٵ�IPC���ơ�
  �����˳�ʱ���Զ����Ѿ��ҽӵĹ����ڴ����η��룬�����Խ��鵱���̲���ʹ�ù�������ʱ
  ����shmdt��ж�����Ρ�
  ע�⣬��һ�����̷�֧�������̺��ӽ���ʱ����������ǰ���������й����ڴ����ζ��ᱻ�ӽ��̼̳С�
  ��������Ѿ�����ɾ�����(��ǰ����IPC����RMIDָ�����shmctl)������ǰ�ҽ����Ѿ���Ϊ0��
  ������ξͻᱻ�Ƴ���
 */
/*
  shmget(  )  ����һ���µĹ����ڴ�����
              ȡ��һ�������ڴ����ε�������
  shmctl(  )  ȡ��һ�������ڴ����ε���Ϣ
              Ϊһ�������ڴ����������ض�����Ϣ
              �Ƴ�һ�������ڴ�����
  shmat(  )   �ҽ�һ�������ڴ�����
  shmdt(  )   ��һ�������ڴ����εķ���
 */
//����һ�������ڴ����Σ�����ʾ�������Ϣ��Ȼ��ɾ�����ڴ湲����
#include <stdio.h>
#include <unistd.h>  //getpagesize(  )
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 67483
int main(  )
    {
        //���ϵͳ��ҳ��Ĵ�С
        printf( "page size=%d/n",getpagesize(  ) );
        //����һ�������ڴ�����
        int shmid,ret;
        shmid=shmget( MY_SHM_ID,4096,0666|IPC_CREAT );
        //������һ��4KB��С�����ڴ����Ρ�ָ���Ĵ�С�����ǵ�ǰϵͳ<a href="http://lib.csdn.net/base/16" class='replace_word' title="������վ�ܹ�֪ʶ��" target='_blank' style='color:#df3434; font-weight:bold;'>�ܹ�</a>
        //��ҳ���С��������
        if( shmid>0 )
            printf( "Create a shared memory segment %d/n",shmid );
        //���һ���ڴ����ε���Ϣ
        struct shmid_ds shmds;
        //shmid=shmget( MY_SHM_ID,0,0 );//ʾ���������һ�������ڴ�ı�ʶ��
        ret=shmctl( shmid,IPC_STAT,&shmds );
        if( ret==0 )
            {
                printf( "Size of memory segment is %d/n",shmds.shm_segsz );
                printf( "Numbre of attaches %d/n",( int )shmds.shm_nattch );
            }
        else
            {
                printf( "shmctl(  ) call failed/n" );
            }
        //ɾ���ù����ڴ���
        ret=shmctl( shmid,IPC_RMID,0 );
        if( ret==0 )
            printf( "Shared memory removed /n" );
        else
            printf( "Shared memory remove failed /n" );
        return 0;
    }
