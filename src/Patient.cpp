#include "../include/Patient.h"
#include <iostream>
#include <iomanip> 

Patient::Patient(int id, std::string name, std::string phone, int age)
    : Person(id, name, phone) {
    this->age = age;
}

void Patient::addVisit(Visit* v) {
    history.addVisit(v);
}

void Patient::displayVisitHistory() const {
    std::cout << "\nVISIT HISTORY FOR PATIENT: " << name << std::endl;
    history.displayHistory();
    std::cout << "Total Spent: " << history.calculateTotalFees() << " EGP" << std::endl;
}

double Patient::getTotalSpent() const {
    return history.calculateTotalFees();
}

void Patient::displayInfo() const {
    std::cout << "--- Patient Details ---" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Age: " << age << std::endl;
}

int Patient::getId() const { return id; }
std::string Patient::getName() const { return name; }
std::string Patient::getPhone() const { return phone; }
int Patient::getAge() const { return age; }
void Patient::setAge(int age) { this->age = age; }
void Patient::setPhone(std::string phone) { this->phone = phone; }

std::ostream& operator<<(std::ostream& os, const Patient& p) {
    os << std::left << std::setw(8) << p.id 
       << std::setw(20) << p.name 
       << std::setw(8) << p.age 
       << p.phone;
    return os;
}