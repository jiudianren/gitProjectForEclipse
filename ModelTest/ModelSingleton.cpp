
/*
 * 线程安全的 单例模式
 * https://www.cnblogs.com/myd620/p/6133420.html
 * */


/* 饿汉模式
 * （1）饿汉

需要动手写一下


饿汉单例，即在最开始的时候，静态对象就已经创建完成；
设计方法是类中包含一个静态成员指针，该指针指向该类的一个对象，提供一个公有的静态成员方法，返回该对象指针；
为了使得对象唯一，还需要将构造函数设为私有，
 * */



template <class T>  class singletonOne
{
protected:
    singletonOne(){}; 	// 注意点 1  将默认构造函数设置为 protected
private:
    singletonOne(const singletonOne &)              = delete;//禁止拷贝  注意点3
    singletonOne & operator=(const singletonOne &)  = delete;//禁止赋值  注意点4
    static T* m_instance;      // 注意点2  静态成员变量  指针
public:
    static T* GetInstance();  //注意点4   getInstance的成员函数也要是 static函数，并且是public
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




