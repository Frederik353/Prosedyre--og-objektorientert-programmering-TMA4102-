#pragma once
#include "Car.h"
#include <memory>
#include <string>

class Person {
private:
  std::string _name;
  std::string _email;
  std::unique_ptr<Car> _car;

public:
  Person(std::string name, std::string email,
         std::unique_ptr<Car> car = nullptr)
      : _name{name}, _email{email}, _car{std::move(car)} {};

  std::string getName() const { return _name; };
  std::string getEmail() const { return _email; };
  void setEmail(std::string email) { _email = email; };
  bool hasAvailableSeat() const;
  bool hasCar() const;
  Car *getCar() const { return _car.get(); };
};

std::ostream &operator<<(std::ostream &os, const Person &person);