#include "../include/Visit.h"
#include <iostream>

Visit::Visit(std::string date, std::string doctorName, std::string diagnosis, double baseFee) {
    this->date = date;
    this->doctorName = doctorName;
    this->diagnosis = diagnosis;
    this->baseFee = baseFee;
}

std::string Visit::getDate() const { return date; }
std::string Visit::getDoctorName() const { return doctorName; }
std::string Visit::getDiagnosis() const { return diagnosis; }

void Visit::displayVisit() const {
    std::cout << date << " | Dr. " << doctorName << " | " << diagnosis << " | " << calculateFee() << " EGP" << std::endl;
}

// Normal Visit Implementation
NormalVisit::NormalVisit(std::string date, std::string doctorName, std::string diagnosis, double baseFee)
    : Visit(date, doctorName, diagnosis, baseFee) {}

double NormalVisit::calculateFee() const {
    return baseFee; // Standard fee
}

// Emergency Visit Implementation (Adds extra charge, e.g., 50% extra)
EmergencyVisit::EmergencyVisit(std::string date, std::string doctorName, std::string diagnosis, double baseFee)
    : Visit(date, doctorName, diagnosis, baseFee) {}

double EmergencyVisit::calculateFee() const {
    return baseFee + 100.0; 
}