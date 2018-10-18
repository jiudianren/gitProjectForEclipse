#include "InsertSort.h"

void InsertSort(int arr[],int n){
    for (int i =1;i <= n;++i){
        for(int j = i;j > 0;--j){
            if(arr[j] < arr[j -1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}


void InsertSort2(std::vector<int> &num){
    for(int i = 1;i < num.size();++i){
        for(int j = i;j > 0;--j){
            if(num[j] < num[j - 1]){
                int temp = num[j];
                num[j] = num[j-1];
                num[j-1] = temp;
            }
        }
    }
}
