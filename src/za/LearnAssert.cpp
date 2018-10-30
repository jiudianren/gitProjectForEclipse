// http://www.169it.com/article/11369597425660380263.html


/*

c++ assert()����ԭ�ͼ���������:
#include < assert.h>
void assert( int expression );
�� ��: ����һ������������ʹ������ֹ.

   C++ assert()�������������ּ�����ʽ expression �������ֵΪ�٣���Ϊ0����
   ��ô������stderr��ӡһ��������Ϣ��Ȼ��ͨ������ abort ����ֹ�������С�
   ʹ��C++ assert()������ȱ���ǣ�Ƶ���ĵ��ûἫ���Ӱ���������ܣ����Ӷ���Ŀ�����
   �ڵ��Խ����󣬿���ͨ���ڰ���#include < assert.h>�����֮ǰ���� #define NDEBUG ������assert���ã�ʾ���������£�


#include < stdio.h>
#define NDEBUG
#include < assert.h>


  �÷��ܽ���ע�����

1)�ں�����ʼ�����鴫������ĺϷ���.
2)ÿ��assertֻ����һ������,��Ϊͬʱ����������ʱ,�������ʧ��,�޷�ֱ�۵��ж����ĸ�����ʧ��.

����: assert(nOffset>=0 && nOffset+nSize<=m_nInfomationSize);

��: assert(nOffset >= 0);

assert(nOffset+nSize <= m_nInfomationSize);

3)����ʹ�øı价�������,��Ϊassertֻ��DEBUG����Ч,�����ô��,��ʹ�ó�������������ʱ��������

����: assert(i++ < 100)

������Ϊ�������������ִ��֮ǰi=100,��ô�������Ͳ���ִ�У���ôi++���������û��ִ�С�
��ȷ: assert(i < 100)
i++;

4)assert�ͺ�������Ӧ��һ��,���γ��߼����Ӿ��ϵ�һ�¸�

5)�еĵط�,assert���ܴ����������ˡ�
 * */

#include < stdio.h>
#include < assert.h>
#include < stdlib.h>
#include "LearnAssert.h"

int mainAssert( void )
{
    FILE *fp;
    fp = fopen( "test.txt", "w" );//�Կ�д�ķ�ʽ��һ���ļ�����������ھʹ���һ��ͬ���ļ�
    assert( fp ); //�������ﲻ�����
    fclose( fp );
    fp = fopen( "noexitfile.txt", "r" );//��ֻ���ķ�ʽ��һ���ļ�����������ھʹ��ļ�ʧ��
    assert( fp ); //�����������
    fclose( fp ); //������Զ��ִ�в���������
    return 0;
}

