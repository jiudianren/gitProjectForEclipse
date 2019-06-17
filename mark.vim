

https://www.vim.org/scripts/script.php?script_id=1238

https://www.vim.org/scripts/script.php?script_id=2666

https://www.cnblogs.com/heartchord/p/4857451.html

Mark高亮插件
• 插件简介
       Mark是一款vim文本高亮插件，它可以同时用不同颜色来高亮不同的文本。例如，你在阅读一段很长的代码时，可以高亮其中一些关键变量来帮助理解，同时也使得追踪源码也将变得更加容易。

• 插件安装
       ▶ 下载Mark.vim，下载地址：http://www.vim.org/scripts/script.php?script_id=1238；

       ▶  存放路径，在Windows系统下路径为：vim安装路径\vimXX\plugin\，在Linux系统下安装路径为：/usr/share/vim/vimXX/plugin/；

       ▶  将下载的Mark.vim文件拷贝到存放路径下的plugin目录。

• 插件快捷键
       【普通模式（normal mode）】

       • \m : 高亮或取消高亮鼠标当前所在的单词。将鼠标放置在待高亮的单词上，按下\m后单词将被高亮。
       • \r   : 手工输入正则表达式，高亮正则表达式匹配的单词。使用时先输入\r，再输入正则表达式。
       • \n  : 取消鼠标所在单词的高亮或取消所有高亮单词的高亮显示。

       【可视模式（visual  mode）】

       • \m : 高亮或者取消高亮选中的文本段。
       • \r   : 在选中的文本中手工输入正则表达式，高亮正则表达式匹配的文本。

• 插件命令
       【命令模式（command mode）】

       • :Mark regexp : 高亮正则表达式。
       • :Mark regexp : 取消正则表达式高亮。
       • :Mark              : 取消所有高亮。
