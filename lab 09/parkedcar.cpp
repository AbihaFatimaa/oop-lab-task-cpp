#include "ParkedCar.h"

ParkedCar::ParkedCar(string make, string model, string color,
                     string licenseNumber, int minutesParked) {
    this->make = make;
    this->model = model;
    this->color = color;
    this->licenseNumber = licenseNumber;
    this->minutesParked = minutesParked;
}

string ParkedCar::getMake() { return make; }
string ParkedCar::getModel() { return model; }
string ParkedCar::getColor() { return color; }
string ParkedCar::getLicenseNumber() { return licenseNumber; }
int ParkedCar::getMinutesParked() { return minutesParked; }