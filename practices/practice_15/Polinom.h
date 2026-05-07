#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <fstream>
#include <string>

class Polinom {
private:
    double* coeffs;
    int N;

public:
    Polinom(int size = 0);
    Polinom(const Polinom& other); // Копі-конструктор
    ~Polinom();                    // Деструктор

    Polinom& operator=(const Polinom& other); // Оператор присвоєння (необхідний для динамічної пам'яті)

    void setCoeff(int index, double value);
    void fillManual();
    void output() const;

    // Дружні функції для файлових операцій
    friend void saveToBinary(const Polinom& p, const std::string& filename);
    friend void loadFromBinary(Polinom& p, const std::string& filename);
};

#endif