#include "../include/WaitingRoom.h"
#include <iostream>

PatientNode::PatientNode(Patient* p, int prio) {
    patient = p;
    priority = prio;
    next = nullptr;
}

WaitingRoom::WaitingRoom() {
    head = nullptr;
}

WaitingRoom::~WaitingRoom() {
    while (head != nullptr) {
        PatientNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void WaitingRoom::addPatient(Patient* p, int priority) {
    PatientNode* newNode = new PatientNode(p, priority);

    if (head == nullptr || priority > head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }

    PatientNode* temp = head;
    while (temp->next != nullptr && temp->next->priority >= priority) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

Patient* WaitingRoom::callNextPatient() {
    if (head == nullptr) return nullptr;

    PatientNode* temp = head;
    Patient* p = temp->patient;
    head = head->next;
    delete temp;
    return p;
}

void WaitingRoom::displayWaitingRoom() const {
    if (head == nullptr) {
        std::cout << "Waiting room is empty." << std::endl;
        return;
    }

    std::cout << "\n--- Patients in Waiting Room (Priority Queue) ---" << std::endl;
    PatientNode* temp = head;
    while (temp != nullptr) {
        std::cout << "[Priority " << temp->priority << "] ID: " 
                  << temp->patient->getId() << " - Name: " 
                  << temp->patient->getName() << std::endl;
        temp = temp->next;
    }
}

bool WaitingRoom::isEmpty() const {
    return head == nullptr;
}