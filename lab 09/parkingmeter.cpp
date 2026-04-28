#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int minutesPurchased) {
    this->minutesPurchased = minutesPurchased;
}

int ParkingMeter::getMinutesPurchased() {
    return minutesPurchased;
}