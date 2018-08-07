
#ifndef MULTITHREAD_TASK_H_
#define MULTITHREAD_TASK_H_


#include <string>

using namespace std;
class Task {

public:
    Task(){
        this->id =0;
        this->name="no name";
        this->price = 0;
    };
    Task(const Task & ref )
    {
        this->id = ref.id;
        this->name = ref.name;
        this->price = ref.price;
    }

    int getId() {
        return id;
    }
    void setId(int id) {
       this->id =id;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
      this->name=name;
    }

    int getPrice() {
        return price;
    }

    void setPrice(int price) {
      this->price=price;
    }


private:
    int id;
    string name;
    int price;
};

#endif

