
#include <iostream>
#include <functional>
#include <typeinfo>
#include <string.h>
#include "bind.h"

int add1(int i, int j, int k) {
    return i + j + k;
}


class Utils {
public:
    Utils(const char* name) {
        strcpy(_name, name);
    }

    void sayHello(const char* name) const {
        std::cout << _name << " say: hello " << name << std::endl;
    }

    static int getId() {
        return 10001;
    }

    int operator()(int i, int j, int k) const {
        return i + j + k;
    }

private:
    char _name[32];
};


/*
 *
 */
void mainBind(void)
{
    std::cout << "\n---------------------------" << std::endl;
    std::cout << "mainBind()start =================================" << std::endl;
    // ��ȫ�ֺ���
    auto add2 = std::bind(add1, std::placeholders::_1, std::placeholders::_2, 10);
    // ����add2 = ��add1����������1���䣬����2���䣬����3�̶�Ϊ10.
    std::cout << typeid(add2).name() << std::endl;
    std::cout << "add2(1,2) = " << add2(1, 2) << std::endl;

    std::cout << "\n---------------------------" << std::endl;

    // �󶨳�Ա����
    Utils utils("Vicky");
    auto sayHello = std::bind(&Utils::sayHello, utils/*������*/, std::placeholders::_1/*����1*/);
    sayHello("Jack");

    auto sayHelloToLucy = std::bind(&Utils::sayHello, utils/*������*/, "Lucy"/*�̶�����1*/);
    sayHelloToLucy();

    // �󶨾�̬��Ա����
    auto getId = std::bind(&Utils::getId);
    std::cout << getId() << std::endl;

    std::cout << "\n---------------------------" << std::endl;

    // ��operator����
    auto add100 = std::bind(&Utils::operator (), utils, std::placeholders::_1, std::placeholders::_2, 100);
    std::cout << "add100(1, 2) = " << add100(1, 2) << std::endl;

    // ע�⣺�޷�ʹ��std::bind()��һ�����غ���
    std::cout << "mainBind() end  =================================" << std::endl;
    std::cout << "\n---------------------------" << std::endl;
}

