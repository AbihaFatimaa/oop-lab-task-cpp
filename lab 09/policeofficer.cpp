#include "PoliceOfficer.h"
#include "ParkingTicket.h"

PoliceOfficer::PoliceOfficer(string name, string badgeNumber) {
    this->name = name;
    this->badgeNumber = badgeNumber;
}

string PoliceOfficer::getName() const {
    return name;
}

string PoliceOfficer::getBadge() const {
    return badgeNumber;
}

ParkingTicket PoliceOfficer::issueTicket(ParkedCar car, int overtime) const {
    return ParkingTicket(car, this, overtime);
}