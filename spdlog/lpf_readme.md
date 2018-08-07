spdlog 是什么？ 用来干嘛 ？ 如何用？ 

spdlog是一个开源的、快速的、仅有头文件的C++11 日志库，code地址在 https://github.com/gabime/spdlog ，目前最新的发布版本为0.14.0。它提供了向流、标准输出、文件、系统日志、调试器等目标输出日志的能力。它支持的平台包括Windows、Linux、Mac、Android。

	spdlog特性：

	(1)、非常快，性能是它的主要目标；

	(2)、仅包括头文件；

	(3)、日志的格式化处理使用开源的fmt库(  https://github.com/fmtlib/fmt )；

	(4)、可选的printf语法支持；

	(5)、非常快的异步模式(可选)，支持异步写日志；

	(6)、自定义格式；

	(7)、条件日志；

	(8)、多线程/单线程日志；

	(9)、各种日志目标：可对日志文件进行循环输出；可每日生成日志文件；支持控制台日志输出(支持颜色)；系统日志；Windows debugger；较容易扩展自定义日志目标；

	(10)、支持日志输出级别：阈值级别既可以在运行时也可以在编译时修改。
	
	
	
	
## Benchmarks

Below are some [benchmarks](bench) comparing popular log libraries under Ubuntu 64 bit, Intel i7-4770 CPU @ 3.40GHz

#### Synchronous mode
Time needed to log 1,000,000 lines in synchronous mode (in seconds, the best of 3 runs):

|threads|boost log 1.54|glog   |easylogging |spdlog|
|-------|:-------:|:-----:|----------:|------:|
|1|       4.169s  |1.066s |0.975s     |0.392s|
|10|     6.180s   |3.032s |2.857s     |0.773s|
|100|     5.981s  |1.139s |4.512s     |0.587s|


#### Asynchronous mode
Time needed to log 1,000,000 lines in asynchronous mode, i.e. the time it takes to put them in the async queue (in seconds, the best of 3 runs):

|threads|g2log <sup>async logger</sup>   |spdlog <sup>async mode</sup>|
|:-------|:-----:|-------------------------:|
|1|       1.850s |0.39s |
|10|      0.943s  |0.416s|
|100|      0.959s |0.413s|
	