#include "Person.h"

bool Person::hasAvailableSeat() const {
  if (_car->hasAvailableSeat()) {
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
  os << "Name: " << person.getName() << ", Email: " << person.getEmail();
  std::cout << person.hasCar() << std::endl;
  if (person.hasCar()) {
    os << ", " << *(person.getCar());
  }
  return os;
};

bool Person::hasCar() const { return _car != nullptr; };