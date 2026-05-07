#ifndef FRIEND_H
#define FRIEND_H

#include "Person.h"

class Friend : public Person {
    std::string phone;

public:
    Friend(std::string n = "", unsigned y = 0, std::string ph = "");

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    void setPhone(const std::string& newPh) { phone = newPh; }

    int input(std::istream& in) override;
    void show(std::ostream& out) const override;
};

#endif