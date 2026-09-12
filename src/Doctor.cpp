#include "../include/Doctor.h"
#include <iostream>

using namespace std;

Doctor::Doctor(int id, string name, string phone, string specialization, double consultationFee)
    : Person(id, name, phone) {
    this->specialization = specialization;
    this->consultationFee = consultationFee;
}

void Doctor::displayInfo() const {
    cout << "--- Doctor Details ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Consultation Fee: $" << consultationFee << endl;
}

int Doctor::getId() const { return id; }
string Doctor::getName() const { return name; }
string Doctor::getPhone() const { return phone; }
string Doctor::getSpecialization() const { return specialization; }
double Doctor::getConsultationFee() const { return consultationFee; }

void Doctor::setSpecialization(string spec) { specialization = spec; }
void Doctor::setConsultationFee(double fee) { consultationFee = fee; }