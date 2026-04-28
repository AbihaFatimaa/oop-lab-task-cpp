#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
using namespace std;

ParkingTicket::ParkingTicket(ParkedCar c, const PoliceOfficer* o, int over)
    : car(c), officer(o) {

    int hours = (over + 59) / 60;
    fine = 25 + (hours - 1) * 10;
}

void ParkingTicket::printTicket() {
    cout << "\n--- Parking Ticket ---\n";
    cout << "Car: " << car.getMake() << " " << car.getModel() << endl;
    cout << "Color: " << car.getColor() << endl;
    cout << "License: " << car.getLicenseNumber() << endl;

    cout << "Fine: $" << fine << endl;

    cout << "Officer: " << officer->getName() << endl;
    cout << "Badge: " << officer->getBadge() << endl;
}