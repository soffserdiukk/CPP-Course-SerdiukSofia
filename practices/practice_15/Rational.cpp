#include "Rational.h"
#include <cmath>

int Rational::gcd(int a, int b) const {
    return b == 0 ? std::abs(a) : gcd(b, a % b);
}

void Rational::simplify() {
    if (denominator == 0) return;
    int common = gcd(nominator, denominator);
    nominator /= common;
    denominator /= common;
    if (denominator < 0) {
        nominator = -nominator;
        denominator = -denominator;
    }
}

Rational::Rational(int n, int d) : nominator(n) {
    setDenominator(d);
}

Rational::Rational(const Rational& other)
    : nominator(other.nominator), denominator(other.denominator) {}

void Rational::setNominator(int n) {
    nominator = n;
    simplify();
}

void Rational::setDenominator(int d) {
    if (d == 0) {
        std::cerr << "Помилка: знаменник не може бути 0. Встановлено 1.\n";
        denominator = 1;
    } else {
        denominator = d;
    }
    simplify();
}

void Rational::input() {
    int n, d;
    std::cout << "Чисельник: "; std::cin >> n;
    std::cout << "Знаменник: "; std::cin >> d;
    nominator = n;
    setDenominator(d);
}

void Rational::output() const {
    std::cout << nominator << "/" << denominator;
}

double Rational::toDouble() const {
    return static_cast<double>(nominator) / denominator;
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(nominator * other.denominator + other.nominator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(nominator * other.denominator - other.nominator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(nominator * other.nominator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    return Rational(nominator * other.denominator, denominator * other.nominator);
}

bool Rational::operator<(const Rational& other) const { return this->toDouble() < other.toDouble(); }
bool Rational::operator>(const Rational& other) const { return other < *this; }
bool Rational::operator<=(const Rational& other) const { return !(*this > other); }
bool Rational::operator>=(const Rational& other) const { return !(*this < other); }
bool Rational::operator==(const Rational& other) const {
    return nominator == other.nominator && denominator == other.denominator;
}