# __attribute__ 机制详解

https://blog.csdn.net/shift_wwx/article/details/103689854


## attribute((section(“name”)))

将作用的函数或数据放入指定名为"section_name"对应的段中

  __attribute__((section(".ps_spec_data")))


##  关于__attribute__中section部分的一些了解
todo  https://blog.csdn.net/Rong_Toa/article/details/98451872
https://blog.csdn.net/sadshen/article/details/9419267  

https://blog.csdn.net/guanhuhousheng/article/details/76301829


# constructor

https://blog.csdn.net/accumla/article/details/96161462
__attribute__((constructor)) 先于main()函数调用  
 __attribute__((destructor)) 在main()函数后调用 