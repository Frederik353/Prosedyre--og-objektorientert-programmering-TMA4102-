#pragma once
#include <string>

class Animal {
protected:
  std::string name;
  int age;

public:
  Animal(std::string name, int age) : name(name), age(age){};
  virtual ~Animal() = default;
  virtual std::string toString() const = 0;
};
