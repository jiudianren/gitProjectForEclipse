[c++内存布局最完整](https://blog.csdn.net/watson2016/article/details/68937074)

https://www.cnblogs.com/QG-whz/p/4909359.html


显然，虚继承之所以能够实现在多重派生子类中只保存一份共有基类的拷贝，
关键在于vbptr指针。
那vbptr到底指的是什么？
又是如何实现虚继承的呢？其实上面的类D内存布局图中已经给出答案：