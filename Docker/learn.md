����һ��docker�����顷

docker run -i -t ubuntu /bin/bash

 -i stdin ����
 -t  ��һ��α�ն�
 exit
 -d �����ػ�ʽ����
 -p  �˿�ӳ��
 --name xxxx Ϊ��������
 --link  ��������
 --restart  
 �����Ѿ�ֹͣ������
 docker  start contain-id
 
 ���ŵ�����
 docker attach cid
 docker exec 
 
 docker run -d ubuntu /bin/bash "while true ; do echo hello world ; sleep 1m ; done"
 
 ���� -d���������� 
 �����Ҫ���������ڲ�������ʹ��docker exec �����µĽ���
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
 
 �������� ����������
 
 ��ε���Dockerfile �����dockerfile��ĳһ��ʧ�ܣ�����ύһ�����õģ��ڴ�ʧ�����֮ǰ�ľ��������ľ��� ���Ϳ��Ե��Ը�dockerfile 
 
 docker��ʹ��gdb����Ҫ��docker run ��������ѡ��
--security-opt seccomp=unconfined
 
 
 docker �Ե�ǰ������� ���ύ���� �� exit�������˳���ʹ��docker commit container_id  imags_id  ����ǰ�����ύΪ����
 
 docker push
 
 
 *����*  
 
 ��Ubuntu�ϰ�װDocker
 https://www.cnblogs.com/ksir16/p/6530433.html
 docker���������С��helloworld����:
 https://blog.csdn.net/u012819339/article/details/80007919