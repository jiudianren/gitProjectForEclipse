

apt-get install  -y redis-tools
docker run -d -p 6379 --name redis jiudianren/myredis
docker port redis

#redis �����ڲ�ֱ�ӷ���
�޸������ļ� docker exec -t -i redis /bin/bash 

���� �����ڵĶ˿�port0 ӳ�䵽�����Ķ˿�port1
redis-cli -h 127.0.0.1  -p port1
redis-cli -h 127.0.0.1  -p port1

#��������������ʹ��redis-server �� redis tools
docker run -t -i  --link redis:db  --name redistools  jiudianren/redistools
cat /etc/hosts ����db��ip 
������ ping db(redis��redistools����ı���)�����Կ���redis������ip
redis-cli -h db  -p 6379 


#������������������ 
https://blog.csdn.net/u011072139/article/details/64922917
redis��127.0.0.1����������������ip���ʣ��ͻᱨ������������޸�redis.conf�ļ�
1.bind 0.0.0.0                  ����������ʵ�ip
2.requirepass 123456   ���÷�������
3.protected-mode no     �رձ���ģʽ
Ȼ��ָ��Ĭ��Ĭ�������ļ�����   ./redis-server redis.conf