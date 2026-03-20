#pragma once
#include <iostream>

using namespace std;

//абстрактный класс (интерфейс)
class IDataEntity {
public:
	virtual void input() = 0; //ввод данных
	virtual void print() = 0; //ввод данных

};