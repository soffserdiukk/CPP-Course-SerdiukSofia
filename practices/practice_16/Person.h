#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person {
protected:
    std::string name;
    unsigned byear;

public:
    Person(std::string n = "", unsigned y = 0);
    virtual ~Person() {}

    virtual int input(std::istream& in);
    virtual void show(std::ostream& out) const;

    unsigned getBYear() const { return byear; }

    // Перевантаження операторів для зручності
    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
};

#endif

