/*todo
 *
 *
 * https://www.cnblogs.com/lang5230/p/5322668.html */


class Subject
{
public:

    virtual ~Subject()=0;
    virtual void Request()=0;//具体代理的任务
protected:
    Subject();
};

class ConcreteSubject:public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();
    void Request();
};

class Proxy:public Subject
{
public:
    Proxy();
    Proxy(Subject* _sub);
    void Request()//实现对委托者的委托任务执行与补偿
    {
        bef();
        this->_sub->Request();
        end();
    }
    void bef()
    {}

    void end()
    {}

    ~Proxy();
private:

    Subject* _sub;
};
