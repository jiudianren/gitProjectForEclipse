/*
 * MergerSort.cpp
 *
 *  Created on: 2017��10��30��
 *      Author: Administrator
 */



/*�鲢����
 *
 * �ȹ� ��
 * ��
 * ���磬�������ֳ� �����룬ÿһ��������Ȼ�����������룬�ϲ���һ����˳�������
 *
 * */

#include <iostream>

void Merge(int r[],int r1[],int s,int m,int t){

    std::cout<<"s:"<<s<<"m"<<m<<"t"<<t<<std::endl;
    int i=s;
    int j=m+1;
    int k=s;
    while(i<=m&&j<=t){
        if(r[i]<=r[j])
            r1[k++]=r[i++];
        else
            r1[k++]=r[j++];
    }
    //����֮������һ�룬����ʣ����
    if(i<=m)
        while(i<=m)
            r1[k++]=r[i++];
    else
        while(j<=t)
            r1[k++]=r[j++];
    for(int n=s;n<=t;n++)
        r[n]=r1[n];
}

void MergeSort(int r[],int r1[],int s,int t){

    if(s<t){
        int m=s+(t-s)>>1;
        MergeSort(r,r1,s,m);
        MergeSort(r,r1,m+1,t);
        Merge(r,r1,s,m,t);
    }
}
void mainMergSort(){
    int r[8]={10,3,5,1,9,34,54,565},r1[8];
    MergeSort(r,r1,0,7);
    std::cout<<"mainMergSort===============start" <<std::endl;
    for(int q=0;q<8;q++)
        std::cout<<","<<r[q];
    std::cout<<" " <<std::endl;
    std::cout<<"mainMergSort===============end" <<std::endl;
}
