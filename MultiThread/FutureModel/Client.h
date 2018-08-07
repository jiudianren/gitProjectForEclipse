/*
 * Client.h
 *
 *  Created on: 2017Äê12ÔÂ20ÈÕ
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
