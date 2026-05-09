#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

namespace MyLib {

    template <typename T>
    class CustomString {
    private:
        std::vector<T> elements;
        T delimiter;

    public:
        // Конструктор
        CustomString(T delim = T()) : delimiter(delim) {}

        // Введення та заміна роздільника
        void setDelimiter(T delim) { delimiter = delim; }

        // Довжина рядка (кількість елементів)
        size_t length() const { return elements.size(); }

        // Доступ за індексом
        T& operator[](size_t index) {
            if (index >= elements.size()) throw std::out_of_range("Індекс поза межами");
            return elements[index];
        }

        // Видалення символу за індексом
        void remove(size_t index) {
            if (index >= elements.size()) throw std::out_of_range("Неможливо видалити: індекс поза межами");
            elements.erase(elements.begin() + index);
        }

        // Конкатенація (додавання іншого рядка через роздільник)
        void concat(const CustomString<T>& other) {
            if (other.elements.empty()) return;
            // Якщо поточний рядок не порожній, можна було б логічно додати роздільник,
            // але зазвичай конкатенація просто зливає масиви елементів.
            for (const auto& el : other.elements) {
                elements.push_back(el);
            }
        }

        // Злиття масиву символів у один символ (додавання в кінець)
        void mergeFromVector(const std::vector<T>& vec) {
            for (const auto& el : vec) {
                elements.push_back(el);
            }
        }

        // Введення з консолі (кількість та елементи)
        friend std::istream& operator>>(std::istream& is, CustomString<T>& cs) {
            size_t n;
            std::cout << "Кількість елементів для вводу: ";
            if (!(is >> n)) throw std::runtime_error("Помилка вводу кількості");

            cs.elements.clear();
            for (size_t i = 0; i < n; ++i) {
                T temp;
                std::cout << "Елемент [" << i << "]: ";
                if (!(is >> temp)) throw std::runtime_error("Некоректний тип елемента");
                cs.elements.push_back(temp);
            }
            return is;
        }

        // Виведення в консоль (через роздільник)
        friend std::ostream& operator<<(std::ostream& os, const CustomString<T>& cs) {
            for (size_t i = 0; i < cs.elements.size(); ++i) {
                os << cs.elements[i];
                if (i < cs.elements.size() - 1) os << cs.delimiter;
            }
            return os;
        }

        // Робота з файлами
        void saveToFile(const std::string& filename) const {
            std::ofstream ofs(filename);
            if (!ofs) throw std::runtime_error("Не вдалося відкрити файл для запису");
            ofs << *this;
            ofs.close();
        }

        void loadFromFile(const std::string& filename) {
            std::ifstream ifs(filename);
            if (!ifs) throw std::runtime_error("Не вдалося відкрити файл для читання");
            T temp;
            elements.clear();
            while (ifs >> temp) {
                elements.push_back(temp);
            }
        }
    };
}

int main() {
    try {
        // Тест з типом string (де символ - це слово, а роздільник - кома)
        MyLib::CustomString<std::string> myStr(", ");

        std::cout << "--- Тест рядка з елементів-рядків ---\n";
        std::cin >> myStr;

        std::cout << "\nВаш рядок: " << myStr << std::endl;
        std::cout << "Довжина: " << myStr.length() << std::endl;

        if (myStr.length() > 0) {
            std::cout << "Видаляємо перший елемент...\n";
            myStr.remove(0);
        }

        std::cout << "Результат: " << myStr << std::endl;

        // Збереження у файл
        myStr.saveToFile("custom_string.txt");
        std::cout << "Дані збережено у custom_string.txt\n";

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}