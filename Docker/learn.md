����һ��docker�����顷

docker run -i -t ubuntu /bin/bash

 -i stdin ����
 -t  ��һ��α�ն�
 exit
 
 --name xxxx Ϊ��������
 
 �����Ѿ�ֹͣ������
 docker  start contain-id
 
 ���ŵ�����
 docker attach cid
 
 -d �����ػ�ʽ����
 
 docker run -d ubuntu /bin/bash "while true ; do echo hello world ; sleep 1m ; done"
 
 docker run -p 
 
 docker ps -a
 docker list
 docker logs xxxx
 docker logs -f
 docker top xxx 
 docker exec xxx �����������Ľ���
 docker stop  ֹͣĳ��docker
 docker kill 
 
 docker run --restart=xxx  
 dokcer inspect xxx �鿴������Ϣ
 docker rm 
 
 docker image rm -f myhello:2.0
 
 �������� ����������
 
 ��ε���Dockerfile �����dockerfile��ĳһ��ʧ�ܣ�����ύһ�����õģ��ڴ�ʧ�����֮ǰ�ľ��������ľ��� ���Ϳ��Ե��Ը�dockerfile 
 
 
 
 *����*  
 
 ��Ubuntu�ϰ�װDocker
 https://www.cnblogs.com/ksir16/p/6530433.html
 docker���������С��helloworld����:
 https://blog.csdn.net/u012819339/article/details/80007919