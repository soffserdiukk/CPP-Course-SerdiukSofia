#include <iostream>
#include <stack>
#include <string>
#include "Rational.h"

namespace MyLib {

    // --- Власна реалізація шаблону Стек ---
    template <typename T>
    class Stack {
    private:
        struct Node { T data; Node* next; };
        Node* topNode = nullptr;
        size_t count = 0;

    public:
        Stack() : topNode(nullptr), count(0) {}
        ~Stack() { while (!empty()) pop(); }

        void push(const T& val) {
            topNode = new Node{val, topNode};
            count++;
        }

        void pop() {
            if (empty()) return;
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            count--;
        }

        T top() const {
            if (empty()) throw std::runtime_error("Стек порожній");
            return topNode->data;
        }

        bool empty() const { return topNode == nullptr; }
        size_t size() const { return count; }
    };

    // --- Універсальна функція введення ---
    template <typename T>
    int FillArrayUntilZero(T*& arr) {
        MyLib::Stack<T> tempStack;
        T val;

        // Динамічна підказка залежно від типу
        if constexpr (std::is_same_v<T, Rational>) {
            std::cout << "Вводьте 'чисельник знаменник' (наприклад: 1 2). Для кінця введіть '0 1':\n";
        } else {
            std::cout << "Вводьте числа по одному. Для кінця введіть '0':\n";
        }

        while (true) {
            try {
                if (!(std::cin >> val)) {
                    std::cin.clear();
                    std::string dummy;
                    std::cin >> dummy;
                    continue;
                }

                // Перевірка на нуль (працює для int та Rational)
                if (val == T(0)) break;

                tempStack.push(val);
                std::cout << "  > Додано. Елементів у стеку: " << tempStack.size() << "\n";
            } catch (const ExeptionRational& e) {
                std::cout << "  ! Помилка: " << e.what() << ". Спробуйте ще раз.\n";
            }
        }

        int n = static_cast<int>(tempStack.size());
        if (n == 0) {
            arr = nullptr;
            return 0;
        }

        arr = new T[n];
        for (int i = n - 1; i >= 0; --i) {
            arr[i] = tempStack.top();
            tempStack.pop();
        }

        return n;
    }
}

int main() {

    // 1. Тест з int
    int* intArr = nullptr;
    std::cout << "--- ТЕСТ 1: Цілі числа (int) ---\n";
    int countInt = MyLib::FillArrayUntilZero(intArr);

    std::cout << "\nРЕЗУЛЬТАТ (масив int): [ ";
    for (int i = 0; i < countInt; i++) std::cout << intArr[i] << " ";
    std::cout << "]\nКількість елементів: " << countInt << "\n\n";
    delete[] intArr;

    // 2. Тест з Rational
    Rational* ratArr = nullptr;
    std::cout << "--- ТЕСТ 2: Раціональні дроби (Rational) ---\n";
    int countRat = MyLib::FillArrayUntilZero(ratArr);

    std::cout << "\nРЕЗУЛЬТАТ (масив Rational): [ ";
    for (int i = 0; i < countRat; i++) std::cout << ratArr[i] << " ";
    std::cout << "]\nКількість елементів: " << countRat << "\n\n";
    delete[] ratArr;

    // 3. STL Перевірка
    std::cout << "--- ТЕСТ 3: Стандартний std::stack (STL) ---\n";
    std::stack<std::string> stlS;
    stlS.push("Перший");
    stlS.push("Другий");
    std::cout << "Верхній елемент STL стеку: " << stlS.top() << "\n";
    std::cout << "Роботу програми завершено успішно.\n";

    return 0;
}