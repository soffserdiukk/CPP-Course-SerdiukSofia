#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int nominator;
    int denominator;

    int gcd(int a, int b) const; // Метод для знаходження НСД
    void simplify();             // Приватний метод для скорочення дробу

public:
    Rational(int n = 1, int d = 1); // Конструктор за замовчуванням та з параметрами
    Rational(const Rational& other); // Копі-конструктор

    // Методи ініціалізації
    void setNominator(int n);
    void setDenominator(int d); // Заборона нуля

    // Введення та виведення
    void input();
    void output() const;
    double toDouble() const;

    // Арифметичні оператори
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Оператори порівняння
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator==(const Rational& other) const;
};

#endif