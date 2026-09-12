#include "../include/Patient.h"

#include <iomanip>
#include <iostream>

using namespace std;

Patient::Patient(int id, string name, string phone, int age) : Person(id, name, phone) {
    this->age = age;
}

void Patient::addVisit(Visit* v) { history.addVisit(v); }

void Patient::displayVisitHistory() const {
    cout << "\nVISIT HISTORY FOR PATIENT: " << name << endl;
    history.displayHistory();
    cout << "Total Spent: " << history.calculateTotalFees() << " EGP" << endl;
}

double Patient::getTotalSpent() const { return history.calculateTotalFees(); }

void Patient::displayInfo() const {
    cout << "--- Patient Details ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Age: " << age << endl;
}

int Patient::getId() const { return id; }
string Patient::getName() const { return name; }
string Patient::getPhone() const { return phone; }
int Patient::getAge() const { return age; }
void Patient::setAge(int age) { this->age = age; }
void Patient::setPhone(string phone) { this->phone = phone; }

ostream& operator<<(ostream& os, const Patient& p) {
    os << left << setw(8) << p.id << setw(20) << p.name << setw(8) << p.age << p.phone;
    return os;
}