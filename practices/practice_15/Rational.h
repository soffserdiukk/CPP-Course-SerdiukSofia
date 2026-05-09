#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class ExeptionRational : public std::runtime_error {
public:
    ExeptionRational(const std::string& msg = "DENOMINATOR CANT BE ZERO")
        : std::runtime_error(msg) {}
};

class Rational {
private:
    int nominator;
    int denominator;

    int gcd(int a, int b) const;
    void simplify();

public:
    Rational(int n = 1, int d = 1);
    Rational(const Rational& other);

    void setNominator(int n);
    void setDenominator(int d);

    double toDouble() const;

    // Арифметичні оператори (як члени класу)
    Rational operator+(const Rational& other) const;
    Rational operator*(const Rational& other) const;

    // Перевантаження
    Rational operator-(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Оператори порівняння
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator==(const Rational& other) const;

    // Перевантаження введення/виведення (дружні функції)
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

    // Дружня функція для запису у файл
    friend void saveToFile(const Rational& r, const std::string& filename);
};

#endif