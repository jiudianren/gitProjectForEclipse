静态多态的设计思想：对于相关的对象类型，直接实现它们各自的定义，不需要共有基类，甚至可以没有任何关系。只需要各个具体类的实现中要求相同的接口声明，这里的接口称之为隐式接口。客户端把操作这些对象的函数定义为模板，当需要操作什么类型的对象时，直接对模板指定该类型实参即可（或通过实参演绎获得）。

相对于面向对象编程中，以显式接口和运行期多态（虚函数）实现动态多态，在模板编程及泛型编程中，是以隐式接口和编译器多态来实现静态多态。

看代码：

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