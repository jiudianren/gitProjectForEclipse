/*
 * ModelSingleton.cpp
 *
 *  Created on: 2018��3��15��
 *      Author: Administrator
 */



/*
 * �̰߳�ȫ�� ����ģʽ
 *
 * https://www.cnblogs.com/myd620/p/6133420.html
 * */


/* ����ģʽ
 * */
template <class T>
class singletonOne
{
protected:
    singletonOne(){};
private:
    singletonOne(const singletonOne &)              = delete;//��ֹ����
    singletonOne & operator=(const singletonOne &)  = delete;//��ֹ��ֵ
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





/*����ģʽ �̲߳���ȫ */
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


/*��Ϊ����߳�ͬʱ����GetInstance()�������Ϳ��ܵ����в������ʵ����Ҫʵ���̰߳�ȫ���ͱ������  */
template <class T>
T* singletonTwice<T>::GetInstance()
{
    if( m_instance == NULL)
    {
        m_instance = new T();
    }
    return m_instance;
}


/*�̰߳�ȫ������ÿ�μ��� Ӱ������  */
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
 * ��Ҳ������ν�ġ�˫���������ơ�����������������ʵ�ֻ��������⣬
 * ��ִ�� m_instance = new T()ʱ������ ��T��û�г�ʼ����ɣ�
 * m_instance ���Ѿ���ֵ�ˡ������ᵼ������һ������GetInstance()�������̣߳�
 * ��ȡ����δ��ʼ����ɵ�m_instance ָ�룬���ȥʹ������
 * �������ϲ����ĺ������ʵ���������Ҳ�ܼ򵥣���һ���ֲ����������¼���
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




