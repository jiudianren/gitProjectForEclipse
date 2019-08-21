#VIM 命令：

切换盘符号：
先执行cd f:\  
然后执行NERDTree  
cd: 改变vim的当前工作路径  
lcd： 改变当前窗口的工作路径  
pwd: 查看当前的工作路径  
set autochdir: 自动设当前编辑的文件所在目录为当前工作路径 ，这个可以加入到_vimrc文件中去  
## 多窗口切换
2.在窗格间切换的方法
Ctrl+w+方向键——切换到前／下／上／后一个窗格
Ctrl+w+h/j/k/l ——同上
Ctrl+ww——依次向后切换到下一个窗格中


# VIM 插件

## Visual Mark 
https://www.vim.org/scripts/script.php?script_id=1026
快速标记行 mm


##mark   https://www.vim.org/scripts/script.php?script_id=1238
全文标记文字


## NERDTree 显示树形目录插件() 使用4.2.0版本：
https://www.vim.org/scripts/script.php?script_id=1658
windows: https://www.cnblogs.com/openusb/archive/2012/12/13/2815896.html
https://www.cnblogs.com/wangkongming/p/4050833.html

http://www.blogdaren.com/post-2390.html
# 常用的 命令：
:NERDTree 打开
？ 查看帮助
当前页面 :q 退出
:NERDTree D:\



##CtrIP
ctrlp和ctrlp的插件ctrlp-funky是一套强大的文本搜索系统。
它可以提供文件、buffer和内容中查找的功能

##taglist  
https://www.cnblogs.com/loveyakamoz/p/3472205.html

## ctags  
下载附件中的文件ctags.ex ，并将其 解压到目录中取。解压之后的目录是CTAGS_PATH（例如D:\Program Files\ctags58）。
并把%CTAGS_PATH%加到环境变量PATH的后面。

###  ctags -R 生成tag

###  Vim + ctags 配置
实现vim对tags的自动递归查找其实很简单, 因为vim已经实现了这个功能, 只是默认没有开启. 在vimrc添加下面两行配置, 就会是见证奇迹的时刻:

　　set autochdir
　　set tags=tags;

　　set autochdir表示自动切换目录的意思, set tags=tags;表示自动查找, 这两句同时设置vim即可实现递归的tags查找, 注意: set tags=tags;这一句的最后有一个分号, 这个分号是不能省略的. vim的配置文件使用的是vim自己的脚步语言. 这里是少数几个在行尾需要使用分号的地方之一.
  
  2、ctags能定位什么内容
1) 用#define定义的宏
2) 枚举类型变量的值
3) 函数的定义、原型和声明
4) 名字空间(namespace)
5) 类型定义(typedef)
6) 变量(包括定义和声明)
7) 类、结构体、枚举类型、联合
8) 类、结构体和联合中成员变量或函数

3、安装ctags
如果是redhat或centos系统可以直接使用yum在线安装

[root@localhost ~]# yum install ctags
源码位置生成tags文件

[root@localhost ~]# ctags -R *
4、查找操作(3种使用方式)
1)直接在命令行上操作

[root@localhost ~]# vim -t main
[root@localhost ~]# vim -t pos_create_task
结果：直接打开对应符号对应文件，并定位到该符号的定义位置。常用在知道符号，但不知道在哪个文件模块中的位置。

2)在vim的模式下使用": ta"命令

:ta main
:ta pos_create_task
3)在光标指定位置下直接使用"ctrl + ]"
在光标指定的位置下直接使用 "crtl + ]" 就可以定位到函数的定义位置；使用 "ctrl + t" 快捷键返回到上次跳转之前的位置。

关于ctags的用法很多，以下是我们列举的部分：
-->"ctrl + t"退回到原来的地方
-->"[{"转到上一个位于第一列的"{"
-->"}]"转到下一个位于第一列的"{" /* 似乎不管用 */
-->"{"转到上一个空行
-->"}"转到下一个空行
-->"gd"转到当前光标所指的局部变量的定义
-->"*"转到当前光标所指的单词一次出现的地方
-->"#"转到当前光标所指的单词上一次出现的地方


https://www.cnblogs.com/chenliyang/p/6634679.html
  
https://www.vim.org/scripts/script.php?script_id=2288  




