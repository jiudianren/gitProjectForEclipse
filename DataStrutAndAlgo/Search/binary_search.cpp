
#include <string.h>
#include <assert.h>

int binary_search( const int arr[],int n,int key)
{
    assert(arr!=NULL && n>0 );//ע����Ե�����

    int left=0;
    int right=n-1;
    int mid=0;

    while(left <= right)
    {
        mid = left + ((right-left)>>1);//��ֱ����(left+right)/2�Ƿ�ֹԽ������Ч��

        if(arr[mid]<key)
            left=mid+1;
        else if(arr[mid]>key)
            right=mid-1;
        else
            return mid;
    }
    return -1;
}

