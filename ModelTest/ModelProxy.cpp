/*todo
 *
 *
 * https://www.cnblogs.com/lang5230/p/5322668.html */


class Subject
{
public:

    virtual ~Subject()=0;
    virtual void Request()=0;//������������
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
    void Request()//ʵ�ֶ�ί���ߵ�ί������ִ���벹��
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
