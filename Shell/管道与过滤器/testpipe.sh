#!/bin/sh
  
 if [ $# -gt 0 ];then
     exec 0<$1;
#�ж��Ƿ���������ļ�����������룬�����ļ��󶨵���׼����
 fi
  
 while read line
 do
     echo $line;
 done<&0;
#ͨ����׼����ѭ����ȡ����
 exec 0&-;
#�����׼�����