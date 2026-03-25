#pragma once
#include "IDataEntity.h"
#include <iomanip>

class VinylRecord : public IDataEntity {
private:
    int id;
    char artist[50];
    char album[50];
    char genre[30];
    int year;
    float price;
    int quantity;

public:
    void input() override {
        cout << "\nID: ";
        cin >> id;
        cin.ignore();

        cout << "Исполнитель: ";
        cin.getline(artist, 50);

        cout << "Альбом: ";
        cin.getline(album, 50);

        cout << "Жанр: ";
        cin.getline(genre, 30);

        cout << "Год: ";
        cin >> year;

        cout << "Цена: ";
        cin >> price;

        cout << "Количество: ";
        cin >> quantity;
    }
    
    // красивый вывод информации о товаре
    void print() override {
        cout << left
            << setw(5) << id
            << setw(20) << artist
            << setw(25) << album
            << setw(15) << genre
            << setw(8) << year
            << setw(10) << fixed << setprecision(2) << price
            << setw(10) << quantity
            << endl;
    }

    int getId() override {
        return id;
    }

    float getPrice() { return price; }
    int getQuantity() { return quantity; }

    ~VinylRecord() {
        // деструктор
        // Почему пустой? У нас в классах обычные типы 
        // или же статические массивы
        // поэтому они автоматом очищаются сами
        // тоесть он пустой потому что нет динамической памяти
    }
};