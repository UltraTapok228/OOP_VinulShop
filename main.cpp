#include <iostream>
#include <fstream>
#include <windows.h>
#include "VinylRecord.h"
#include "Customer.h"

using namespace std;

// =-=-=-=-= Добавление (полиморфизм) =-=-=-=-=
template <typename T>
void addEntity(T* entity, const char* filename) {
    entity->input();

    ofstream file(filename, ios::binary | ios::app);
    file.write((char*)entity, sizeof(T));
    file.close();

    cout << "Данные сохранены\n";
    system("pause");
}

// =-=-=-=-= Вывод =-=-=-=-=
template <typename T>
void showEntities(const char* filename) {
    system("cls");

    ifstream file(filename, ios::binary);
    T obj;

    while (file.read((char*)&obj, sizeof(obj))) {
        IDataEntity* e = &obj;
        obj.print();
    }

    file.close();
    system("pause");
}

// =-=-=-=-= Удаление =-=-=-=-=
template <typename T>
void deleteById(const char* filename) {
    system("cls");

    showEntities<T>(filename);

    int id;
    cout << "\nВведите ID: ";
    cin >> id;

    ifstream file(filename, ios::binary);
    ofstream temp("temp.bin", ios::binary);

    T obj;
    bool found = false;

    while (file.read((char*)&obj, sizeof(obj))) {
        if (obj.getId() != id)
            temp.write((char*)&obj, sizeof(obj));
        else
            found = true;
    }

    file.close();
    temp.close();

    remove(filename);
    rename("temp.bin", filename);

    cout << (found ? "Удалено\n" : "ID не найден\n");
    system("pause");
}

// =-=-=-=-= Сводка =-=-=-=-=
void showSummary() {
    system("cls");

    ifstream fileR("records.bin", ios::binary);
    VinylRecord r;

    int countR = 0, totalQ = 0;
    float totalCost = 0;

    while (fileR.read((char*)&r, sizeof(r))) {
        countR++;
        totalQ += r.getQuantity();
        totalCost += r.getPrice() * r.getQuantity();
    }
    fileR.close();

    ifstream fileC("customers.bin", ios::binary);
    Customer c;

    int countC = 0, totalP = 0;
    float totalSpent = 0;

    while (fileC.read((char*)&c, sizeof(c))) {
        countC++;
        totalP += c.getPurchasesCount();
        totalSpent += c.getTotalSpent();
    }
    fileC.close();

    cout << "=== СВОДКА ПО МАГАЗИНУ ===\n\n";

    cout << "Пластинки:\n";
    cout << "Количество: " << countR << endl;
    cout << "Всего на складе: " << totalQ << endl;
    cout << "Общая стоимость: " << totalCost << endl;

    cout << "\nКлиенты:\n";
    cout << "Количество: " << countC << endl;
    cout << "Всего покупок: " << totalP << endl;
    cout << "Общая сумма: " << totalSpent << endl;

    system("pause");
}

// ===== Меню =====
void menu() {
    cout << "====== ПластинкаSHOP ======\n";
    cout << "1 - Добавить пластинку\n";
    cout << "2 - Показать пластинки\n";
    cout << "3 - Добавить клиента\n";
    cout << "4 - Показать клиентов\n";
    cout << "5 - Удалить пластинку\n";
    cout << "6 - Удалить клиента\n";
    cout << "7 - Сводная информация\n";
    cout << "0 - Выход\n";
    cout << "Ваш выбор: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        system("cls");
        menu();
        cin >> choice;

        if (choice == 1) {
            VinylRecord* e = new VinylRecord();
            addEntity(e, "records.bin");
            delete e;
        }

        if (choice == 2) showEntities<VinylRecord>("records.bin");

        if (choice == 3) {
            Customer* e = new Customer();
            addEntity(e, "customers.bin");
            delete e;
        }

        if (choice == 4) showEntities<Customer>("customers.bin");

        if (choice == 5) deleteById<VinylRecord>("records.bin");
        if (choice == 6) deleteById<Customer>("customers.bin");

        if (choice == 7) showSummary();

    } while (choice != 0);

    return 0;
}