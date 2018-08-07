/*
 * zk_test.h
 *
 *  Created on: 2018Äê5ÔÂ7ÈÕ
 *      Author: Administrator
 */

#ifndef ZOOKEEPERLEARN_ZK_TEST_H_
#define ZOOKEEPERLEARN_ZK_TEST_H_

#include "zookeeper.h"
#include"zookeeper_log.h"

void CheckReturnFlag(int flag);

void wexists(zhandle_t *zkhandle,char *str);
#endif /* ZOOKEEPERLEARN_ZK_TEST_H_ */
