《第一本docker入门书》

docker 命令
http://www.runoob.com/docker/docker-container-connection.html

#docker run 
docker run -i -t ubuntu /bin/bash
 -i stdin 开启
 -t  打开一个伪终端

 -d 创建守护式容器
 -p  端口映射
 --name xxxx 为容器命名
 --link  容器互联
 --restart  
 
# 启动已经停止的容器
 docker  start contain-id
 
# 附着到容器
 docker attach cid
 docker exec 
 
 docker run -d ubuntu /bin/bash "while true ; do echo hello world ; sleep 1m ; done"

#docker exec 
 对于 -d启动的容器  如果需要进入容器内部，可以使用docker exec 启动新的进程
 这个时候，可以执行docker exec -t -i container-id  /bin/bash


 docker ps -a
 docker list
 docker logs xxxx
 docker logs -f
 docker top xxx 
 docker exec xxx 容器内起额外的进程
 docker stop  停止某个docker 向容器发送SIGTERM 
 docker kill               向容器发送SIGKILL 
 
 docker run --restart=xxx  
 dokcer inspect xxx 查看容器信息
 docker rm   
 docker image rm -f myhello:2.0

#docker中使用gdb，需要在docker run 加入如下选项
--security-opt seccomp=unconfined


#docker logs

#docker stop
#dokcer kill

 
#docker inpect 
 

 *文章*  
 
 在Ubuntu上安装Docker
 https://www.cnblogs.com/ksir16/p/6530433.html
 docker建立最简单最小的helloworld镜像:
 https://blog.csdn.net/u012819339/article/details/80007919