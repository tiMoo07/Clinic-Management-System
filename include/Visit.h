#ifndef VISIT_H
#define VISIT_H

#include <string>

class Visit {
   protected:
    std::string date;
    std::string doctorName;
    std::string diagnosis;
    double baseFee;

   public:
    Visit(std::string date, std::string doctorName, std::string diagnosis, double baseFee);
    virtual ~Visit() {}

    std::string getDate() const;
    std::string getDoctorName() const;
    std::string getDiagnosis() const;

    virtual double calculateFee() const = 0;
    virtual void displayVisit() const;
};

class NormalVisit : public Visit {
   public:
    NormalVisit(std::string date, std::string doctorName, std::string diagnosis, double baseFee);
    double calculateFee() const override;
};

class EmergencyVisit : public Visit {
   public:
    EmergencyVisit(std::string date, std::string doctorName, std::string diagnosis, double baseFee);
    double calculateFee() const override;
};

#endif