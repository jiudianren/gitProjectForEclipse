/*
 * RandomArray.cpp
 *
 *  Created on: 2019��3��18��
 *      Author: lian.pengfei
 */




//��ν�һ�������������

/*
��Ŀ����ν�һ������������ң�
����һ��
ֱ�����뵽һ���㷨��ѭ���������飬ÿһ�β���һ�������С������������±����ڵ�λ���Ƴ�ȥ��Ȼ�����ֵ�浽����һ���µ������ֱ�������һ��Ԫ��Ϊֹ�����������ȡ����������ɵ������������
���㷨α���룺
����������һ��ʱ�临�Ӷ���O(N^2) �������ռ�N;
*/


void method1(vector<int> a)
{
    int j=0;
    int size = a.size();
    for(int i=0;i < size ;i++)
        auto index = rand() % size - 1;
        b[j++]=a[index];
        for(k=index;k < size-1;k++)
            a[k]=a[k+1];
        size--;

}


/*
��������
Fisher and Yates�� �����ʱ�临�Ӷ�O(N)�������ռ�1������������㷨�����㷨α�������£�
*/

void method2()
{
    for(i=n-1;i>=0;i--)
        index= rand(i+1)%i+1  //generate random index 0<=index<=i
        if(i != index)
            exchange(i,index)
}
