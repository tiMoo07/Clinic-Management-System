#pragma once
#include "Visit.h"

struct VisitNode {
    Visit* visit;
    VisitNode* next;
    VisitNode(Visit* v);
};

class VisitHistory {
   private:
    VisitNode* head;
    double calculateTotalRecursive(VisitNode* node) const;

   public:
    VisitHistory();
    ~VisitHistory();

    void addVisit(Visit* v);
    void displayHistory() const;
    double calculateTotalFees() const;
    bool isEmpty() const;
};