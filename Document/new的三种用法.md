#new�������÷���ϸ����

C++ new�ؼ����������
https://blog.csdn.net/bbs375/article/details/53202079

https://blog.csdn.net/wangkai_123456/article/details/75091270

#1 new operator��
Ҳ��new���ʽ��new���ʽ�Ƚϳ�����Ҳ��ã����磺
	
	string* ps = new string("abc");
�������new���ʽ������������飺�����ڴ�ͳ�ʼ������

#2 operator new��
Ҳ��new��������������Ӣ���������Ҳ̫���ˣ������׸�죬�Ǿͼ��������ưɡ�new������������C�� ���е�malloc��ֻ�Ǹ��������ڴ棬���磺

	void* buffer = operator new(sizeof(string));

ע��: �������һ��operator������new�ĵڶ����÷���Ҳ��Ƚϳ����ɡ�

#3 placement new��
�������ڸ������ڴ��г�ʼ������Ҳ����˵����������һ�����õ��ڴ棬���磺

	void* buffer = operator new(sizeof(string));//��ô����buffer������ӵ�������ڴ��ָ��
	buffer = new(buffer) string("abc"); //������placement new����buffer��ָ����ڴ��г�ʼ��string���͵Ķ��󣬳�ʼֵ��"abc"

��ʵ�ϣ�placement newҲ��new���ʽ��һ�֣����Ǳ���ͨ��new���ʽ����һ����������Ȼ��ɵĲ����ͷ���ֵҲ��ͬ��

�������new�ĵ�һ���÷����Էֽ����� �������ֱ�Ϊ����������÷���


��new��Ӧ��deleteû�������﷨����ֻ�����֣��ֱ���`delete operator��operator delete`��Ҳ��Ϊdelete���ʽ��delete��������
delete���ʽ��new���ʽ��Ӧ����ɶ�����������ڴ���ͷŲ�����
��delete ������ֻ�������ڴ���ͷţ���C�����е�free���ơ����磺

 

	string* ps = new string("abc");
	...
	delete ps; //����delete���ʽ�����������ͷ�
	void* buffer = operator new(sizeof(string));
	...
	operator delete(buffer); //�ͷ�

��ôΪʲôû�к� placement new��Ӧ���Ǹ�delete�أ���ʵ���еġ�

placement new����ָ��λ�ó�ʼ������Ҳ���ǵ����˹��캯����
�����֮��Ӧ�ľ������������ˣ�ֻ����������placement��delete����


	void *pv = operator new(sizeof(vector<int>));
	pv = new(pv) vector<int>(8, 0);
	...
	static_cast<vector<int>* >(pv)->~vector(); // call destruct function
	operator delete(pv); // free memory
	pv = NULL;
	//�ȵ���������Ȼ���ڵ���operator delete �ͷŵ��ڴ�
	
	
	


### new opeartor�Ĺ���

	class A
	{
	   int i;
	public:
	   A(int _i) :i(_i*_i) {}
	   void Say()  { printf("i=%d\n", i); }
	};
	//����new��
	A* pa = new A(3);

��ô������̬����һ������Ĺ��̴����൱���������仰��ֻ�Ǵ����ϣ���

	A* pa = (A*)malloc(sizeof(A));
	pa->A::A(3);
	return pa;
	
new operator��������ƽʱ��ʹ�õ�new������Ϊ����ǰ����˵���������裬���ǲ��ܸ�������

�����嵽ĳһ�����е���Ϊ����������������ǵľ���Ҫ��ʱ���������п��ܸ������ġ�

�������������һ��ֻ�Ǽ򵥵���һ��ָ�������ת����ûʲô��˵�ģ������ڱ�����Ĵ�����Ҳ������Ҫ����ת����
ֻ����Ϊ����ʶ���ˡ���ǰ��������Щ�����ˡ�

new operator�ĵ�һ�������ڴ�ʵ������ͨ������operator new����ɵģ������newʵ��������Ӽ��˳�һ���Ĳ����������Ҳ�ǿ������صġ�
operator newĬ����������ȵ��÷����ڴ�Ĵ��룬���Եõ�һ�ζ��ϵĿռ䣬����ɹ��ͷ��أ����ʧ�ܣ���ת��ȥ����һ��new_hander��Ȼ������ظ�ǰ����̡�
������Ƕ�������̲����⣬�Ϳ�������operator new������������ϣ������Ϊ�����磺
	
	class A
	{
	public:
	   void* operator new(size_t size)
	   {
	       printf("operator new called\n");
	       return ::operator new(size);
	   }
	};
	 
	A* a = new A();
	
����ͨ��::operator new������ԭ�е�ȫ�ֵ�new��ʵ�����ڷ����ڴ�֮ǰ���һ�仰��ȫ�ֵ�operator newҲ�ǿ������صģ�������һ���Ͳ����ٵݹ��ʹ��new�������ڴ棬��ֻ��ʹ��malloc�ˣ�

	void* operator new(size_t size)
	{
	   printf("global new\n");
	   return malloc(size);
	}
	

placement new :

	#include <new.h>
	void main()
	{
	   char s[sizeof(A)];
	   A* p = (A*)s;
	   new(p) A(3); //p->A::A(3);
	   p->Say();
	}
	
��ͷ�ļ�<new>��<new.h>�������Ǳ���ģ������ſ���ʹ��placement new�����new(p) A(3)��������ֵ�д������placement new�ˣ���ʵ������ָ���ڴ��ַ����ָ�����͵Ĺ��캯��������һ������Ĺ��ܣ�����A(3)���ǶԹ��캯������ʽ���á����ﲻ�ѷ��֣����ָ���ĵ�ַ�ȿ�����ջ���ֿ����Ƕѣ�placement�Դ˲������֡����ǣ������ر��Ҫ����Ҫֱ��ʹ��placement new ����Ͼ�������������������ʽд����ֻ������new operator��һ��������ѡ�ʹ��new operator�ر��������Զ����ɶ�placement new�ĵ��õĴ��룬���Ҳ����Ӧ������ʹ��deleteʱ�������������Ĵ��롣�����������������ջ��ʹ����placement new��������ֹ�����������������Ҳ����ʽ��������������Ψһ�����

	p->~A();
�����Ǿ���Ĭ�ϵ�new operator���ڴ�Ĺ������������ǵ���Ҫ����ϣ���Լ��ֹ��Ĺ����ڴ�ʱ��placement new�������ˡ�STL�е�allocator��ʹ�������ַ�ʽ������placement new��ʵ�ָ������Ч���ڴ����



#�����ڴ�����쳣
����ǰ����˵��operator new��Ĭ����Ϊ����������ڴ棬
	
	����ɹ��򷵻ش��ڴ��ַ�����ʧ�������һ��new_handler��Ȼ�����ظ��˹��̡�
���ǣ���Ҫ��operator new��ִ�й����з��أ����Ȼ��Ҫ������������֮һ��

	�����ڴ�ɹ�
	new_handler���׳�bad_alloc�쳣
	new_handler�е���exit()�����Ƶĺ�����ʹ�������
���ǣ����ǿ��Լ���Ĭ�������operator new����Ϊ��������

	void* operator new(size_t size)
	{
	   void* p = null
	   while(!(p = malloc(size)))
	   {
	       if(null == new_handler)
	          throw bad_alloc();
	       try
	       {
	          new_handler();
	       }
	       catch(bad_alloc e)
	       {
	          throw e;
	       }
	       catch(��)
	       {}
	   }
	   return p;
	}


��Ĭ������£�
		
		new_handler����Ϊ���׳�һ��bad_alloc�쳣���������ѭ��ֻ��ִ��һ�Ρ�

��������ǲ�ϣ��ʹ��Ĭ����Ϊ�������Զ���һ��new_handler����ʹ��std::set_new_handler����ʹ����Ч�����Զ����new_handler�У����ǿ����׳��쳣�����Խ�������Ҳ��������һЩ����ʹ���п������ڴ汻���г������Ӷ���һ�η���ʱҲ���ɹ���Ҳ����ͨ��set_new_handler����װ��һ�����ܸ���Ч��new_handler�����磺

	void MyNewHandler()
	{
	   printf(��New handler called!\n��);
	   throw std::bad_alloc();
	}
	 
	std::set_new_handler(MyNewHandler);

	
	
##STL ���ڴ������ traits ����

todo
