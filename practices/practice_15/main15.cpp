#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Rational.h"
#include "Point.h"
#include "Polinom.h"

// Функції-обгортки для завдань
void runRationalTask();
void runPointTask();
void runPolinomTask();

int main() {
    std::cout << std::fixed << std::setprecision(4);
    int choice;
    do {
        std::cout << "\n--- МЕНЮ ПРАКТИЧНОЇ №15 ---\n";
        std::cout << "1. Раціональні числа (мінімум та ряд)\n";
        std::cout << "2. Точки та Багатокутник (статичні члени)\n";
        std::cout << "3. Поліном (динамічна пам'ять та бінарні файли)\n";
        std::cout << "0. Вихід\nВибір: ";
        if (!(std::cin >> choice)) break;

        switch (choice) {
            case 1: runRationalTask(); break;
            case 2: runPointTask(); break;
            case 3: runPolinomTask(); break;
        }
    } while (choice != 0);
    return 0;
}

void runRationalTask() {
    // Мінімум у масиві
    std::vector<Rational> arr = { Rational(1, 2), Rational(-3, 4), Rational(5, 6), Rational(1, 10) };
    Rational minR = arr[0];
    for (const auto& r : arr) if (r < minR) minR = r;
    std::cout << "Мінімальне число: "; minR.output(); std::cout << std::endl;

    // Обчислення ряду pi^2/12
    double target = (M_PI * M_PI) / 12.0;
    double sum = 0;
    int n = 1;
    while (true) {
        double term = 1.0 / (n * n);
        sum += (n % 2 != 0) ? term : -term;
        if (std::abs(sum - target) < 0.01) break;
        n++;
    }
    std::cout << "Сума ряду: " << sum;
}

void runPointTask() {
    std::cout << "\n--- Завдання 2: Точки та Багатокутник ---\n";
    std::vector<Point> polygon;
    int choice; // Змінюємо string на int для зчитування 1 або 0

    do {
        Point p;
        p.input();
        polygon.push_back(p);

        // Оновлений текст запиту
        std::cout << "Ввести наступну вершину? (1 - так, 0 - ні): ";
        std::cin >> choice;

    } while (choice == 1); // Цикл триває, поки користувач вводить 1

    std::cout << "\nКількість вершин: " << Point::counter() << "\n";

    double perimeter = 0;
    if (polygon.size() > 1) {
        for (size_t i = 0; i < polygon.size(); ++i) {
            perimeter += polygon[i].distanceTo(polygon[(i + 1) % polygon.size()]);
        }
    }
    std::cout << "Периметр багатокутника: " << perimeter << "\n";
}

void runPolinomTask() {
    int n;
    std::cout << "Ступінь полінома N: "; std::cin >> n;
    Polinom p1(n);
    p1.fillManual();

    std::string file = "practice_15/polinom.dat";
    saveToBinary(p1, file);

    Polinom p2;
    loadFromBinary(p2, file);
    std::cout << "Завантажено з бінарного файлу: ";
    p2.output();
}