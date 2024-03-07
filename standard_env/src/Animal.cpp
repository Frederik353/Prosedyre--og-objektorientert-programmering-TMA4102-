#include "Animal.h"
#include <iostream>

Animal::tostring() {
  std::cout << "Name: " << name << ", Age: " << age << std::endl;
}