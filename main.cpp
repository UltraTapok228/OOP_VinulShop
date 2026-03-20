#include <iostream>
#include <fstream>
#include <windows.h>
#include "VinylRecord.h"
#include "Customer.h"

using namespace std;

void deleteCustomerById() {
    system("cls");

    // показ клиентов перед удалением
    showCustomers();

    int id;
    cout << "\nВведите ID клиента для удаления: ";
    cin >> id;

    ifstream file("customers.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);

    Customer c;
    bool found = false;

    while (file.read((char*)&c, sizeof(c))) {
        if ()
    }
}

// ===== ФУНКЦИИ =====
void addRecord() {
    VinylRecord r;
    r.input();

    ofstream file("records.bin", ios::binary | ios::app);
    file.write((char*)&r, sizeof(r));
    file.close();

    cout << "Пластинка добавлена\n";
    system("pause");
}

void showAllRecords() {
    system("cls");

    ifstream file("records.bin", ios::binary);
    VinylRecord r;

    cout << left
        << setw(5) << "ID"
        << setw(20) << "Исполнитель"
        << setw(25) << "Альбом"
        << setw(15) << "Жанр"
        << setw(8) << "Год"
        << setw(10) << "Цена"
        << setw(10) << "Кол-во"
        << endl;

    cout << string(93, '-') << endl;

    while (file.read((char*)&r, sizeof(r))) {
        r.print();
    }

    file.close();
    system("pause");
}

void addCustomer() {
    Customer c;
    c.input();

    ofstream file("customers.bin", ios::binary | ios::app);
    file.write((char*)&c, sizeof(c));
    file.close();

    cout << "Клиент добавлен\n";
    system("pause");
}

void showCustomers() {
    system("cls");

    ifstream file("customers.bin", ios::binary);
    Customer c;

    cout << left
        << setw(5) << "ID"
        << setw(25) << "ФИО"
        << setw(10) << "Покупки"
        << setw(15) << "Сумма"
        << endl;

    cout << string(55, '-') << endl;

    while (file.read((char*)&c, sizeof(c))) {
        c.print();
    }

    file.close();
    system("pause");
}

// ===== МЕНЮ =====

void menu() {
    cout << "==== VINYL SHOP ====\n";
    cout << "1 - Добавить пластинку\n";
    cout << "2 - Показать пластинки\n";
    cout << "3 - Добавить клиента\n";
    cout << "4 - Показать клиентов\n";
    cout << "0 - Выход\n";
    cout << "Выбор: ";
}

// ===== MAIN =====

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        system("cls");
        menu();
        cin >> choice;

        if (choice == 1) addRecord();
        if (choice == 2) showAllRecords();
        if (choice == 3) addCustomer();
        if (choice == 4) showCustomers();

    } while (choice != 0);

    return 0;
}
