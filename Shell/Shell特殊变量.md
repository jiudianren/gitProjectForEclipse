https://www.cnblogs.com/davygeek/p/5670212.html

����	����
$0	��ǰ�ű����ļ���
$n	���ݸ��ű������Ĳ�����n ��һ�����֣���ʾ�ڼ������������磬��һ��������$1���ڶ���������$2��
$#	���ݸ��ű������Ĳ���������
$*	���ݸ��ű����������в�����
$@	���ݸ��ű����������в�������˫����(" ")����ʱ���� $* ���в�ͬ�����潫�ὲ����
$?	�ϸ�������˳�״̬�������ķ���ֵ��
$$	��ǰShell����ID������ Shell �ű���������Щ�ű����ڵĽ���ID��
�����в���
���нű�ʱ���ݸ��ű��Ĳ�����Ϊ�����в����������в����� $n ��ʾ�����磬$1 ��ʾ��һ��������$2 ��ʾ�ڶ����������������ơ�


�뿴����Ľű���

���ƴ���
#!/bin/bash
echo "File Name: $0"
echo "First Parameter : $1"
echo "First Parameter : $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"
���ƴ���
 

���н����

���ƴ���
$./test.sh Zara Ali
File Name : ./test.sh
First Parameter : Zara
Second Parameter : Ali
Quoted Values: Zara Ali
Quoted Values: Zara Ali
Total Number of Parameters : 2
���ƴ���
 

$* �� $@ ������
$* �� $@ ����ʾ���ݸ�������ű������в���������˫����(" ")����ʱ������"$1" "$2" �� "$n" ����ʽ������в�����

���ǵ����Ǳ�˫����(" ")����ʱ��"$*" �Ὣ���еĲ�����Ϊһ�����壬��"$1 $2 �� $n"����ʽ������в�����"$@" �Ὣ���������ֿ�����"$1" "$2" �� "$n" ����ʽ������в�����

��������ӿ�������Ŀ��� $* �� $@ ������

���ƴ���
#!/bin/bash
echo "\$*=" $*
echo "\"\$*\"=" "$*"
echo "\$@=" $@
echo "\"\$@\"=" "$@"
echo "print each param from \$*"
for var in $*
do
echo "$var"
done
echo "print each param from \$@"
for var in $@
do
echo "$var"
done
echo "print each param from \"\$*\""
for var in "$*"
do
echo "$var"
done
echo "print each param from \"\$@\""
for var in "$@"
do
echo "$var"
done
���ƴ���
 

ִ�� ./test.sh "a" "b" "c" "d"����������Ľ����

���ƴ���
$*=  a b c d
"$*"= a b c d
$@=  a b c d
"$@"= a b c d
print each param from $*
a
b
c
d
print each param from $@
a
b
c
d
print each param from "$*"
a b c d
print each param from "$@"
a
b
c
d
���ƴ���
 

�˳�״̬
$? ���Ի�ȡ��һ��������˳�״̬����ν�˳�״̬��������һ������ִ�к�ķ��ؽ����

�˳�״̬��һ�����֣�һ������£��󲿷�����ִ�гɹ��᷵�� 0��ʧ�ܷ��� 1��

������Ҳ��һЩ���������ֵ����ʾ��ͬ���͵Ĵ���

���������У�����ɹ�ִ�У�

���ƴ���
$./test.sh Zara Ali
File Name : ./test.sh
First Parameter : Zara
Second Parameter : Ali
Quoted Values: Zara Ali
Quoted Values: Zara Ali
Total Number of Parameters : 2
$echo $?
0
