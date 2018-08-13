
#docker serach  xx
查找镜像


# 构建环境 构建上下文
Sending build context to Docker daemon  5.997MB
 
#如何调试Dockerfile 
如果dockerfile在某一条失败，则会提交一个可用的，在此失败语句之前的镜像，启动改镜像 ，就可以调试该dockerfile 
 


 
 
# docker hub

  login       Log in to a Docker registry
  logout      Log out from a Docker registry
docker login  
docker push    jiudianren/helloworld
docker pull   jiudianren/helloworld
 
#docker commit     
 https://www.cnblogs.com/wherein/p/6862911.html

 docker 以当前运行情况 ，提交镜像 ， exit从容器退出后，使用docker commit container_id  imags_id  将当前容器提交为镜像

docker commit CONTAINER_ID wherein/ubuntu
docker commit CONTAINER_ID jiudianren/helloworld

#docker rmi 
删除镜像

 
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