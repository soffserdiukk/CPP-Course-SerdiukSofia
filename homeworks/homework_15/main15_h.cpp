#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle r1(0, 5, 10, 5);
    Rectangle r2(5, 7, 10, 5);

    std::cout << "Прямокутник 1: "; r1.print();
    std::cout << "Прямокутник 2: "; r2.print();

    Rectangle result = r1.intersect(r2);

    std::cout << "\nРезультат перетину: ";
    result.print();

    return 0;
}