#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
using namespace std;

class ParkedCar {
private:
    string make, model, color, licenseNumber;
    int minutesParked;

public:
    ParkedCar(string make, string model, string color,
              string licenseNumber, int minutesParked);

    string getMake();
    string getModel();
    string getColor();
    string getLicenseNumber();
    int getMinutesParked();
};

#endif