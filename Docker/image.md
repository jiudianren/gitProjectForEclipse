 
 构建环境 构建上下文
 
 如何调试Dockerfile ，如果dockerfile在某一条失败，则会提交一个可用的，在此失败语句之前的镜像，启动改镜像 ，就可以调试该dockerfile 
 
 docker中使用gdb，需要在docker run 加入如下选项
--security-opt seccomp=unconfined
 
 
 docker 以当前运行情况 ，提交镜像 ， exit从容器退出后，使用docker commit container_id  imags_id  将当前容器提交为镜像
 
 
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