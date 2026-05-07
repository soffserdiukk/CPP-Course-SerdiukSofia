#include "Figure3D.h"
#include <cmath>

// Parallelepiped
Parallelepiped::Parallelepiped(double sideA, double sideB, double height)
    : a(sideA), b(sideB), h(height) {}

double Parallelepiped::lateralArea() const { return 2 * h * (a + b); }
double Parallelepiped::volume() const { return a * b * h; }
int Parallelepiped::verticesCount() const { return 8; }
double Parallelepiped::totalArea() const { return lateralArea() + 2 * a * b; }

// Pyramid3 (Трикутна)
Pyramid3::Pyramid3(double side, double height, double apothem)
    : a(side), h(height), l(apothem) {}

double Pyramid3::lateralArea() const { return 1.5 * a * l; }
double Pyramid3::volume() const { return (std::sqrt(3) / 12) * a * a * h; }
int Pyramid3::verticesCount() const { return 4; }
double Pyramid3::totalArea() const { return lateralArea() + (std::sqrt(3) / 4) * a * a; }

// Pyramid4 (Чотирикутна)
Pyramid4::Pyramid4(double side, double height, double apothem)
    : a(side), h(height), l(apothem) {}

double Pyramid4::lateralArea() const { return 2 * a * l; }
double Pyramid4::volume() const { return (1.0 / 3.0) * a * a * h; }
int Pyramid4::verticesCount() const { return 5; }
double Pyramid4::totalArea() const { return lateralArea() + a * a; }