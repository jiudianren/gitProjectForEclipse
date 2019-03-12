https://blog.csdn.net/leonan/article/details/21445787



	db provides these facilities for debugging multi-thread programs:
	
	automatic notification of new threads
	‘thread threadno’, a command to switch among threads
	‘info threads’, a command to inquire about existing threads
	‘thread apply [threadno] [all] args’, a command to apply a command to a list of threads
	thread-specific breakpoints
	‘set print thread-events’, which controls printing of messages on thread start and exit.
	‘set libthread-db-search-path path’, which lets the user specify which libthread_db to use if the default choice isn't compatible with the program.




	

使用gdb 调试多线程

	set print thread-events off  打印线程启动和线程退出的信息
	info threads
	thread thread_no  设置为当前调试线程
	thread app


调试多进程

	set follow-fork-mode [parent|child]