

apt-get install  -y redis-tools
docker run -d -p 6379 --name redis jiudiaren/myredis
docker port redis
���� �����ڵĶ˿�port0 ӳ�䵽�����Ķ˿�port1
redis-cli -h 127.0.0.1  -p port1


#��������������ʹ��redis-server �� redis tools
