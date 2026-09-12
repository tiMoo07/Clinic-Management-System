#include "../include/ClinicManager.h"
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

ClinicManager::ClinicManager() {
    patientCapacity = 5;
    patientCount = 0;
    patients = new Patient*[patientCapacity];

    doctorCapacity = 5;
    doctorCount = 0;
    doctors = new Doctor*[doctorCapacity];
}

ClinicManager::~ClinicManager() {
    for (int i = 0; i < patientCount; i++) delete patients[i];
    delete[] patients;

    for (int i = 0; i < doctorCount; i++) delete doctors[i];
    delete[] doctors;
}

int ClinicManager::getValidInt() {
    int val;
    while (!(cin >> val)) {
        cout << "Invalid input! Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return val;
}

double ClinicManager::getValidDouble() {
    double val;
    while (!(cin >> val)) {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return val;
}

string ClinicManager::getValidLine() {
    string str;
    getline(cin >> ws, str);
    return str;
}

void ClinicManager::resizePatients() {
    patientCapacity *= 2;
    Patient** temp = new Patient*[patientCapacity];
    for (int i = 0; i < patientCount; i++) temp[i] = patients[i];
    delete[] patients;
    patients = temp;
}

void ClinicManager::resizeDoctors() {
    doctorCapacity *= 2;
    Doctor** temp = new Doctor*[doctorCapacity];
    for (int i = 0; i < doctorCount; i++) temp[i] = doctors[i];
    delete[] doctors;
    doctors = temp;
}

void ClinicManager::addPatient(Patient* p) {
    if (findPatientById(p->getId()) != nullptr) {
        cout << "Error: Patient ID already exists!\n";
        delete p;
        return;
    }
    if (patientCount == patientCapacity) resizePatients();

    int i = patientCount - 1;
    while (i >= 0 && patients[i]->getId() > p->getId()) {
        patients[i + 1] = patients[i];
        i--;
    }
    patients[i + 1] = p;
    patientCount++;
    cout << "Patient added successfully.\n";
}

Patient* ClinicManager::findPatientById(int id) const {
    int low = 0;
    int high = patientCount - 1;
    int comparisons = 0;

    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;

        if (patients[mid]->getId() == id) {
            cout << "Found in " << comparisons << " comparisons [binary search]\n";
            return patients[mid];
        }
        if (patients[mid]->getId() < id) low = mid + 1;
        else high = mid - 1;
    }

    cout << "[" << comparisons << " comparisons made] ";
    return nullptr;
}

void ClinicManager::deletePatient(int id) {
    int idx = -1;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i]->getId() == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Error: Patient not found.\n";
        return;
    }
    delete patients[idx];
    for (int i = idx; i < patientCount - 1; i++) patients[i] = patients[i + 1];
    patientCount--;
    cout << "Patient deleted successfully.\n";
}

void ClinicManager::displayAllPatients() const {
    if (patientCount == 0) {
        cout << "No patients registered yet." << endl;
        return;
    }
    cout << "\n=== ALL PATIENTS ===" << endl;
    cout << "ID\tNAME\t\tAGE\tPHONE" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < patientCount; i++) cout << *patients[i] << endl;
    cout << "\nTotal: " << patientCount << " patient(s)." << endl;
}

void ClinicManager::sortPatients(int criterion) {
    if (patientCount == 0) {
        cout << "No patients registered to sort.\n";
        return;
    }

    Patient** tempArray = new Patient*[patientCount];
    for (int i = 0; i < patientCount; i++) tempArray[i] = patients[i];

    int comparisons = 0;
    for (int i = 0; i < patientCount - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < patientCount; j++) {
            comparisons++;
            if (criterion == 1) {
                if (tempArray[j]->getName() < tempArray[minIdx]->getName()) minIdx = j;
            } else {
                if (tempArray[j]->getAge() < tempArray[minIdx]->getAge()) minIdx = j;
            }
        }
        if (minIdx != i) {
            Patient* temp = tempArray[i];
            tempArray[i] = tempArray[minIdx];
            tempArray[minIdx] = temp;
        }
    }

    cout << "\n=== PATIENTS (SORTED VIEW ONLY) ===" << endl;
    cout << "ID\tNAME\t\tAGE\tPHONE" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < patientCount; i++) cout << *tempArray[i] << endl;
    cout << "\nSorted in " << comparisons << " comparisons [selection sort]" << endl;

    delete[] tempArray;
}

void ClinicManager::addDoctor(Doctor* d) {
    if (findDoctorById(d->getId()) != nullptr) {
        cout << "Error: Doctor ID already exists!\n";
        delete d;
        return;
    }
    if (doctorCount == doctorCapacity) resizeDoctors();
    doctors[doctorCount++] = d;
    cout << "Doctor added successfully.\n";
}

Doctor* ClinicManager::findDoctorById(int id) const {
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i]->getId() == id) return doctors[i];
    }
    return nullptr;
}

void ClinicManager::displayAllDoctors() const {
    if (doctorCount == 0) {
        cout << "No doctors registered.\n";
        return;
    }
    cout << "\n---------------- ALL DOCTORS ----------------\n";
    for (int i = 0; i < doctorCount; i++) {
        doctors[i]->displayInfo();
        cout << "---------------------------------------------\n";
    }
}

void ClinicManager::sendPatientToWaitingRoom(int patientId, bool isEmergency, string arrivalTime) {
    Patient* p = findPatientById(patientId);
    if (p == nullptr) {
        cout << "Error: Patient not found!\n";
        return;
    }
    int priority = isEmergency ? 10 : 1;
    waitingRoom.addPatient(p, priority);
    cout << "Patient " << p->getName() << " added to waiting room (" << (isEmergency ? "Emergency" : "Normal") << ").\n";
}

void ClinicManager::serveNextPatient(Doctor* doc, string date, string diagnosis, bool isEmergency) {
    if (doc == nullptr) {
        cout << "Error: Doctor is invalid or not found.\n";
        return;
    }
    if (waitingRoom.isEmpty()) {
        cout << "Waiting room is empty.\n";
        return;
    }

    Patient* p = waitingRoom.callNextPatient();
    Visit* v = nullptr;

    if (isEmergency) {
        v = new EmergencyVisit(date, doc->getName(), diagnosis, doc->getConsultationFee());
    } else {
        v = new NormalVisit(date, doc->getName(), diagnosis, doc->getConsultationFee());
    }

    p->addVisit(v);

    cout << ">>> NOW CALLING: " << p->getName() << " (" << (isEmergency ? "EMERGENCY" : "NORMAL") << ")\n";
    cout << "Doctor   : " << doc->getName() << "\n";
    cout << "Diagnosis: " << diagnosis << "\n";
    cout << "Fee      : " << v->calculateFee() << " EGP\n";
    cout << "[OK] Visit added to history.\n";
}

void ClinicManager::displayWaitingRoom() const { waitingRoom.displayWaitingRoom(); }

void ClinicManager::displayPatientHistory(int patientId) const {
    Patient* p = findPatientById(patientId);
    if (p == nullptr) {
        cout << "Error: Patient not found.\n";
        return;
    }
    p->displayVisitHistory();
}