#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook(const std::string& fname) : filename(fname), count(0) {}

void PhoneBook::loadFromFile() {
    std::ifstream in(filename);
    if (!in) return;
    
    count = 0;
    while (count < 100) {
        std::string n, ph;
        unsigned y;
        // Зчитуємо дані у тимчасові змінні
        if (!(in >> n >> y >> ph)) break;

        // Створюємо об'єкт через конструктор
        list[count] = Friend(n, y, ph);
        count++;
    }
    in.close();
}

void PhoneBook::saveToFile() const {
    std::ofstream out(filename);
    for (int i = 0; i < count; ++i) {
        // Використовуємо публічні методи для доступу до даних
        out << list[i].getName() << " "
            << list[i].getBYear() << " "
            << list[i].getPhone() << "\n";
    }
    out.close();
}

void PhoneBook::addFriend() {
    if (count < 100) {
        list[count].input(std::cin);
        count++;
        saveToFile();
    } else {
        std::cout << "Довідник переповнений!\n";
    }
}

void PhoneBook::findByName(const std::string& searchName) const {
    for (int i = 0; i < count; ++i) {
        if (list[i].getName() == searchName) {
            std::cout << "Знайдено: " << list[i].getPhone() << "\n";
            return;
        }
    }
    std::cout << "Контакт не знайдено.\n";
}

void PhoneBook::updatePhone(const std::string& searchName, const std::string& newPhone) {
    for (int i = 0; i < count; ++i) {
        if (list[i].getName() == searchName) {
            list[i].setPhone(newPhone);
            saveToFile();
            std::cout << "Номер оновлено.\n";
            return;
        }
    }
}

void PhoneBook::displayAll() const {
    for (int i = 0; i < count; ++i) {
        list[i].show(std::cout);
        std::cout << "\n";
    }
}