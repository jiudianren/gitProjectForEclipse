/*
 * findHash.cpp
 *
 *  Created on: 2018年10月21日
 *      Author: Administrator
 */


//找出字符串中第一个只出现一次的字符
//https://blog.csdn.net/ego_bai/article/details/80461304

void findSingle( const char *arr){
    int hashtable[26] = {0};
    int i;
    int len = strlen(arr);
    for(i=0;i<len;i++)
        hashtable[arr[i]-'a']++;

    for(i=0;i<len;i++){
        if(hashtable[arr[i]-'a'] == 1){
            printf("%c\n",arr[i]);
            break;
        }
    }
    if(i >= len){
      return -1;
    }
}


//同样如果不仅线制对小写字母，各类字符都有的情况直接采用int hashtable[256] = {0};更通用



#include<iostream>
#include<string>
using namespace std;
const int Tabsize = 256;
int hashtab[Tabsize];
int main(){
    string str;
    while(cin>>str){
        bool flg = false;
        for(int i=0;i<Tabsize;++i) {
            hashtab[i]=0;
        }
        for(int i=0;i<str.size();++i){
            hashtab[str[i]]++;
        }
        for(int i=0;!flg && i<str.size();++i){
            if(hashtab[str[i]] == 1){
                cout<<str[i]<<endl;
                flg = true;
                break;
            }
        }
        if(!flg)
            cout<<'-1'<<endl;
    }
    return 0;
}

