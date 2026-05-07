#include "Person.h"
#include <limits>
#include <iomanip>

int getSafeInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) return value;
        std::cout << "(!) Помилка: введіть число від " << min << " до " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Конструктори
Person::Person(std::string name, std::string g, int a) : fullName(name), gender(g), age(a) {}

AcademicPerson::AcademicPerson(std::string name, std::string g, int a, std::string uni)
    : Person(name, g, a), university(uni) {}

Student::Student(std::string name, std::string g, int a, std::string uni, int c, std::string gr)
    : Person(name, g, a), AcademicPerson(name, g, a, uni), course(c), group(gr) {}

Teacher::Teacher(std::string name, std::string g, int a, std::string uni, std::string pos, double sal)
    : Person(name, g, a), AcademicPerson(name, g, a, uni), position(pos), salary(sal) {}

Aspirant::Aspirant(std::string name, std::string g, int a, std::string uni)
    : Person(name, g, a), AcademicPerson(name, g, a, uni), Student(name, g, a, uni), Teacher(name, g, a, uni) {}

// Методи введення
void Person::input() {
    std::cout << "Введіть ПІБ: "; std::getline(std::cin >> std::ws, fullName);
    int g = getSafeInt("Стать (1-Ч, 2-Ж): ", 1, 2);
    gender = (g == 1) ? "Чоловіча" : "Жіноча";
    age = getSafeInt("Вік (0-120): ", 0, 120);
}

void AcademicPerson::input() {
    Person::input();
    std::cout << "ВНЗ: "; std::getline(std::cin >> std::ws, university);
}

void Student::input() {
    AcademicPerson::input();
    course = getSafeInt("Курс (1-6): ", 1, 6);
    std::cout << "Група: "; std::getline(std::cin >> std::ws, group);
}

void Teacher::input() {
    AcademicPerson::input();
    std::cout << "Посада: "; std::getline(std::cin >> std::ws, position);
    std::cout << "Зарплата: "; std::cin >> salary;
}

void Aspirant::input() {
    Student::input();
    std::cout << "--- Дані викладача для аспіранта ---\n";
    std::cout << "Наукова посада: "; std::getline(std::cin >> std::ws, position);
    std::cout << "Зарплата/Стипендія: "; std::cin >> salary;
}

// Методи виведення
void Person::output() const {
    std::cout << "Ім'я: " << fullName << " | " << gender << " | Вік: " << age;
}

void AcademicPerson::output() const {
    Person::output();
    std::cout << " | ВНЗ: " << university;
}

void Student::output() const {
    AcademicPerson::output();
    std::cout << " | Курс: " << course << " | Група: " << group;
}

void Teacher::output() const {
    AcademicPerson::output();
    std::cout << " | Посада: " << position << " | ЗП: " << salary;
}

void Aspirant::output() const {
    Student::output(); // Виводимо як студента
    std::cout << " | Посада: " << position << " | ЗП: " << salary;
}