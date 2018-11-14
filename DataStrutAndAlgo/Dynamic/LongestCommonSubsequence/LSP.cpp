
/*
 *
 *https://blog.csdn.net/qq_31881469/article/details/77892324
找两个字符串的最长公共子串，这个子串要求在原字符串中是连续的。而最长公共子序列则并不要求连续。

cnblogs与belong，最长公共子序列为blog（cnblogs, belong），最长公共子串为lo（cnblogs, belong）

这两个问题都是用空间换空间，创建一个二维数组来记录之前的每个状态
 *
 *用i，j遍历两个子串x,y，如果两个元素相等就+1 ，不等就用上一个状态最大的元素

           1 , 0                           i=0,j=1
c[i][j] =  2 , c[i-1][j-1] +1              i,j >0 and Xi=Yj
           3 , max { c[i,j-1] c[i-1,j]}    i,j >0 and Xi != Yj
 *
 * */
#include <string.h>

/*
 * 最长公共子序列
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
 * 最长公共子串为
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
    int result = 0;     //记录最长公共子串长度
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
