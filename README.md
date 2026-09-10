# Clinic Management System (C++)

A comprehensive Clinic Management System written in C++ demonstrating Core Object-Oriented Programming (OOP) concepts and Data Structures.

## Features
- **Patient Management:** Add, search (Binary Search), delete, and sort patients (Selection Sort).
- **Doctor Management:** Add and view doctors with specialized fees.
- **Waiting Room Queue:** Priority Queue implementation to handle Emergency and Normal cases.
- **Visit History:** Singly Linked List tracking patient visits and calculating total fees recursively.

## OOP & Data Structures Applied
- **Inheritance & Polymorphism:** `Person` -> `Patient`/`Doctor`, `Visit` -> `NormalVisit`/`EmergencyVisit`
- **Dynamic Arrays:** Resizable arrays for managing patients and doctors.
- **Linked List:** Used for storing visit history.
- **Priority Queue:** Linked list implementation for waiting room triage.
- **Algorithms:** Binary Search $O(\log n)$ and Selection Sort $O(n^2)$.

## How to Build and Run

Using `g++`:
```bash
g++ -Iinclude src/*.cpp main.cpp -o clinic_app
./clinic_app