#include "Car.h"
#include <iostream>

bool Car::hasAvailableSeat() const {
  if (_freeSeats > 0)
    return true;
  else
    return false;
}

std::ostream &operator<<(std::ostream &os, const Car &car) {
  os << "Car: "
     << ", Available seat" << ((car.getFreeSeats() > 1) ? "s" : "") << ": "
     << car.getFreeSeats();
  return os;
};
