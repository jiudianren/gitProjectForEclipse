/*
 * Huanchongqu.cpp
 *
 *  Created on: 2017��12��28��
 *      Author: Administrator
 */


#include <iostream>
#include <stdio.h>

/*
 * ���������
 *
 * https://www.cnblogs.com/clover-toeic/p/3737011.html
 * */
void HCQ(void){
    int a, *p;
    p = (int*)((char *)&a + 12);  //��pָ��main��������fooʱ��ջ�ķ��ص�ַ����Ч��p = (int*)(&a + 3);
    *p += 12;    //�޸ĸõ�ַ��ֵ��ʹ��ָ��һ��ָ�����ʼ��ַ
}
int mainHCQ(void){
    HCQ();
    printf("First printf call\n");
    printf("Second printf call\n");
    return 0;
}
