��̬��̬�����˼�룺������صĶ������ͣ�ֱ��ʵ�����Ǹ��ԵĶ��壬����Ҫ���л��࣬��������û���κι�ϵ��ֻ��Ҫ�����������ʵ����Ҫ����ͬ�Ľӿ�����������Ľӿڳ�֮Ϊ��ʽ�ӿڡ��ͻ��˰Ѳ�����Щ����ĺ�������Ϊģ�壬����Ҫ����ʲô���͵Ķ���ʱ��ֱ�Ӷ�ģ��ָ��������ʵ�μ��ɣ���ͨ��ʵ�������ã���

���������������У�����ʽ�ӿں������ڶ�̬���麯����ʵ�ֶ�̬��̬����ģ���̼����ͱ���У�������ʽ�ӿںͱ�������̬��ʵ�־�̬��̬��

�����룺

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