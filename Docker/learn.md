����һ��docker�����顷

docker ����
http://www.runoob.com/docker/docker-container-connection.html

#docker run 
docker run -i -t ubuntu /bin/bash
 -i stdin ����
 -t  ��һ��α�ն�

 -d �����ػ�ʽ����
 -p  �˿�ӳ��
 --name xxxx Ϊ��������
 --link  ��������
 --restart  
 
# �����Ѿ�ֹͣ������
 docker  start contain-id
 
# ���ŵ�����
 docker attach cid
 docker exec 
 
 docker run -d ubuntu /bin/bash "while true ; do echo hello world ; sleep 1m ; done"

#docker exec 
 ���� -d����������  �����Ҫ���������ڲ�������ʹ��docker exec �����µĽ���
 ���ʱ�򣬿���ִ��docker exec -t -i container-id  /bin/bash


 docker ps -a
 docker list
 docker logs xxxx
 docker logs -f
 docker top xxx 
 docker exec xxx �����������Ľ���
 docker stop  ֹͣĳ��docker ����������SIGTERM 
 docker kill               ����������SIGKILL 
 
 docker run --restart=xxx  
 dokcer inspect xxx �鿴������Ϣ
 docker rm   
 docker image rm -f myhello:2.0

#docker��ʹ��gdb����Ҫ��docker run ��������ѡ��
--security-opt seccomp=unconfined


#docker logs

#docker stop
#dokcer kill

 
#docker inpect 
 

 *����*  
 
 ��Ubuntu�ϰ�װDocker
 https://www.cnblogs.com/ksir16/p/6530433.html
 docker���������С��helloworld����:
 https://blog.csdn.net/u012819339/article/details/80007919