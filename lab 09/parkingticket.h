#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkedCar.h"

class PoliceOfficer;

class ParkingTicket {
private:
    ParkedCar car;
    const PoliceOfficer* officer;
    int fine;
public:
    ParkingTicket(ParkedCar c, const PoliceOfficer* o, int over);

    void printTicket();
};

#endif