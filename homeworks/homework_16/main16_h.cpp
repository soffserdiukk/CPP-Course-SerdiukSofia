#include <iostream>
#include <vector>
#include <iomanip>
#include "Figure3D.h"

int main() {
    // Створення масиву (вектора) фігур
    std::vector<Figure3D*> figures;

    figures.push_back(new Parallelepiped(2, 3, 4));
    figures.push_back(new Pyramid3(3, 5, 4));
    figures.push_back(new Pyramid4(4, 6, 5));

    double totalVolume = 0;
    double totalAreaAll = 0;
    int totalVertices = 0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--- Розрахунок параметрів фігур ---" << std::endl;

    for (const auto& f : figures) {
        totalVolume += f->volume();
        totalAreaAll += f->totalArea();
        totalVertices += f->verticesCount();
    }

    std::cout << "Сумарний об'єм: " << totalVolume << std::endl;
    std::cout << "Сумарна площа всіх граней: " << totalAreaAll << std::endl;
    std::cout << "Загальна кількість вершин: " << totalVertices << std::endl;

    // Очищення динамічної пам'яті
    for (auto f : figures) {
        delete f;
    }

    return 0;
}