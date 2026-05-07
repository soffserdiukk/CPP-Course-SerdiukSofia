#include "PhoneBook.h"
#include <iostream>

int main() {
    PhoneBook myBook("contacts.txt");
    myBook.loadFromFile();

    int choice;
    std::string name, phone;

    do {
        std::cout << "\n1. Додати\n2. Показати всіх\n3. Пошук за \n4. Змінити номер\n0. Вихід\nВаш вибір: ";
        std::cin >> choice;

        switch (choice) {
            case 1: myBook.addFriend(); break;
            case 2: myBook.displayAll(); break;
            case 3:
                std::cout << "Введіть прізвище: "; std::cin >> name;
                myBook.findByName(name);
                break;
            case 4:
                std::cout << "Введіть прізвище: "; std::cin >> name;
                std::cout << "Новий номер: "; std::cin >> phone;
                myBook.updatePhone(name, phone);
                break;
        }
    } while (choice != 0);

    return 0;
}