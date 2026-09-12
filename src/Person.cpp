#include "../include/Person.h"

using namespace std;

Person::Person(int id, string name, string phone)
    : id(id), name(name), phone(phone) {}

Person::~Person() {}