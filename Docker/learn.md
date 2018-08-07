《第一本docker入门书》

docker run -i -t ubuntu /bin/bash

 -i stdin 开启
 -t  打开一个伪终端
 exit
 
 --name xxxx 为容器命名
 
 启动已经停止的容器
 docker  start contain-id
 
 附着到容器
 docker attach cid
 
 -d 创建守护式容器
 
 docker run -d ubuntu /bin/bash "while true ; do echo hello world ; sleep 1m ; done"
 
 docker run -p 
 
 docker ps -a
 docker list
 docker logs xxxx
 docker logs -f
 docker top xxx 
 docker exec xxx 容器内起额外的进程
 docker stop  停止某个docker
 docker kill 
 
 docker run --restart=xxx  
 dokcer inspect xxx 查看容器信息
 docker rm 
 
 docker image rm -f myhello:2.0
 
 构建环境 构建上下文
 
 如何调试Dockerfile ，如果dockerfile在某一条失败，则会提交一个可用的，在此失败语句之前的镜像，启动改镜像 ，就可以调试该dockerfile 
 
 
 
 *文章*  
 
 在Ubuntu上安装Docker
 https://www.cnblogs.com/ksir16/p/6530433.html
 docker建立最简单最小的helloworld镜像:
 https://blog.csdn.net/u012819339/article/details/80007919