https://blog.csdn.net/leonan/article/details/21445787


set print thread-events off 

使用gdb 调试多线程

	info threads
	thread thread_no  设置为当前调试线程
	thread app


调试多进程

	set follow-fork-mode [parent|child]