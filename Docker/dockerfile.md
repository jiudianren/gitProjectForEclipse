# 全面的 dockerfile讲解

https://blog.csdn.net/dejunyang/article/details/91450370



    #include <stdio.h>
    int main(int argc, char *argv[])
    {
        printf("hello world\n");
        return 0;
    }


mkdir build
gcc -o build/hello hello.c
 ldd hello 



touch Dockerfile

		FROM ubuntu:latest
		RUN mkdir /data
		COPY hello /data
		ENTRYPOINT ["/data/hello", "arvik"]

`docker build -t myhello:1.0 .`
`docker build -t  jiudianren/helloworld:latest  . `

jiudianren 是仓库名
helloworld 是镜像名
latest    是标签


gcc -static -o build/hello hello.c  
ldd hello 


    FROM scratch
    COPY hello /
    CMD ["/hello"]
    
    

构建：
基于最后一步成功的镜像，测试dockerfile

docker run -t -i secess_imagsId /bin/bash 



Dockerfile语法


# RUN命令有两种格式

1. RUN <command>
2. RUN ["executable", "param1", "param2"]
第一种后边直接跟shell命令
在linux操作系统上默认 /bin/sh -c
在windows操作系统上默认 cmd /S /C
第二种是类似于函数调用。
可将executable理解成为可执行文件，后面就是两个参数。


#ENV REFRESH_AT XXXX_XX_XX

WORKDIR


CMD 能够被 docker命令行覆盖

ENTRYPOINT 不能被docker命令行覆盖  ，可以接受docker命令行的参数，也可以接收 CMD的参数

USER  root
USER   xxx 
VOLUE 卷

ARGS


ADD   目录或者文件  tar url 
ADD  file  DestDir
COPY  file（必须是当前dockerfile路径下的文件）  DestDir（绝对路径）

ONBULID 当该镜像被用作其他的镜像的基础镜像时，被执行




# CMD 和 ENTERPOINT的区别
cmd 可以有多条，最后一条有作用，cmd可以被容器启动时的启动命令所代替

ENTERPINT指令不会被覆盖，docker run的指定的参数，会被附加到 enterpoint之后  


从上面的说明，我们可以看到有两个共同点：

都可以指定shell或exec函数调用的方式执行命令；
当存在多个CMD指令或ENTRYPOINT指令时，只有最后一个生效；
而它们有如下差异：

       差异1：CMD指令指定的容器启动时命令可以被docker run指定的命令覆盖，而ENTRYPOINT指令指定的命令不能被覆盖，而是将docker run指定的参数当做ENTRYPOINT指定命令的参数。

       差异2：CMD指令可以为ENTRYPOINT指令设置默认参数，而且可以被docker run指定的参数覆盖；

下面分别对上面两个差异点进行详细说明，



    
