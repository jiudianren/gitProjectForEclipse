 
 �������� ����������
 
 ��ε���Dockerfile �����dockerfile��ĳһ��ʧ�ܣ�����ύһ�����õģ��ڴ�ʧ�����֮ǰ�ľ��������ľ��� ���Ϳ��Ե��Ը�dockerfile 
 
 docker��ʹ��gdb����Ҫ��docker run ��������ѡ��
--security-opt seccomp=unconfined
 
 
 docker �Ե�ǰ������� ���ύ���� �� exit�������˳���ʹ��docker commit container_id  imags_id  ����ǰ�����ύΪ����
 
 
 #docker hub
 
 docker login  
docker push    jiudianren/helloworld
docker pull   jiudianren/helloworld
 
 # commit     
 https://www.cnblogs.com/wherein/p/6862911.html

docker commit CONTAINER_ID wherein/ubuntu
docker commit CONTAINER_ID jiudianren/helloworld


 
 # dockerfile   

    docker build  -t name  paththodockfiel
    docker build  -t name  .
    docker build --build-arg xx=xxx 
 
 docker push