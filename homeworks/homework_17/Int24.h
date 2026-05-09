#ifndef INT24_H
#define INT24_H

#include <iostream>
#include <stdexcept>
#include <string>

// --- Класи виключень ---
class Int24Exception : public std::runtime_error {
public:
    Int24Exception(const std::string& msg) : std::runtime_error(msg) {}
};

class OverflowException : public Int24Exception {
public:
    OverflowException() : Int24Exception("Помилка: Переповнення діапазону Int24 (-2^23...+2^23-1)") {}
};

class DivisionByZeroException : public Int24Exception {
public:
    DivisionByZeroException() : Int24Exception("Помилка: Ділення на нуль!") {}
};

// --- Клас Трьохбайтне число ---
class Int24 {
private:
    int value;
    static const int MIN_VAL = -8388608; // -2^23
    static const int MAX_VAL = 8388607;  // 2^23 - 1

    void checkRange(long long val) const; // Перевірка на переповнення

public:
    Int24(long long v = 0);
    
    // Оператори
    Int24 operator+(const Int24& other) const;
    Int24 operator-(const Int24& other) const;
    Int24 operator*(const Int24& other) const;
    Int24 operator/(const Int24& other) const;

    // Введення/виведення
    friend std::ostream& operator<<(std::ostream& os, const Int24& obj);
    friend std::istream& operator>>(std::istream& is, Int24& obj);

    int getValue() const { return value; }
};

#endif