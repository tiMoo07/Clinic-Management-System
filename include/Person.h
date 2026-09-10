#pragma once
#include <iostream>
#include <string>

class Person {
protected:
    int id;
    std::string name;
    std::string phone;

public:
    Person(int id, std::string name, std::string phone);
    virtual void displayInfo() const = 0;
    virtual ~Person();
};