#include "Friend.h"

Friend::Friend(std::string n, unsigned y, std::string ph) 
    : Person(n, y), phone(ph) {}

int Friend::input(std::istream& in) {
    Person::input(in);
    std::cout << "Номер телефону: "; in >> phone;
    return in ? 1 : 0;
}

void Friend::show(std::ostream& out) const {
    Person::show(out);
    out << ", Тел: " << phone;
}