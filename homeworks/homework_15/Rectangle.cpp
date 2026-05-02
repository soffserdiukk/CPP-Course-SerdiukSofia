#include "Rectangle.h"
#include <iostream>
#include <algorithm> // Для std::min та std::max

Rectangle::Rectangle(double x, double y, double w, double h) 
    : x(x), y(y), width(w), height(h) {}

double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }

double Rectangle::getArea() const { return width * height; }
double Rectangle::getPerimeter() const { return 2 * (width + height); }

Rectangle Rectangle::intersect(const Rectangle& other) const {
    // Координати правої та нижньої меж першого прямокутника
    double right1 = x + width;
    double bottom1 = y - height;

    // Координати правої та нижньої меж другого прямокутника
    double right2 = other.x + other.width;
    double bottom2 = other.y - other.height;

    // Координати перетину
    double x_inter = std::max(x, other.x);
    double y_inter = std::min(y, other.y);
    double right_inter = std::min(right1, right2);
    double bottom_inter = std::max(bottom1, bottom2);

    double w_inter = right_inter - x_inter;
    double h_inter = y_inter - bottom_inter;

    // Перевірка на наявність перетину
    if (w_inter <= 0 || h_inter <= 0) {
        return Rectangle(-1, -1, -1, -1);
    }

    return Rectangle(x_inter, y_inter, w_inter, h_inter);
}

void Rectangle::print() const {
    if (x == -1 && width == -1) {
        std::cout << "Прямокутник порожній (перетину немає)." << std::endl;
    } else {
        std::cout << "Координати: (" << x << ", " << y << "), Ширина: " << width 
                  << ", Висота: " << height << ", Площа: " << getArea() << std::endl;
    }
}