#pragma once
#include <string>

#include "Doctor.h"
#include "Patient.h"
#include "WaitingRoom.h"

class ClinicManager {
   private:
    Patient** patients;
    int patientCount;
    int patientCapacity;

    Doctor** doctors;
    int doctorCount;
    int doctorCapacity;

    WaitingRoom waitingRoom;

    void resizePatients();
    void resizeDoctors();

   public:
    ClinicManager();
    ~ClinicManager();

    int getValidInt();
    double getValidDouble();
    std::string getValidLine();

    void addPatient(Patient* p);
    Patient* findPatientById(int id) const;
    void deletePatient(int id);
    void displayAllPatients() const;
    void sortPatients(int criterion);

    void addDoctor(Doctor* d);
    Doctor* findDoctorById(int id) const;
    void displayAllDoctors() const;

    void sendPatientToWaitingRoom(int patientId, bool isEmergency, std::string arrivalTime);
    void serveNextPatient(Doctor* doc, std::string date, std::string diagnosis, bool isEmergency);
    void displayWaitingRoom() const;
    void displayPatientHistory(int patientId) const;
};