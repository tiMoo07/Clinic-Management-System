#pragma once
#include "Person.h"
#include "VisitHistory.h"
#include <iomanip>

class Patient : public Person {
private:
    int age;
    VisitHistory history;

public:
    Patient(int id, std::string name, std::string phone, int age);

    void addVisit(Visit* v);
    void displayVisitHistory() const;
    double getTotalSpent() const;
    void displayInfo() const override;

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    int getAge() const;
    void setAge(int age);
    void setPhone(std::string phone);

    friend std::ostream& operator<<(std::ostream& os, const Patient& p);
};