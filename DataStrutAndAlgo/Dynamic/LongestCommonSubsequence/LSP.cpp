
/*
 *
 *https://blog.csdn.net/qq_31881469/article/details/77892324
�������ַ�����������Ӵ�������Ӵ�Ҫ����ԭ�ַ������������ġ���������������򲢲�Ҫ��������

cnblogs��belong�������������Ϊblog��cnblogs, belong����������Ӵ�Ϊlo��cnblogs, belong��

���������ⶼ���ÿռ任�ռ䣬����һ����ά��������¼֮ǰ��ÿ��״̬
 *
 *��i��j���������Ӵ�x,y���������Ԫ����Ⱦ�+1 �����Ⱦ�����һ��״̬����Ԫ��

           1 , 0                           i=0,j=1
c[i][j] =  2 , c[i-1][j-1] +1              i,j >0 and Xi=Yj
           3 , max { c[i,j-1] c[i-1,j]}    i,j >0 and Xi != Yj
 *
 * */
#include <string.h>

/*
 * �����������
 */
int lcs(std::string  str1, std::string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    int c[][] = new int[len1+1][len2+1];
    for (int i = 0; i <= len1; i++) {
        for( int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                c[i][j] = 0;

            } else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[len1][len2];
}




//https://www.cnblogs.com/raichen/p/5772056.html


/*
 * ������Ӵ�Ϊ
 *
 *


           1 , 0                           i=0,j=1
c[i][j] =  2 , c[i-1][j-1] +1              i,j >0 and Xi=Yj
           3 , 0                           i,j >0 and Xi != Yj
 *
 * */
 */
 int lcs2(String str1, String str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int result = 0;     //��¼������Ӵ�����
    int c[][] = new int[len1+1][len2+1];
    for (int i = 0; i <= len1; i++) {
        for( int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                c[i][j] = c[i-1][j-1] + 1;
                result = max(c[i][j], result);
            } else {
                c[i][j] = 0;
            }
        }
    }
    return result;
}
