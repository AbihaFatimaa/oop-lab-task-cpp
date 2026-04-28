#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"

using namespace std;

int main() {
    ParkedCar car("Toyota", "Corolla", "White", "ABC-123", 120);
    ParkingMeter meter(60);
    PoliceOfficer officer("Ali Khan", "PK-786");

    int parked = car.getMinutesParked();
    int allowed = meter.getMinutesPurchased();

    if (parked > allowed) {
        int overtime = parked - allowed;
        ParkingTicket ticket = officer.issueTicket(car, overtime);
        ticket.printTicket();
    } else {
        cout << "No violation.\n";
    }

    return 0;
}