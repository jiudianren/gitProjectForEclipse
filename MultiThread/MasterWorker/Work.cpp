/*
 * Work.cpp
 *
 *  Created on: 2017年12月20日
 *      Author: Administrator
 */



#include "Work.h"
#include  <iostream>
using namespace std;

void Work::Run()
{
    cout<<"Work run: "<<this->sWorkName<<  " going to start"<<std::endl;

    int ret = pthread_create( &pThread, NULL, Work::ThreadFnc , this );
    if( ret != 0)
    {
        printf("pthread_create erro %d  \n",ret );
        exit(0);
    }

}

void * Work::ThreadFnc(void * args)
{
    Work * pWork = (Work *)args;

    pthread_t tid = pthread_self();
    printf(" Work::ThreadFnc --Thread id [%u]--work_name [%s]\n " ,
           (unsigned int) tid, pWork->GetWorkName().c_str() );


    bool bAllDone = false;
    while( bAllDone == false)
    {
        pthread_mutex_lock( pWork->pMutex );
        //这里并不获取最后一个*
        cout<<" Task list size  :"<< (int) pWork->listTask->size()<<endl;
        if( pWork->listTask->empty())
        {
            cout<<"****empty"<<std::endl;
            bAllDone = true;
            pthread_mutex_unlock( pWork->pMutex );
            break;
        }

        Task task( pWork->listTask->back() ) ;
        pWork->listTask->pop_back();

        pthread_mutex_unlock( pWork->pMutex );
        auto ptResult =std::make_shared<TResult>() ;
        ptResult->bDone =false;
        ptResult->iResult =-1;
        pWork->Handle( task,  ptResult);

        pWork->mapResult->push_back(ptResult);

    }
    return (void *)0;
}

void  Work::Handle( Task & task, std::shared_ptr<TResult > & result)
{
    pthread_t tid = pthread_self();
    printf("Thread id--[%u] deal task: \n " , (unsigned int) tid);
    cout<<"Task info:"<< task.getId() <<" "<<task.getName()<<" "<<task.getPrice()<<endl;
    result->iResult = task.getPrice( )*2;
    result->bDone = true;
}
