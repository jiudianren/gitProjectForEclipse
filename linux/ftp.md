

apt-get install vsftpd

sudo apt-get install vsftpd
ftp�������ļ���

/etc/vsftpd.conf
����ʹ�������������򿪣��رգ�����ftp����

sudo /etc/init.d/vsftpd start
sudo /etc/init.d/vsftpd stop
sudo /etc/init.d/vsftpd restart
ʹ������������Կ���ϵͳ�ж���ftp�û����ftp�û�

cat /etc/group
cat /etc/passwd

-----------------------------
	�༭/etc/vsftpd.conf�ļ�:

	// ���������û���¼
	anonymous_enable=YES

	// �������û���¼
	local_enable=YES

	// ����ȫ���ϴ�
	write_enable=YES

	// ���������û��ϴ��ļ�
	anon_upload_enable=YES  

	// ���������û��½��ļ���
	anon_mkdir_write_enable=YES


----------------------------

https://www.cnblogs.com/jiqing9006/p/8955559.html


# root ftp enable

Ĭ�������vsftp�ǲ�����root�û���¼�ģ�����ͨ���޸����������������⡣
�����ҵ�vsftp������Ŀ¼
[root@localhost vsftpd]# pwd
/etc/vsftpd
[root@localhost vsftpd]# ls
chroot_list  ftpusers  user_list  vsftpd.conf  vsftpd_conf_migrate.sh
[root@localhost vsftpd]#
�޸�
[root@localhost vsftpd]# cat ftpusers
# Users that are not allowed to login via ftp
#root
bin ....
�޸�
[root@localhost vsftpd]# cat user_list

# vsftpd userlist

# If userlist_deny=NO, only allow users in this file

# If userlist_deny=YES (default), never allow users in this file, and

# do not even prompt for a password.
# Note that the default vsftpd pam config also checks /etc/vsftpd/ftpusers
# for users that are denied.
#root

bin .......

���������������Ĭ�������vsftp������ʹ�õ��˺��б����ļ���rootɾ��������ǰ��Ӹ�#�� ����һ��vsftpd ���� ����
