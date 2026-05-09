#include <iostream>
#include <vector>
#include "Int24.h"

// Функція для обчислення x^n
Int24 power(Int24 x, int n) {
    Int24 res(1);
    for (int i = 0; i < n; ++i) {
        res = res * x;
    }
    return res;
}

int main() {
    try {
        // 1. Обчислення суми масиву
        int m;
        std::cout << "Введіть кількість елементів масиву (m): ";
        std::cin >> m;

        std::vector<Int24> xk;
        Int24 sum(0);

        for (int i = 0; i < m; ++i) {
            Int24 temp;
            std::cout << "Введіть x[" << i + 1 << "]: ";
            std::cin >> temp;
            xk.push_back(temp);
            sum = sum + temp;
        }
        std::cout << "Сума елементів: " << sum << std::endl;

        // 2. Обчислення x^n
        Int24 x;
        int n;
        std::cout << "\nВведіть число x для піднесення до степеня: ";
        std::cin >> x;
        std::cout << "Введіть натуральний степінь n: ";
        std::cin >> n;

        Int24 resPow = power(x, n);
        std::cout << x << "^" << n << " = " << resPow << std::endl;

    } catch (const OverflowException& e) {
        std::cerr << "\nКритична помилка: " << e.what() << std::endl;
    } catch (const DivisionByZeroException& e) {
        std::cerr << "\nКритична помилка: " << e.what() << std::endl;
    } catch (const Int24Exception& e) {
        std::cerr << "\nПомилка Int24: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\nІнша помилка: " << e.what() << std::endl;
    }

    return 0;
}