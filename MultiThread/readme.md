���߳���� ����


# �߳�����  
pthread_attr_init(&thread_attr);  
pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);    
pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE );  
pthread_attr_setscope(&thread_attr, PTHREAD_SCOPE_SYSTEM);  
pthread_attr_setstacksize(&thread_attr, stack * 1024 * 1024);  
pthread_attr_destroy(&thread_attr);  


#�̴߳��� �Լ����з�ʽ
pthread_create(&dwThreadId, &thread_attr, (void *(*)(void *))startaddr, (LPVOID)parg))
pthread_self()  
pthread_cancel  
pthread_join();//�߳������Ժ󣬱�����ȷ�̵߳Ľ�����ʽ �ǵ��ü���ʽ join ���Ƿ���ʽ detach��
pthread_detach();  
pthread_exit  


#������
pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_init
pthread_mutex_lock( &MUTEX );
pthread_mutex_trylock
pthread_mutex_unlock( &MUTEX );
pthread_mutex_destroy
   

# �����߳���������
pthread_key_t    rl_key;
pthread_key_create()   
pthread_setspecific()
pthread_getspecific()

# ��������
pthread_cond_t CON_NOT_FULL  = PTHREAD_COND_INITIALIZER;
pthread_cond_init
pthread_cond_wait( & CON_NOT_EMPTY  , & MUTEX  );
pthread_cond_timedwait
pthread_cond_signal( &CON_NOT_FULL);
pthread_cond_broadcast
pthread_cond_destroy
 
# �߳�һ�ε���
pthread_once()
pthread_once_t 

#��д��
pthread_rwlock_init  
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);  
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);  
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);  

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);  
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);  

int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abs_timeout);  
int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abs_timeout);   

int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);  


/*
�����оֲ���̬�����ĺ������ǲ����̲߳���ȫ�ġ�

mallco �� free ���ǲ��� ���� 
*/
