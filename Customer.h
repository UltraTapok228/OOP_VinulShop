#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include "IDataEntity.h"

using namespace std;

class Customer : public IDataEntity {
private:
    int id;
    char name[50];
    char phone[20];
    char email[50];
    int purchasesCount;
    float totalSpent;

public:
    Customer() {}

    ~Customer() {
        // тут аналогично с VinylRecord
    }

    // =-=-=-=-= Ввод данных =-=-=-=-=
    void input() override {
        cout << "\nID клиента: ";
        cin >> id;
        cin.ignore();

        cout << "ФИО: ";
        cin.getline(name, 50);

        cout << "Телефон: ";
        cin.getline(phone, 20);

        cout << "Email: ";
        cin.getline(email, 50);

        cout << "Кол-во покупок: ";
        cin >> purchasesCount;

        cout << "Сумма покупок: ";
        cin >> totalSpent;
    }

    // =-=-=-=-= Красивый вывод =-=-=-=-=
    void print() override {
        cout << left
            << setw(5) << id
            << setw(25) << name
            << setw(20) << phone
            << setw(25) << email
            << setw(10) << purchasesCount
            << setw(15) << fixed << setprecision(2) << totalSpent
            << endl;
    }

    // =-=-=-=-= Геттеры =-=-=-=-=
    int getId() const { return id; }
    const char* getName() const { return name; }
    const char* getPhone() const { return phone; }
    const char* getEmail() const { return email; }
    int getPurchasesCount() const { return purchasesCount; }
    float getTotalSpent() const { return totalSpent; }

};