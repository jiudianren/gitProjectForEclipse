

apt-get install  -y redis-tools
docker run -d -p 6379 --name redis jiudianren/myredis
docker port redis

#redis 容器内部直接访问
修改配置文件 docker exec -t -i redis /bin/bash 

看到 容器内的端口port0 映射到主机的端口port1
redis-cli -h 127.0.0.1  -p port1
redis-cli -h 127.0.0.1  -p port1

#容器互联方案，使用redis-server 和 redis tools
docker run -t -i  --link redis:db  --name redistools  jiudianren/redistools
cat /etc/hosts 看到db的ip 
容器内 ping db(redis在redistools里面的别名)，可以看到redis容器的ip
redis-cli -h db  -p 6379 


#容器互联方案的配置 
https://blog.csdn.net/u011072139/article/details/64922917
redis用127.0.0.1访问正常，但是用ip访问，就会报错，解决方法，修改redis.conf文件
1.bind 0.0.0.0                  设置允许访问的ip
2.requirepass 123456   设置访问密码
3.protected-mode no     关闭保护模式
然后指定默认默认配置文件启动   ./redis-server redis.conf