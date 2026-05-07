#include "Point.h"
#include <iostream>
#include <cmath>

int Point::count = 0;

Point::Point(double x, double y) : x(x), y(y) { count++; }
Point::Point(const Point& other) : x(other.x), y(other.y) { count++; }
Point::~Point() { count--; }

int Point::counter() { return count; }

double Point::distanceTo(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

void Point::input() {
    std::cout << "Введіть x та y: ";
    std::cin >> x >> y;
}