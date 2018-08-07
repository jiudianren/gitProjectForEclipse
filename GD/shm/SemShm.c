/*
 * SemShm.c
 *
 *  Created on: 2016��8��16��
 *      Author: Administrator
 */




////////////////////////////////////////////////////////////////////////
/*ʹ������Э�������ڴ������
  ʹ�úͱ�������
  gcc -Wall test.c -o test
  ./test create
  ./test use a &
  ./test use b &
  ./test read &
  ./test remove
 */
////////////////////////////////////////////////
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MY_SHM_ID 34325
#define MY_SEM_ID 23234
#define MAX_STRING 200
typedef struct
{
    int semID;
    int counter;
    char string[ MAX_STRING+1 ];
}MY_BLOCK_T;
int main(int argc,char** argv)
    {
        int shmid,ret,i;
        MY_BLOCK_T* block;
        struct sembuf sb;
        char user;
        //make sure there is a command
        if( argc>=2 )
            {
                //create the shared memory segment and init it
                //with the semaphore
              if( !strncmp(argv[ 1 ],"create",6) )
                    {
                        //create the shared memory segment and semaphore
                        printf( "Creating the shared memory/n" );
                        shmid=shmget( MY_SHM_ID,sizeof( MY_BLOCK_T ),( IPC_CREAT|0666 ) );
                        block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );
                        block->counter=0;
                        //create the semaphore and init
                        block->semID=semget(MY_SEM_ID,1,( IPC_CREAT|0666 ));
                        sb.sem_num=0;
                        sb.sem_op=1;
                        sb.sem_flg=0;
                        semop( block->semID,&sb,1 );
                        //now detach the segment
                        shmdt( ( void* )block );
                        printf( "Create the shared memory and semaphore successuflly/n" );

                    }
                else if( !strncmp(argv[ 1 ],"use",3) )
                    {
                        /*use the segment*/
                        //must specify  also a letter to write to the buffer
                        if( argc<3 ) exit( -1 );
                        user=( char )argv[ 2 ][ 0 ];
                        //grab the segment
                        shmid=shmget( MY_SHM_ID,0,0 );
                        block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );

                        /*##########�ص����ʹ������Թ������ķ���###########*/
                        for( i=0;i<100;++i )
                        {
                            sleep( 1 ); //���ó�1s�ͻῴ�� a/b������֣�Ϊ0��a��b��������
                        //grab the semaphore
                        sb.sem_num=0;
                        sb.sem_op=-1;
                        sb.sem_flg=0;
                        if( semop( block->semID,&sb,1 )!=-1 )
                            {
                                //write the letter to the segment buffer
                                //this is our CRITICAL SECTION
                                block->string[ block->counter++ ]=user;

                                sb.sem_num=0;
                                sb.sem_op=1;
                                sb.sem_flg=0;
                                if( semop( block->semID,&sb,1 )==-1 )
                                    printf( "Failed to release the semaphore/n" );

                            }
                        else
                            printf( "Failed to acquire the semaphore/n" );
                        }

                       //do some clear work
                        ret=shmdt(( void*)block);

                    }
                else if( !strncmp(argv[ 1 ],"read",4) )
                    {
                        //here we will read the buffer in the shared segment
                        shmid=shmget( MY_SHM_ID,0,0 );
                        if( shmid!=-1 )
                            {
                                block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );
                                block->string[ block->counter+1 ]=0;
                                printf( "%s/n",block->string );
                                printf( "Length=%d/n",block->counter );
                                ret=shmdt( ( void*)block );
                             }
                        else
                            printf( "Unable to read segment/n" );

                    }
                else if( !strncmp(argv[ 1 ],"remove",6) )
                    {
                        shmid=shmget( MY_SHM_ID,0,0 );
                        if( shmid>=0 )
                            {
                                block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );
                                //remove the semaphore
                                ret=semctl( block->semID,0,IPC_RMID );
                                if( ret==0 )
                                    printf( "Successfully remove the semaphore /n" );
                                //remove the shared segment
                                ret=shmctl( shmid,IPC_RMID,0 );
                                if( ret==0 )
                                    printf( "Successfully remove the segment /n" );
                            }
                    }
                else
                    printf( "Unkonw command/n" );
            }
        return 0;

    }
