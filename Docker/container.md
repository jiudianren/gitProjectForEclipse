容器：
# 容器重命名：
docker 原容器名 新容器名
##  删除容器
删除：docker rm CONTAINERID


## 查看容器
docker ps -a
docker ps  正在运行
### 停止容器
docker stop

 docker stop $(docker ps -a -q) //  stop停止所有容器 
## 删除容器
docker rm 
 docker rm $(docker ps -a -q) //   remove删除所有容器

## 重启容器
docker restart 容器ID
## 进入容器
docker attach 容器ID
docker exec -it 容器ID /bin/bash 
docker exec -it vscode /bin/bash

## 保存容器修改
进入容器后，就可以修改镜像了，比如修改镜像中已经部署的代码或者安装新的软件或包等，修改完成之后，exit 退出容器

docker commit 3bd0eef03413  demo：v1.3  提交你刚才修改的镜像，新的镜像名称为demo，版本为v1.1


## docker run 参数
####  -v 本地目录：容器内目录
#### -p  本地端口：容器内端口
###  -i
### -t
### 
### --restart

使用 容器启动参数
--restart=always 
启动run的时候加上这个参数，总是启动
--restart=on-failure:10
如上是10次
还可以设置重启最大次数

–restart具体参数值详细信息：

       no -  容器退出时，不重启容器；
       on-failure - 只有在非0状态退出时才从新启动容器；
       always - 无论退出状态是如何，都重启容器；
## docker run
卷
docker run  -v /usr/ToolsAPIDir:/ToolsAPIDir1
-v 本地目录:容器目录。挂载主机的本地目录 /usr/ToolsAPIDir 目录到容器的/ToolsAPIDir1 目录，本地目录的路径必须是绝对路径
进入退出容器
https://www.cnblogs.com/defineconst/p/10035529.html
日志
docker logs -f  container_name

进程
docker top container_name