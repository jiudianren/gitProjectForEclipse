
#docker serach  xx
���Ҿ���


# �������� ����������
Sending build context to Docker daemon  5.997MB
 
#��ε���Dockerfile 
���dockerfile��ĳһ��ʧ�ܣ�����ύһ�����õģ��ڴ�ʧ�����֮ǰ�ľ��������ľ��� ���Ϳ��Ե��Ը�dockerfile 
 


 
 
# docker hub

  login       Log in to a Docker registry
  logout      Log out from a Docker registry
docker login  
docker push    jiudianren/helloworld
docker pull   jiudianren/helloworld
 
#docker commit     
 https://www.cnblogs.com/wherein/p/6862911.html

 docker �Ե�ǰ������� ���ύ���� �� exit�������˳���ʹ��docker commit container_id  imags_id  ����ǰ�����ύΪ����

docker commit CONTAINER_ID wherein/ubuntu
docker commit CONTAINER_ID jiudianren/helloworld

#docker rmi 
ɾ������

 
# docker build   

 --no-cache 
 
    docker build  -t name  paththodockfiel 
    docker build  -t name  .
    docker build --build-arg xx=xxx 
    docker buiold -t name  git@github.com:jiudianren/Projname

#docker tag 
docker tag old  new 
docker tag jiudianren/boostdocker:latest   jiudianren/boostdocker:ok

# docker push