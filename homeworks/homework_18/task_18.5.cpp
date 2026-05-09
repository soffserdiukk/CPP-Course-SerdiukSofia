#include <iostream>
#include <vector>
#include "Rational.h"

namespace MyLib {

    template <typename T>
    class Array {
    private:
        T* data;
        size_t sz;

        // Допоміжний метод для злиття двох частин масиву
        static void merge(T* arr, size_t left, size_t mid, size_t right) {
            size_t n1 = mid - left + 1;
            size_t n2 = right - mid;

            T* L = new T[n1];
            T* R = new T[n2];

            for (size_t i = 0; i < n1; i++) L[i] = arr[left + i];
            for (size_t j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

            size_t i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (!(R[j] < L[i])) { // Еквівалент L[i] <= R[j]
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) arr[k++] = L[i++];
            while (j < n2) arr[k++] = R[j++];

            delete[] L;
            delete[] R;
        }

        // Рекурсивна частина Merge Sort
        static void mergeSortRecursive(T* arr, size_t left, size_t right) {
            if (left < right) {
                size_t mid = left + (right - left) / 2;
                mergeSortRecursive(arr, left, mid);
                mergeSortRecursive(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }
        }

    public:
        // Конструктор
        Array(size_t size) : sz(size) {
            data = new T[sz];
        }

        // Деструктор
        ~Array() {
            delete[] data;
        }

        // Доступ до елементів
        T& operator[](size_t index) { return data[index]; }
        size_t size() const { return sz; }

        // Статичний метод сортування (inplace)
        static void sort(T* arr, size_t size) {
            if (size > 1) {
                mergeSortRecursive(arr, 0, size - 1);
            }
        }

        // Метод сортування для екземпляра класу
        void sort() {
            sort(data, sz);
        }

        // Вивід масиву
        void print(const std::string& msg) const {
            std::cout << msg << ": ";
            for (size_t i = 0; i < sz; i++) std::cout << data[i] << " ";
            std::cout << std::endl;
        }
    };
}

int main() {
    // Тест 1: Цілі числа
    MyLib::Array<int> intArray(6);
    intArray[0] = 34; intArray[1] = 7; intArray[2] = 23;
    intArray[3] = 32; intArray[4] = 5; intArray[5] = 62;

    intArray.print("Масив int до сортування");
    intArray.sort();
    intArray.print("Масив int після Merge Sort");

    std::cout << std::endl;

    // Тест 2: Раціональні дроби (Rational)
    MyLib::Array<Rational> ratArray(4);
    ratArray[0] = Rational(1, 2); // 0.5
    ratArray[1] = Rational(1, 8); // 0.125
    ratArray[2] = Rational(3, 4); // 0.75
    ratArray[3] = Rational(1, 4); // 0.25

    ratArray.print("Масив Rational до сортування");
    // Використання статичного методу
    MyLib::Array<Rational>::sort(&ratArray[0], ratArray.size());
    ratArray.print("Масив Rational після статичного сортування");

    return 0;
}