#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Friend.h"
#include <vector>
#include <fstream>

class PhoneBook {
    Friend list[100];
    int count;
    std::string filename;

public:
    PhoneBook(const std::string& fname);

    void loadFromFile();
    void saveToFile() const;

    void addFriend();
    void findByName(const std::string& searchName) const;
    void updatePhone(const std::string& searchName, const std::string& newPhone);
    void displayAll() const;
};

#endif