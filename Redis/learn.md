

apt-get install  -y redis-tools
docker run -d -p 6379 --name redis jiudiaren/myredis
docker port redis
看到 容器内的端口port0 映射到主机的端口port1
redis-cli -h 127.0.0.1  -p port1


#容器互联方案，使用redis-server 和 redis tools
