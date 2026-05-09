#include "Person.h"

Person::Person(std::string n, unsigned y) : name(n), byear(y) {}

int Person::input(std::istream& in) {
    std::cout << "Прізвище: "; in >> name;
    std::cout << "Рік народження: "; in >> byear;
    return in ? 1 : 0;
}

void Person::show(std::ostream& out) const {
    out << "Прізвище: " << name << ", Рік: " << byear;
}

std::istream& operator>>(std::istream& in, Person& p) {
    p.input(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    p.show(out);
    return out;
}