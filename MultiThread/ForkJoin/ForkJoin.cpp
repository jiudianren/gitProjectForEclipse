#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
/*
 *��ģ�Ͱ����ݹ�˼��ͻ���˼�룬�ݹ�����������񣬻����úϲ������
 *  ������������һЩ���Խ��в�ֵĴ�����
 *  ����Ҫ�ǰ�һ���������𼶲��Ϊ���������Ȼ��ֱ������߳���ִ�У�
 *  ��ÿ�����߳�ִ�н���֮���𼶻��ݣ����ؽ�����л��ܺϲ������յó���Ҫ�Ľ����
 * */

/*
 *����һ�����ֵļӺͣ�
 *�����������̫�࣬���䰴�գ�ÿ�鲻����max������ ���в�֡�
 * */

pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CON_NOT_FULL  = PTHREAD_COND_INITIALIZER;
pthread_cond_t CON_NOT_EMPTY = PTHREAD_COND_INITIALIZER;


#define  UNIT_LONG 20
#define  START_NUM  0
#define  END_NUM 300
typedef struct
{
    long start;
    long end;
} TSubArray ,* PTSubArray;



void * MultiThreadSub( void * args)
{
    TSubArray * pInput =  (TSubArray *) args;
    TSubArray  tInput = *pInput;

    long lRet =0;
    long lDiff=  tInput.end - tInput.start;
    if(  lDiff > UNIT_LONG )
    {
        TSubArray tFront;
        TSubArray tBehind;

        long lMid= tInput.start + lDiff/2;
        tFront.start = tInput.start;
        tFront.end = lMid;

        tBehind.start = lMid + 1;
        tBehind.end = tInput.end;

        pthread_t pFrnt ;
        pthread_t pBeh ;

        int  ret = pthread_create( &pFrnt, NULL, MultiThreadSub , &tFront );
        if( ret != 0)
        {
            printf(" inner pthread_create erro %d  \n",ret );
            exit(0);
        }

        ret = pthread_create( &pBeh, NULL, MultiThreadSub , &tBehind );
        if( ret != 0)
        {
            printf(" inner pthread_create erro %d  \n",ret );
            exit(0);
        }



        void * tFnt;
        void * tBeh;
        ret = pthread_join( pFrnt  , & tFnt );  //�ȴ��߳̽��
        ret = pthread_join( pBeh  , & tBeh );    //�ȴ��߳̽��

        if( tFnt == PTHREAD_CANCELED )
        {
            printf(" inner pthread_join erro: PTHREAD_CANCELED  \n" );
            exit(0);
        }
        printf("inner Front---start:[%ld] end:[%ld] Fnt result:%ld. \n", tFront.start, tFront.end,(long)tFnt );

        if( tBeh == PTHREAD_CANCELED )
        {
            printf(" inner pthread_join erro: PTHREAD_CANCELED  \n" );
            exit(0);
        }
        printf("inner Behind---start:[%ld] end:[%ld] Fnt result:%ld. \n", tBehind.start, tBehind.end,(long)tBeh );

        lRet = (long )tFnt + (long )tBeh ;
    }
    else
    {
        for( long i= tInput.start; i<=tInput.end ; i++)
        {
            lRet+=i;
        }
    }


    return ( (void *) lRet);
}

int main(void)
{
    printf("ForkJoin start ==========.\n");


    TSubArray tSubArray;
    tSubArray.start = START_NUM;
    tSubArray.end   = END_NUM;

    /*
    (void *) iRet = NULL;
    iRet =  MultiThreadSub( &tSubArray );
   printf("Sub result:%d. \n", &iRet );
     */

    pthread_t pMultiSub ;

    int ret = pthread_create( &pMultiSub, NULL, MultiThreadSub , &tSubArray );
    if( ret !=0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }

    void * tRet;
    ret = pthread_join( pMultiSub  , & tRet );
    if( ret !=0)
    {
        printf("pthread_join erro %d  \n",ret );
        exit(0);
    }

    if( tRet == PTHREAD_CANCELED )
    {
        printf("pthread_join erro PTHREAD_CANCELED  \n" );
        exit(0);
    }

    //(tSubArray.end* (tSubArray.end -1))/2
    printf("Sub result:%d. \n", (long)tRet );


    printf("ForkJoin end ==========.\n");
    return 0;
}
