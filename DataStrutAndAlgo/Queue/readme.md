

用数组实现 队列

两个栈 实现一个队列
https://www.cnblogs.com/MrListening/p/5697459.html


	#include<stack>
	template<typename T>
	class QueueBy2Stack
	{
	public:
	
	    void push(const T& data)
	    {
	        s1.push(data);
	    }
	    void pop()
	    {
	        if (s1.empty() && s2.empty())
	        {
	            cout << "The queue is empty";
	        }
	        if (!s2.empty())
	        {
	            s2.pop();
	        }
	        else
	        {
	            while (!s1.empty())
	            { 
	                s2.push(s1.top());
	                s1.pop();
	            }
	            s2.pop();
	        }
	    }
	    T& Front()
	    {
	        assert(!s1.empty() || !s2.empty());
	        if (s2.empty())
	        {
	            while (!s1.empty())
	            {
	                s2.push(s1.top());
	                s1.pop();
	            }
	        }
	        return s2.top();
	    }
	    T& Back()
	    {
	        assert(!s1.empty() || !s2.empty());
	        if (s1.empty() )
	        {
	            while (!s2.empty())
	            {
	                s1.push(s2.top());
	                s2.pop();
	            }
	        }
	        return s1.top();
	    }
	    size_t size()
	    {
	        return s1.size() + s2.size();
	    }
	    bool empty()
	    {
	        if (s1.empty() && s2.empty())
	        {
	            return true;
	        }
	        return false;
	    }
	private:
	    stack<T> s1;
	    stack<T> s2;
	};