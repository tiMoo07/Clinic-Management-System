#include "../include/Person.h"

Person::Person(int id, std::string name, std::string phone) {
    this->id = id;
    this->name = name;
    this->phone = phone;
}

Person::~Person() {}