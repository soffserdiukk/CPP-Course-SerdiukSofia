#ifndef FIGURE3D_H
#define FIGURE3D_H

// Базовий абстрактний клас
class Figure3D {
public:
    virtual double lateralArea() const = 0;
    virtual double volume() const = 0;
    virtual int verticesCount() const = 0;
    virtual double totalArea() const = 0;
    virtual ~Figure3D() {}
};

class Parallelepiped : public Figure3D {
    double a, b, h;
public:
    Parallelepiped(double sideA, double sideB, double height);
    double lateralArea() const override;
    double volume() const override;
    int verticesCount() const override;
    double totalArea() const override;
};

class Pyramid3 : public Figure3D {
    double a, h, l;
public:
    Pyramid3(double side, double height, double apothem);
    double lateralArea() const override;
    double volume() const override;
    int verticesCount() const override;
    double totalArea() const override;
};

class Pyramid4 : public Figure3D {
    double a, h, l;
public:
    Pyramid4(double side, double height, double apothem);
    double lateralArea() const override;
    double volume() const override;
    int verticesCount() const override;
    double totalArea() const override;
};

#endif