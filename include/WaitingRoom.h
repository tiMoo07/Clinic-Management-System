#pragma once
#include "Patient.h"

struct PatientNode {
    Patient* patient;
    int priority;
    PatientNode* next;
    PatientNode(Patient* p, int prio);
};

class WaitingRoom {
private:
    PatientNode* head;

public:
    WaitingRoom();
    ~WaitingRoom();

    void addPatient(Patient* p, int priority);
    Patient* callNextPatient();
    void displayWaitingRoom() const;
    bool isEmpty() const;
};