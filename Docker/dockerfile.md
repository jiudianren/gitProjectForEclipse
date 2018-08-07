
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
    
    



ENV REFRESH_AT XXXX_XX_XX

WORKDIR

CMD 能够被 docker命令行覆盖

ENTRYPOINT 不能被docker命令行覆盖  ，可以接受docker命令行的参数，也可以接收 CMD的参数

USER  root
USER   xxx 
VOLUE 卷


ADD   目录或者文件  tar url 
ADD  file  DestDir
COPY  file（必须是当前dockerfile路径下的文件）  DestDir（绝对路径）

ONBULID 当该镜像被用作其他的镜像的基础镜像时，被执行






    