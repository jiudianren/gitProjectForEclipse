#!/bin/bash

#�ܵ�����������ǣ���|��,�����ܴ�����ǰ��һ��ָ�������ȷ�����Ϣ��
#Ҳ���� standard output ����Ϣ��
#���� stdandard error ��Ϣû��ֱ�Ӵ���������
#Ȼ�󣬴��ݸ���һ�������Ϊ��׼������ standard input.

#https://www.cnblogs.com/pengliangcheng/p/5211786.html


#����test.sh�ļ����ݣ�ͨ���ܵ�ת����grep ��Ϊ������
cat test.sh | grep -n 'echo'


cat test.sh test1.sh | grep -n 'echo'
#cat: test1.sh: û���Ǹ��ļ���Ŀ¼
#cat test1.sh�����ڣ����������ӡ����Ļ����ȷ���ͨ���ܵ����͸�grep


cat testpipe.txt | sh testpipe.sh
 
sh testpipe.sh testpipe.txt  