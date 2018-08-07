/*
 * shmdata.h
 *
 *  Created on: 2016年8月9日
 *      Author: Administrator
 */

#ifndef SHM_SHMDATA_H_
#define SHM_SHMDATA_H_


#define TEXT_SZ 2048

struct shared_use_st
{
	int written;//作为一个标志，非0：表示可读，0表示可写
	char text[TEXT_SZ];//记录写入和读取的文本
};


#endif /* SHM_SHMDATA_H_ */
