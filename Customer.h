#pragma once
#include "IDataEntity.h"
#include <iomanip>

class Customer : public IDataEntity {
private:
    int id;
    char name[50];
    char phone[20];
    char email[50];
    int purchasesCount;
    float totalSpent;

public:
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

    void print() override {
        cout << left
            << setw(5) << id
            << setw(25) << name
            << setw(10) << purchasesCount
            << setw(15) << fixed << setprecision(2) << totalSpent
            << endl;
    }

    int getId() override {
        return id;
    }

    int getPurchasesCount() { return purchasesCount; }
    float getTotalSpent() { return totalSpent; }

    ~Customer() {
        // деструктор
        // тут история аналогична ~VinulRecord.h
    }
};