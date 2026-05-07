// Завдання 17.1 реалізовано в оновленому класі Rational в директорії practice_15
#include <iostream>
#include <vector>
#include "Person.h"

int main() {
    // Налаштування виводу української мови (залежить від ОС, зазвичай UTF-8)
    std::vector<Person*> people;

    int n = getSafeInt("Скільки людей ви хочете додати до списку? ", 1, 100);

    for (int i = 0; i < n; ++i) {
        std::cout << "\n--- Створення запису #" << i + 1 << " ---\n";
        std::cout << "Тип особи:\n1. Студент\n2. Викладач\n3. Аспірант\n";
        int type = getSafeInt("Ваш вибір: ", 1, 3);

        Person* p = nullptr;

        // Використовуємо try-catch для непередбачуваних помилок
        try {
            switch (type) {
                case 1: p = new Student(); break;
                case 2: p = new Teacher(); break;
                case 3: p = new Aspirant(); break;
            }

            p->input();
            people.push_back(p);
            std::cout << ">> Запис успішно додано.\n";

        } catch (const std::exception& e) {
            std::cerr << "(!) Критична помилка: " << e.what() << "\n";
            delete p;
            --i; // Повторити введення для цього номера
        }
    }

    std::cout << "Результат вашого введення:\n";

    for (Person* p : people) {
        p->output();

        // Витягуємо ВНЗ через динамічне приведення типів
        // Це доводить, що об'єкт коректно успадкував AcademicPerson
        auto academic = dynamic_cast<AcademicPerson*>(p);
        if (academic) {
            std::cout << " | Перевірка поля ВНЗ: " << academic->getUniversity();
        }
        std::cout << "\n----------------------------------------\n";
    }

    // Очищення пам'яті
    for (Person* p : people) delete p;

    return 0;
}