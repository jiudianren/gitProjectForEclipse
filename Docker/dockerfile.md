
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

jiudianren �ǲֿ���
helloworld �Ǿ�����
latest    �Ǳ�ǩ


gcc -static -o build/hello hello.c  
ldd hello 


    FROM scratch
    COPY hello /
    CMD ["/hello"]
    
    



ENV REFRESH_AT XXXX_XX_XX

WORKDIR

CMD �ܹ��� docker�����и���

ENTRYPOINT ���ܱ�docker�����и���  �����Խ���docker�����еĲ�����Ҳ���Խ��� CMD�Ĳ���

USER  root
USER   xxx 
VOLUE ��


ADD   Ŀ¼�����ļ�  tar url 
ADD  file  DestDir
COPY  file�������ǵ�ǰdockerfile·���µ��ļ���  DestDir������·����

ONBULID ���þ������������ľ���Ļ�������ʱ����ִ��






    