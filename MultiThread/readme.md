多线程相关 内容


# 线程属性
pthread_attr_init(&thread_attr);
pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE );
pthread_attr_setscope(&thread_attr, PTHREAD_SCOPE_SYSTEM);
pthread_attr_setstacksize(&thread_attr, stack * 1024 * 1024);
pthread_attr_destroy(&thread_attr);


#线程创建 以及运行方式
pthread_create(&dwThreadId, &thread_attr, (void *(*)(void *))startaddr, (LPVOID)parg))
pthread_self()
pthread_cancel
pthread_join();//线程启动以后，必须明确线程的结束方式 是调用加入式 join 还是分离式 detach。
pthread_detach();
pthread_exit


#互斥锁
pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_init
pthread_mutex_lock( &MUTEX );
pthread_mutex_trylock
pthread_mutex_unlock( &MUTEX );
pthread_mutex_destroy
   

# 各个线程特有数据
pthread_key_t    rl_key;
pthread_key_create()   
pthread_setspecific()
pthread_getspecific()

# 条件变量
pthread_cond_t CON_NOT_FULL  = PTHREAD_COND_INITIALIZER;
pthread_cond_init
pthread_cond_wait( & CON_NOT_EMPTY  , & MUTEX  );
pthread_cond_timedwait
pthread_cond_signal( &CON_NOT_FULL);
pthread_cond_broadcast
pthread_cond_destroy
 
# 线程一次调用
pthread_once()
pthread_once_t 

#读写锁
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
包含有局部静态变量的函数，是不能线程不安全的。

mallco 和 free 都是不可 重入 
*/
