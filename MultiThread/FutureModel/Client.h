/*
 * Client.h
 *
 *  Created on: 2017��12��20��
 *      Author: Administrator
 */

#ifndef MULTITHREAD_FUTUREMODEL_CLIENT_H_
#define MULTITHREAD_FUTUREMODEL_CLIENT_H_


#include "DataInterface.h"
class Client {
public :
    Data * request( std::string queryStr);
};



#endif /* MULTITHREAD_FUTUREMODEL_CLIENT_H_ */
