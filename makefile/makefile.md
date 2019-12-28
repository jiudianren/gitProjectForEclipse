Makefile中.PHONY的作用

https://blog.csdn.net/derkampf/article/details/70256891


addprefix
https://blog.csdn.net/runfarther/article/details/50039023

给一个或者一组字符串增加前缀





# 特殊符号

Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是：

$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件

##

Makefile中include、-include、sinclude的区别
https://blog.csdn.net/iot_ai/article/details/68059586


# makefile 内置函数
调用内置函数


## dir
$(dir $(_OUT_OBJ))

取目录函数——dir
解释： 从文件名序列<names>中取出目录部分。目录部分是指最后一个反斜杠（“/”）之前的部分
示例： $(dir src/foo.c hacks)返回值是“src/, ./”。