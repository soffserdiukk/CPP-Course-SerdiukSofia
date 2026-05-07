#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>

// Допоміжна функція
int getSafeInt(const std::string& prompt, int min, int max);

class Person {
protected:
    std::string fullName;
    std::string gender;
    int age;
public:
    Person(std::string name = "", std::string g = "", int a = 0);
    virtual void input();
    virtual void output() const;
    virtual ~Person() {}
};

class AcademicPerson : public virtual Person {
protected:
    std::string university;
public:
    AcademicPerson(std::string name = "", std::string g = "", int a = 0, std::string uni = "");
    void input() override;
    void output() const override;
    std::string getUniversity() const { return university; }
};

class Student : public virtual AcademicPerson {
protected:
    int course;
    std::string group;
public:
    Student(std::string name = "", std::string g = "", int a = 0, std::string uni = "", int c = 1, std::string gr = "");
    void input() override;
    void output() const override;
};

class Teacher : public virtual AcademicPerson {
protected:
    std::string position;
    double salary;
public:
    Teacher(std::string name = "", std::string g = "", int a = 0, std::string uni = "", std::string pos = "", double sal = 0);
    void input() override;
    void output() const override;
};

class Aspirant : public Student, public Teacher {
public:
    Aspirant(std::string name = "", std::string g = "", int a = 0, std::string uni = "");
    void input() override;
    void output() const override;
};

#endif