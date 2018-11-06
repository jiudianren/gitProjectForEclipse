/*
 * Client.h
 *
 *  Created on: 2017Äê12ÔÂ20ÈÕ
 *      Author: Administrator
 */

#ifndef MULTITHREAD_FUTUREMODEL_CLIENT_H_
#define MULTITHREAD_FUTUREMODEL_CLIENT_H_

#include <memory>
#include "DataInterface.h"
class Client {
public :
    std::shared_ptr< FutureData> request( std::string queryStr);
};



#endif /* MULTITHREAD_FUTUREMODEL_CLIENT_H_ */
