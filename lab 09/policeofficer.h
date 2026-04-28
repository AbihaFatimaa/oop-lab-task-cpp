#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
using namespace std;

class ParkedCar;
class ParkingTicket;

class PoliceOfficer {
private:
    string name;
    string badgeNumber;

public:
    PoliceOfficer(string name, string badgeNumber);

    string getName() const;
    string getBadge() const;

    ParkingTicket issueTicket(ParkedCar car, int overtime) const;
};

#endif