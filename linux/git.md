#git

һ.��װGit

$ yum install git
��. ����SSH��Կ
 $ ssh-keygen -t rsa -C "648087012@qq.com"
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