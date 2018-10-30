// http://www.169it.com/article/11369597425660380263.html


/*

c++ assert()函数原型及介绍如下:
#include < assert.h>
void assert( int expression );
功 能: 测试一个条件并可能使程序终止.

   C++ assert()函数的作用是现计算表达式 expression ，如果其值为假（即为0），
   那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。
   使用C++ assert()函数的缺点是，频繁的调用会极大的影响程序的性能，增加额外的开销。
   在调试结束后，可以通过在包含#include < assert.h>的语句之前插入 #define NDEBUG 来禁用assert调用，示例代码如下：


#include < stdio.h>
#define NDEBUG
#include < assert.h>


  用法总结与注意事项：

1)在函数开始处检验传入参数的合法性.
2)每个assert只检验一个条件,因为同时检验多个条件时,如果断言失败,无法直观的判断是哪个条件失败.

不好: assert(nOffset>=0 && nOffset+nSize<=m_nInfomationSize);

好: assert(nOffset >= 0);

assert(nOffset+nSize <= m_nInfomationSize);

3)不能使用改变环境的语句,因为assert只在DEBUG个生效,如果这么做,会使用程序在真正运行时遇到问题

错误: assert(i++ < 100)

这是因为如果出错，比如在执行之前i=100,那么这条语句就不会执行，那么i++这条命令就没有执行。
正确: assert(i < 100)
i++;

4)assert和后面的语句应空一行,以形成逻辑和视觉上的一致感

5)有的地方,assert不能代替条件过滤。
 * */

#include < stdio.h>
#include < assert.h>
#include < stdlib.h>
#include "LearnAssert.h"

int mainAssert( void )
{
    FILE *fp;
    fp = fopen( "test.txt", "w" );//以可写的方式打开一个文件，如果不存在就创建一个同名文件
    assert( fp ); //所以这里不会出错
    fclose( fp );
    fp = fopen( "noexitfile.txt", "r" );//以只读的方式打开一个文件，如果不存在就打开文件失败
    assert( fp ); //所以这里出错
    fclose( fp ); //程序永远都执行不到这里来
    return 0;
}

