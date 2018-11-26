多态的 有几种实现方式：

多态的用法


https://www.cnblogs.com/Leo_wl/p/3667870.html


#什么是动态多态？
动态多态的设计思想：对于相关的对象类型，确定它们之间的一个共同功能集，然后在基类中，把这些共同的功能声明为多个公共的虚函数接口。各个子类重写这些虚函数，以完成具体的功能。客户端的代码（操作函数）通过指向基类的引用或指针来操作这些对象，对虚函数的调用会自动绑定到实际提供的子类对象上去。

从上面的定义也可以看出，由于有了虚函数，因此动态多态是在运行时完成的，也可以叫做运行期多态，这造就了动态多态机制在处理异质对象集合时的强大威力（当然，也有了一点点性能损失）。


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
	
	    //动态多态最吸引人之处在于处理异质对象集合的能力
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


#静态多态

静态多态的设计思想：对于相关的对象类型，直接实现它们各自的定义，
不需要共有基类，甚至可以没有任何关系。
只需要各个具体类的实现中要求相同的接口声明，这里的接口称之为隐式接口。
客户端把操作这些对象的函数定义为模板，
当需要操作什么类型的对象时，直接对模板指定该类型实参即可（或通过实参演绎获得）。

相对于面向对象编程中，以显式接口和运行期多态（虚函数）实现动态多态，在模板编程及泛型编程中，是以隐式接口和编译器多态来实现静态多态。

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
	    //vecLines.push_back(&circle); //编译错误，已不再能够处理异质对象
	    //vecLines.push_back(&rect);    //编译错误，已不再能够处理异质对象
	    StaticPoly::DrawGeometry(vecLines);
	
	    std::vector<StaticPoly::Circle> vecCircles;
	    vecCircles.push_back(circle);
	    StaticPoly::DrawGeometry(circle);
	}
	
	
	
	
	
# CRTP
奇异递归模板模式 https://www.cnblogs.com/fresky/p/3504241.html
C++的静态分发(CRTP)和动态分发(虚函数多态)的比较

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