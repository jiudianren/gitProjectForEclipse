
# 标准文档
ELF(Executable and Linking Format) 
https://refspecs.linuxbase.org/elf/elf.pdf



# 可执行文件（ELF）格式的理解

https://www.cnblogs.com/xmphoenix/archive/2011/10/23/2221879.html


#
在ELF格式出来之后，TISC(Tool Interface Standard Committee)委员会定义了一套ELF标准。你可以从这里(http://refspecs.freestandards.org/elf/)找到详细的标准文档

# binutils 工具包 包括 readelf obdjump等等


# readelf



readelf -a

readelf -S 查看section 

# ar 将.o 归档为.a 
# ldd 查看链接 
# file  a.out 查看文档文档类型
# objdump 的选项 -d 表示要对由 -j 选择项指定的 section 内容进行反汇编

objdump -d -j .text ./aout
