#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double x, y;      // Координати лівого верхнього кута
    double width, height;

public:
    // Конструктор
    Rectangle(double x = 0, double y = 0, double w = 0, double h = 0);

    // Геттери для сторін
    double getWidth() const;
    double getHeight() const;

    // Площа та периметр
    double getArea() const;
    double getPerimeter() const;

    // Перетин двох прямокутників
    Rectangle intersect(const Rectangle& other) const;

    // Вивід інформації
    void print() const;
};

#endif