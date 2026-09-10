#include <iostream>
#include <string>

#include "ClinicManager.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

int main() {
    ClinicManager clinic;

    cout << "=== INITIALIZING CLINIC WITH TEST DATA ===\n";

    clinic.addDoctor(new Doctor(101, "Dr. Ahmed Samy", "01011112222", "Cardiology", 300.0));
    clinic.addDoctor(new Doctor(102, "Dr. Mona Ali", "01122223333", "Pediatrics", 200.0));

    clinic.addPatient(new Patient(5, "Youssef Hassan", "0123456789", 28));
    clinic.addPatient(new Patient(2, "Omar Essam", "0100000000", 25));
    clinic.addPatient(new Patient(8, "Mariam Mahmoud", "0111111111", 22));
    clinic.addPatient(new Patient(1, "Ali Khaled", "0155555555", 40));

    clinic.sendPatientToWaitingRoom(2, false, "10:00 AM");  
    clinic.sendPatientToWaitingRoom(8, true, "10:15 AM");   
    clinic.sendPatientToWaitingRoom(5, false, "10:30 AM");  

    cout << "===========================================\n\n";

    // =========================================================
    // القائمة التفاعلية الشاملة
    // =========================================================
    int mainChoice = -1;

    while (mainChoice != 0) {
        cout << "\n================================\n";
        cout << "    CLINIC MANAGEMENT SYSTEM    \n";
        cout << "================================\n";
        cout << "1. Patients Menu\n";
        cout << "2. Doctors Menu\n";
        cout << "3. Waiting Room Menu\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        mainChoice = clinic.getValidInt();

        if (mainChoice == 1) {
            int pChoice = -1;
            while (pChoice != 0) {
                cout << "\n--- PATIENTS MENU ---\n";
                cout << "1. Add New Patient\n";
                cout << "2. View All Patients\n";
                cout << "3. Search Patient by ID (Binary Search)\n";
                cout << "4. Delete Patient\n";
                cout << "5. View Patient Visit History\n";
                cout << "6. Sort Patients (Selection Sort)\n";
                cout << "0. Back to Main Menu\n";
                cout << "Choose: ";
                pChoice = clinic.getValidInt();

                if (pChoice == 1) {
                    cout << "Enter Patient ID   : ";
                    int id = clinic.getValidInt();
                    cout << "Enter Patient Name : ";
                    string name = clinic.getValidLine();
                    cout << "Enter Patient Age  : ";
                    int age = clinic.getValidInt();
                    cout << "Enter Phone Number : ";
                    string phone = clinic.getValidLine();
                    clinic.addPatient(new Patient(id, name, phone, age));
                } else if (pChoice == 2) {
                    clinic.displayAllPatients();
                } else if (pChoice == 3) {
                    cout << "Enter Patient ID to search: ";
                    int id = clinic.getValidInt();
                    Patient* p = clinic.findPatientById(id);
                    if (p != nullptr) {
                        p->displayInfo();
                    }
                } else if (pChoice == 4) {
                    cout << "Enter Patient ID to delete: ";
                    int id = clinic.getValidInt();
                    clinic.deletePatient(id);
                } else if (pChoice == 5) {
                    cout << "Enter Patient ID: ";
                    int id = clinic.getValidInt();
                    clinic.displayPatientHistory(id);
                } else if (pChoice == 6) {
                    cout << "Sort by: (1) Name  (2) Age: ";
                    int crit = clinic.getValidInt();
                    clinic.sortPatients(crit);
                }
            }
        } else if (mainChoice == 2) {
            int dChoice = -1;
            while (dChoice != 0) {
                cout << "\n--- DOCTORS MENU ---\n";
                cout << "1. Add New Doctor\n";
                cout << "2. View All Doctors\n";
                cout << "3. Search Doctor by ID\n";
                cout << "0. Back to Main Menu\n";
                cout << "Choose: ";
                dChoice = clinic.getValidInt();

                if (dChoice == 1) {
                    cout << "Enter Doctor ID       : ";
                    int id = clinic.getValidInt();
                    cout << "Enter Doctor Name     : ";
                    string name = clinic.getValidLine();
                    cout << "Enter Phone Number    : ";
                    string phone = clinic.getValidLine();
                    cout << "Enter Specialization  : ";
                    string spec = clinic.getValidLine();
                    cout << "Enter Consultation Fee: ";
                    double fee = clinic.getValidDouble();
                    clinic.addDoctor(new Doctor(id, name, phone, spec, fee));
                } else if (dChoice == 2) {
                    clinic.displayAllDoctors();
                } else if (dChoice == 3) {
                    cout << "Enter Doctor ID: ";
                    int id = clinic.getValidInt();
                    Doctor* d = clinic.findDoctorById(id);
                    if (d != nullptr) {
                        d->displayInfo();
                    }
                }
            }
        } else if (mainChoice == 3) {
            int wChoice = -1;
            while (wChoice != 0) {
                cout << "\n--- WAITING ROOM MENU ---\n";
                cout << "1. Send Patient to Waiting Room\n";
                cout << "2. View Waiting Queue\n";
                cout << "3. Call / Serve Next Patient\n";
                cout << "0. Back to Main Menu\n";
                cout << "Choose: ";
                wChoice = clinic.getValidInt();

                if (wChoice == 1) {
                    cout << "Enter Patient ID    : ";
                    int id = clinic.getValidInt();
                    cout << "Case Type (1: Emergency / 2: Normal): ";
                    int type = clinic.getValidInt();
                    cout << "Arrival Time (e.g. 11:15 AM)        : ";
                    string time = clinic.getValidLine();
                    clinic.sendPatientToWaitingRoom(id, (type == 1), time);
                } else if (wChoice == 2) {
                    clinic.displayWaitingRoom();
                } else if (wChoice == 3) {
                    cout << "Enter Assigned Doctor ID: ";
                    int docId = clinic.getValidInt();
                    Doctor* doc = clinic.findDoctorById(docId);

                    if (doc != nullptr) {
                        cout << "Enter Visit Date (e.g. 2026-09-09): ";
                        string date = clinic.getValidLine();
                        cout << "Enter Diagnosis                   : ";
                        string diag = clinic.getValidLine();
                        cout << "Is Emergency? (1: Yes / 0: No)    : ";
                        int isEmergInt = clinic.getValidInt();

                        clinic.serveNextPatient(doc, date, diag, (isEmergInt == 1));
                    }
                }
            }
        }
    }

    cout << "\nSystem closed successfully. Good luck with your testing!\n";
    return 0;
}   