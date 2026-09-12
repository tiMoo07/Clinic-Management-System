#include "../include/Visit.h"
#include <iostream>

using namespace std;

// Base Class Constructor using Initializer List
Visit::Visit(string date, string doctorName, string diagnosis, double baseFee)
    : date(date), doctorName(doctorName), diagnosis(diagnosis), baseFee(baseFee) {}

string Visit::getDate() const { return date; }
string Visit::getDoctorName() const { return doctorName; }
string Visit::getDiagnosis() const { return diagnosis; }

void Visit::displayVisit() const {
    cout << date << " | Dr. " << doctorName << " | " << diagnosis << " | " << calculateFee() << " EGP" << endl;
}

// Normal Visit Implementation
NormalVisit::NormalVisit(string date, string doctorName, string diagnosis, double baseFee)
    : Visit(date, doctorName, diagnosis, baseFee) {}

double NormalVisit::calculateFee() const {
    return baseFee; // Standard fee
}

// Emergency Visit Implementation
EmergencyVisit::EmergencyVisit(string date, string doctorName, string diagnosis, double baseFee)
    : Visit(date, doctorName, diagnosis, baseFee) {}

double EmergencyVisit::calculateFee() const {
    return baseFee + 100.0; // Emergency charge
}