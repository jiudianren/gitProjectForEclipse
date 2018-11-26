��̬�� �м���ʵ�ַ�ʽ��

��̬���÷�


https://www.cnblogs.com/Leo_wl/p/3667870.html


#ʲô�Ƕ�̬��̬��
��̬��̬�����˼�룺������صĶ������ͣ�ȷ������֮���һ����ͬ���ܼ���Ȼ���ڻ����У�����Щ��ͬ�Ĺ�������Ϊ����������麯���ӿڡ�����������д��Щ�麯��������ɾ���Ĺ��ܡ��ͻ��˵Ĵ��루����������ͨ��ָ���������û�ָ����������Щ���󣬶��麯���ĵ��û��Զ��󶨵�ʵ���ṩ�����������ȥ��

������Ķ���Ҳ���Կ��������������麯������˶�̬��̬��������ʱ��ɵģ�Ҳ���Խ��������ڶ�̬��������˶�̬��̬�����ڴ������ʶ��󼯺�ʱ��ǿ����������Ȼ��Ҳ����һ���������ʧ����


	namespace DynamicPoly
	{
	    class Geometry
	    {
	    public:
	        virtual void Draw()const = 0;
	    };
	
	    class Line : public Geometry
	    {
	    public:
	        virtual void Draw()const{    std::cout << "Line Draw()\n";    }
	    };
	
	    class Circle : public Geometry
	    {
	    public:
	        virtual void Draw()const{    std::cout << "Circle Draw()\n";    }
	    };
	
	    class Rectangle : public Geometry
	    {
	    public:
	        virtual void Draw()const{    std::cout << "Rectangle Draw()\n";    }
	    };
	
	    void DrawGeometry(const Geometry *geo)
	    {
	        geo->Draw();
	    }
	
	    //��̬��̬��������֮�����ڴ������ʶ��󼯺ϵ�����
	    void DrawGeometry(std::vector<DynamicPoly::Geometry*> vecGeo)
	    {
	        const size_t size = vecGeo.size();
	        for(size_t i = 0; i < size; ++i)
	            vecGeo[i]->Draw();
	    }
	}
	
	void test_dynamic_polymorphism()
	{
	    DynamicPoly::Line line;
	    DynamicPoly::Circle circle;
	    DynamicPoly::Rectangle rect;
	    DynamicPoly::DrawGeometry(&circle);
	
	    std::vector<DynamicPoly::Geometry*> vec;
	    vec.push_back(&line);
	    vec.push_back(&circle);
	    vec.push_back(&rect);
	    DynamicPoly::DrawGeometry(vec);
	}


#��̬��̬

��̬��̬�����˼�룺������صĶ������ͣ�ֱ��ʵ�����Ǹ��ԵĶ��壬
����Ҫ���л��࣬��������û���κι�ϵ��
ֻ��Ҫ�����������ʵ����Ҫ����ͬ�Ľӿ�����������Ľӿڳ�֮Ϊ��ʽ�ӿڡ�
�ͻ��˰Ѳ�����Щ����ĺ�������Ϊģ�壬
����Ҫ����ʲô���͵Ķ���ʱ��ֱ�Ӷ�ģ��ָ��������ʵ�μ��ɣ���ͨ��ʵ�������ã���

���������������У�����ʽ�ӿں������ڶ�̬���麯����ʵ�ֶ�̬��̬����ģ���̼����ͱ���У�������ʽ�ӿںͱ�������̬��ʵ�־�̬��̬��

	namespace StaticPoly
	{
	    class Line
	    {
	    public:
	        void Draw()const{    std::cout << "Line Draw()\n";    }
	    };
	
	    class Circle
	    {
	    public:
	        void Draw(const char* name=NULL)const{    std::cout << "Circle Draw()\n";    }
	    };
	
	    class Rectangle
	    {
	    public:
	        void Draw(int i = 0)const{    std::cout << "Rectangle Draw()\n";    }
	    };
	
	    template<typename Geometry>
	    void DrawGeometry(const Geometry& geo)
	    {
	        geo.Draw();
	    }
	
	    template<typename Geometry>
	    void DrawGeometry(std::vector<Geometry> vecGeo)
	    {
	        const size_t size = vecGeo.size();
	        for(size_t i = 0; i < size; ++i)
	            vecGeo[i].Draw();
	    }
	}
	
	void test_static_polymorphism()
	{
	    StaticPoly::Line line;
	    StaticPoly::Circle circle;
	    StaticPoly::Rectangle rect;
	    StaticPoly::DrawGeometry(circle);
	
	    std::vector<StaticPoly::Line> vecLines;
	    StaticPoly::Line line2;
	    StaticPoly::Line line3;
	    vecLines.push_back(line);
	    vecLines.push_back(line2);
	    vecLines.push_back(line3);
	    //vecLines.push_back(&circle); //��������Ѳ����ܹ��������ʶ���
	    //vecLines.push_back(&rect);    //��������Ѳ����ܹ��������ʶ���
	    StaticPoly::DrawGeometry(vecLines);
	
	    std::vector<StaticPoly::Circle> vecCircles;
	    vecCircles.push_back(circle);
	    StaticPoly::DrawGeometry(circle);
	}
	
	
	
	
	
# CRTP
����ݹ�ģ��ģʽ https://www.cnblogs.com/fresky/p/3504241.html
C++�ľ�̬�ַ�(CRTP)�Ͷ�̬�ַ�(�麯����̬)�ıȽ�

	template<typename Derived>  class Parent 
	{
	public:
	    void SayHi()
	    {
	        static_cast<Derived*>(this)->SayHiImpl();
	    }
	private:
	    void SayHiImpl() // no need if no need the default implementation
	    {
	        cout << "hi, i'm default!" << endl;
	    }
	};
	
	
	class ChildA :public Parent<ChildA>
	{
	public:
	    void SayHiImpl()
	    {
	        cout << "hi, i'm child A!" << endl;
	    }
	};
	
	class ChildB :public Parent<ChildB>
	{
	};