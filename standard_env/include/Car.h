#pragma once
#include <iostream>

class Car {
private:
  int _freeSeats;

public:
  Car(int freeSeats) : _freeSeats(freeSeats) {

    std::cout << freeSeats << "  " << _freeSeats << std::endl;
    if (_freeSeats < 0) {
      std::cerr << "Error: Car cannot have negative free seats." << std::endl;
      _freeSeats = 0;
    }
  }
  bool hasAvailableSeat() const;
  int getFreeSeats() const { return _freeSeats; };
  void reserveFreeSeat() { --_freeSeats; };
};

std::ostream &operator<<(std::ostream &os, const Car &car);