#include "../include/VisitHistory.h"

#include <iostream>

VisitNode::VisitNode(Visit* v) {
    visit = v;
    next = nullptr;
}

VisitHistory::VisitHistory() { head = nullptr; }

VisitHistory::~VisitHistory() {
    VisitNode* current = head;
    while (current != nullptr) {
        VisitNode* temp = current;
        current = current->next;
        delete temp->visit;
        delete temp;
    }
}

void VisitHistory::addVisit(Visit* v) {
    VisitNode* newNode = new VisitNode(v);
    if (head == nullptr) {
        head = newNode;
    } else {
        VisitNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void VisitHistory::displayHistory() const {
    if (head == nullptr) {
        std::cout << "No visit history available." << std::endl;
        return;
    }
    VisitNode* temp = head;
    while (temp != nullptr) {
        temp->visit->displayVisit();
        temp = temp->next;
    }
}

double VisitHistory::calculateTotalRecursive(VisitNode* node) const {
    if (node == nullptr)
        return 0.0;

    return node->visit->calculateFee() + calculateTotalRecursive(node->next);
}

double VisitHistory::calculateTotalFees() const { return calculateTotalRecursive(head); }

bool VisitHistory::isEmpty() const { return head == nullptr; }