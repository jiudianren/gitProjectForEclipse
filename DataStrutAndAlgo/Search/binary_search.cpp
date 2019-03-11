
#include <string.h>
#include <assert.h>

int binary_search( const int arr[],int n,int key)
{
    assert(arr!=NULL && n>0 );//注意断言的作用

    int left=0;
    int right=n-1;
    int mid=0;

    while(left <= right)
    {
        mid = left + ((right-left)>>1);//不直接用(left+right)/2是防止越界和提高效率

        if(arr[mid]<key)
            left=mid+1;
        else if(arr[mid]>key)
            right=mid-1;
        else
            return mid;
    }
    return -1;
}

