#include <iostream>
#include <string>
#include "Rational.h"

namespace MyLib {
    // 1. Шаблонна функція для пошуку максимуму
    // Працюватиме для всіх типів, що підтримують оператор >
    template <typename T>
    T GetMax(T a, T b) {
        return (a > b) ? a : b;
    }
}

int main() {
    std::cout << "=== Перевірка шаблону GetMax ===" << std::endl;

    // Перевірка стандартних числових типів
    int i1 = 10, i2 = 25;
    std::cout << "Max int (" << i1 << ", " << i2 << "): "
              << MyLib::GetMax(i1, i2) << std::endl;

    double d1 = 45.67, d2 = 12.34;
    std::cout << "Max double (" << d1 << ", " << d2 << "): "
              << MyLib::GetMax(d1, d2) << std::endl;

    // Перевірка рядків (працює, бо std::string має operator>)
    std::string s1 = "Borodin", s2 = "FinalProjects";
    std::cout << "Max string (" << s1 << ", " << s2 << "): "
              << MyLib::GetMax(s1, s2) << std::endl;

    // Перевірка вашого класу Rational
    try {
        Rational r1(1, 2); // 0.5
        Rational r2(3, 4); // 0.75

        // Використовуємо шаблон для вашого класу
        Rational maxR = MyLib::GetMax(r1, r2);

        std::cout << "Max Rational (" << r1 << ", " << r2 << "): "
                  << maxR << std::endl;
    }
    catch (const ExeptionRational& e) {
        std::cerr << "Помилка дробу: " << e.what() << std::endl;
    }

    return 0;
}