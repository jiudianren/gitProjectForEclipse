��Ubuntu�ϰ�װDocker
 https://www.cnblogs.com/ksir16/p/6530433.html
 
 �����¼���������氲װ��ʽ������ƽʱֻ������ʹ�����Բ���Ҫ��װ��ҵ�棬������˽���ҵ�氲װ��ʽ����չٷ��ĵ��� 
 
����CE����
����apt������ HTTPS��ʽ��ȡ����װ:

$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
 

���Docker�ٷ� GPG key:

$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
 

У�� 9DC8 5822 9FC7 DD38 854A E2D8 8D81 803C 0EBF CD88.

$ sudo apt-key fingerprint 0EBFCD88
 

�����������������ȶ�����
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
 

 ��װDocker
����apt������
$ sudo apt-get update
 

��װ���°�Docker
sudo apt-get install docker-ce
 

��֤Docker�Ƿ��Ѿ���װ�ɹ�
$ sudo docker run hello-world
�����������һ�����Ծ��񣬲�������һ��container�����иþ��񣬴�ӡһЩ��Ϣ���˳���

���ˣ�Docker��Ubuntu���Ѿ���װ�ɹ���