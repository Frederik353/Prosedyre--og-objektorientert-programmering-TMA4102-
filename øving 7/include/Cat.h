#pragma once
#include "Animal.h"
#include <string>

class Cat : public Animal {
public:
  Cat(std::string name, int age) : Animal(name, age){};
  std::string toString() const override;
};
