/*
 * shmdata.h
 *
 *  Created on: 2016��8��9��
 *      Author: Administrator
 */

#ifndef SHM_SHMDATA_H_
#define SHM_SHMDATA_H_


#define TEXT_SZ 2048

struct shared_use_st
{
	int written;//��Ϊһ����־����0����ʾ�ɶ���0��ʾ��д
	char text[TEXT_SZ];//��¼д��Ͷ�ȡ���ı�
};


#endif /* SHM_SHMDATA_H_ */
