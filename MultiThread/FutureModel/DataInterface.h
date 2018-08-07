/*
 * DataInterface.h
 *
 *  Created on: 2017Äê12ÔÂ20ÈÕ
 *      Author: Administrator
 */

#ifndef MULTITHREAD_FUTUREMODEL_DATAINTERFACE_H_
#define MULTITHREAD_FUTUREMODEL_DATAINTERFACE_H_


#include <string>

using namespace std;

/*
 * http://blog.csdn.net/lmdcszh/article/details/39696357
 * */


class Data
{
public:
     Data();
    virtual std::string  getResult()=0;
    virtual ~Data();

};

class RealData:public Data
{
public:
    RealData();
    RealData(string request);
    std::string  getResult();
    virtual ~RealData(){};
private :
    string request;
};

class FutureData:public Data
{
    // friend class RealData;
public :
    FutureData();
    FutureData(string request);

    bool IsReady();
    void setResult(string  result)
    {
        this->result =result;
        bReady = true;
    }
    string getResult();
    string getRequest(){
        return request;
    };
    virtual ~FutureData(){};
private :
    bool bReady;
    string request;
    string result;
};



#endif /* MULTITHREAD_FUTUREMODEL_DATAINTERFACE_H_ */
