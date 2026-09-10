#include "../include/Doctor.h"
#include <iostream>

Doctor::Doctor(int id, std::string name, std::string phone, std::string specialization, double consultationFee)
    : Person(id, name, phone) {
    this->specialization = specialization;
    this->consultationFee = consultationFee;
}

void Doctor::displayInfo() const {
    std::cout << "--- Doctor Details ---" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Specialization: " << specialization << std::endl;
    std::cout << "Consultation Fee: $" << consultationFee << std::endl;
}

int Doctor::getId() const { return id; }
std::string Doctor::getName() const { return name; }
std::string Doctor::getPhone() const { return phone; }
std::string Doctor::getSpecialization() const { return specialization; }
double Doctor::getConsultationFee() const { return consultationFee; }

void Doctor::setSpecialization(std::string spec) { specialization = spec; }
void Doctor::setConsultationFee(double fee) { consultationFee = fee; }