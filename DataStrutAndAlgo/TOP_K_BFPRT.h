/*
 * BFPRT.h
 *
 *  Created on: 2017��10��30��
 *      Author: Administrator
 */

#ifndef SRC_DATASTRUTANDALGO_BFPRT_H_
#define SRC_DATASTRUTANDALGO_BFPRT_H_

/*
 *
http://blog.csdn.net/laojiu_/article/details/54986553

*/

int InsertSort(int  array[], int left, int right);                 //�������򣬷�����λ���±�
int GetPivotIndex(int  array[], int left, int right);              //������λ������λ���±�
int Partition(int array[], int left, int right, int pivot_index);  //������λ������λ�����±���л��֣����طֽ����±�
int BFPRT(int array[], int left, int right, const int & k);        //���kС��������λ�õ��±�

int  mainTopK();
#endif /* SRC_DATASTRUTANDALGO_BFPRT_H_ */
