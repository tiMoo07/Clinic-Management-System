#pragma once
#include "Person.h"
#include <string>

class Doctor : public Person {
private:
    std::string specialization;
    double consultationFee;

public:
    Doctor(int id, std::string name, std::string phone, std::string specialization, double consultationFee);

    void displayInfo() const override;

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getSpecialization() const;
    double getConsultationFee() const;

    void setSpecialization(std::string spec);
    void setConsultationFee(double fee);
};