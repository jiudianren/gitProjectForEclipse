/*
 * ModelSingleton.cpp
 *
 *  Created on: 2018年3月15日
 *      Author: Administrator
 */



/*
 * 线程安全的 单例模式
 *
 * https://www.cnblogs.com/myd620/p/6133420.html
 * */


/* 饿汉模式
 * */
template <class T>
class singletonOne
{
protected:
    singletonOne(){};
private:
    singletonOne(const singletonOne &)              = delete;//禁止拷贝
    singletonOne & operator=(const singletonOne &)  = delete;//禁止赋值
    static T* m_instance;
public:
    static T* GetInstance();
};


template <class T>
T* singletonOne<T>::GetInstance()
{
    return m_instance;
}

template <class T>
T* singletonOne<T>::m_instance = new T();





/*懒汉模式 线程不安全 */
template <class T>
class singletonTwice
{
protected:
    singletonTwice(){};
private:
    singletonTwice(const singletonTwice&){};
    singletonTwice& operator=(const singletonTwice&){};
    static T* m_instance;
public:
    static T* GetInstance();
    static T* GetInstance2();
    static T* GetInstance3();
};


/*因为多个线程同时调用GetInstance()方法，就可能导致有产生多个实例。要实现线程安全，就必须加锁  */
template <class T>
T* singletonTwice<T>::GetInstance()
{
    if( m_instance == NULL)
    {
        m_instance = new T();
    }
    return m_instance;
}


/*线程安全，但是每次加锁 影响性能  */
template <class T>
T* singletonTwice<T>::GetInstance2()
{
    pthread_mutex_lock(&mutex);
    if( m_instance == NULL)
    {
        m_instance = new T();
    }
    pthread_mutex_unlock(&mutex);
    return m_instance;
}


template <class T>
T* singletonTwice<T>::GetInstance3()
{
    if( m_instance == NULL)
    {
        pthread_mutex_lock(&mutex);
        if( m_instance == NULL)
        {
             m_instance = new T();
        }
        pthread_mutex_unlock(&mutex);
    }
    return m_instance;
}


/*
 * 这也就是所谓的“双检锁”机制。但是有人质疑这种实现还是有问题，
 * 在执行 m_instance = new T()时，可能 类T还没有初始化完成，
 * m_instance 就已经有值了。这样会导致另外一个调用GetInstance()方法的线程，
 * 获取到还未初始化完成的m_instance 指针，如果去使用它，
 * 会有意料不到的后果。其实，解决方法也很简单，用一个局部变量过渡下即可
 * */

template <class T>
T* singleton<T>::GetInstance()
{
    if( m_instance == NULL)
    {
        pthread_mutex_lock(&mutex);
        if( m_instance == NULL)
        {
             T* ptmp = new T();
             m_instance = ptmp;
        }
        pthread_mutex_unlock(&mutex);
    }
    return m_instance;
}

template <class T>
T* singletonTwice<T>::m_instance = NULL;




