
centos minimal

# ssh����
ps -aux|grep sshd


#��������
vmѡ���������� VMnet8 
�������ǵ�¼����ϵͳ �û���root ���� 123456
Ȼ����������ip��ѯ���� ip addr
����ens33 û��inet ������ԣ���ô��û��ͨ��IP��ַ�����������

�������鿴ens33���������ã�vi /etc/sysconfig/network-scripts/ifcfg-ens33 ע��vi����ӿո�
�������嵥�п��Է��� CentOS 7 Ĭ���ǲ����������ģ�ONBOOT=no����

����һ���ΪYES��ONBOOT=yes��

Ȼ������������� sudo service network restart

[root@promote ~]# ip addr
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: ens33: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether 00:0c:29:11:d5:7b brd ff:ff:ff:ff:ff:ff
    inet 192.168.56.130/24 brd 192.168.56.255 scope global noprefixroute dynamic ens33
       valid_lft 1542sec preferred_lft 1542sec
    inet6 fe80::6f84:f63d:48b3:eeec/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
[root@promote ~]# 

192.168.56.130 ����ip��
# vi /etc/sysconfig/network-script/ifcfg-  ֮��tab�Զ����� �޸Ķ�Ӧ�������ļ�

����Ϊ�Զ���ȡip��ַ

ONBOOT=yes
MM_Controlled=no   �ҵ�û���������
BOOTPROTO=dhcp

��������������
service network restart
�����Ƿ������������
ping www.ahomepage.net

##ftp

## root e


## docker ��װ
yum install -y docker
yum serach docker
which docker

## cmake 
yum install cmake


##gcc g++ gdb

ʹ��yum��װgcc��yum install gcc
ʹ��yum��װg++��yum install gcc-c++   
����һ��ʹ��yum��װ��yum install gdb



#��������
setterm -foreground green
setterm -store

#git

һ.��װGit

$ yum install git
��. ����SSH��Կ
 $ ssh-keygen -t rsa -C ��your email address��
������3���س�������Ĭ��Ϊ�գ����õ� id_rsa �� id_rsa.pub �ļ�����/root/.ssh ��˵�����ɳɹ�

��.�����Կ��Github
�� Github����¼�Լ����˺ź�
����Լ���ͷ��->settings->SSH And GPG Keys->New SSH key
������ id_rsa.pub �е�����ճ���� Key �ı����У���������һ�� title(��Ҫ������)����� Add Key ����

��.����
��������������

$ ssh git@github.com
���������ѯ�ʣ�
Are you sure you want to continue connecting (yes/no)?
����yes��س����������
Hi xxx! You��ve successfully authenticated, but GitHub does not provide shell accessConnection to github.com closed.
��˵����֤�ɹ���������������������е����м��������ˣ�����������
