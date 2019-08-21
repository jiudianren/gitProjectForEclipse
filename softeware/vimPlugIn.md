#VIM 命令：

切换盘符号：
先执行cd f:\  
然后执行NERDTree  
cd: 改变vim的当前工作路径  
lcd： 改变当前窗口的工作路径  
pwd: 查看当前的工作路径  
set autochdir: 自动设当前编辑的文件所在目录为当前工作路径 ，这个可以加入到_vimrc文件中去  

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
  
https://www.vim.org/scripts/script.php?script_id=2288  




