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
    if (d == 0) throw ExeptionRational();
    denominator = d;
    simplify();
}

Rational::Rational(const Rational& other)
    : nominator(other.nominator), denominator(other.denominator) {}

void Rational::setNominator(int n) {
    nominator = n;
    simplify();
}

void Rational::setDenominator(int d) {
    if (d == 0) throw ExeptionRational();
    denominator = d;
    simplify();
}

// Оператор виведення cout <<
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.nominator << "/" << r.denominator;
    return os;
}

// Оператор введення cin >>
std::istream& operator>>(std::istream& is, Rational& r) {
    int n, d;
    is >> n >> d;
    if (d == 0) throw ExeptionRational();
    r.nominator = n;
    r.denominator = d;
    r.simplify();
    return is;
}

// Дружня функція запису у файл
void saveToFile(const Rational& r, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    file << r;
    file.close();
}

// Решта методів залишаються (toDouble, +, -, *, /)
double Rational::toDouble() const { return static_cast<double>(nominator) / denominator; }

Rational Rational::operator+(const Rational& other) const {
    return Rational(nominator * other.denominator + other.nominator * denominator, denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(nominator * other.denominator - other.nominator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(nominator * other.nominator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.nominator == 0) throw ExeptionRational("DIVISION BY ZERO");
    return Rational(nominator * other.denominator, denominator * other.nominator);
}

// Оператори порівняння
bool Rational::operator<(const Rational& other) const { return this->toDouble() < other.toDouble(); }
bool Rational::operator>(const Rational& other) const { return other < *this; }
bool Rational::operator<=(const Rational& other) const { return !(*this > other); }
bool Rational::operator>=(const Rational& other) const { return !(*this < other); }
bool Rational::operator==(const Rational& other) const {
    return nominator == other.nominator && denominator == other.denominator;
}