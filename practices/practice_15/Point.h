#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;
    static int count; // Статичний лічильник об'єктів

public:
    Point(double x = 0, double y = 0);
    Point(const Point& other);
    ~Point();

    static int counter(); // Статичний метод доступу
    double distanceTo(const Point& other) const;
    void input();
};

#endif