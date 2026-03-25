#pragma once
#include <iostream>
using namespace std;

// абстрактный класс
class IDataEntity {
public:
    virtual void input() = 0;
    virtual void print() = 0;
    virtual int getId() = 0;

    virtual ~IDataEntity() {
        // виртуальный деструктор
        // почему виртуальный?
        // что бы корректно удалять объекты наследников
        // через указатель на базовый класс, тоесть это полиморфизм 
    }
};