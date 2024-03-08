#include "Dog.h"
#include <string>

std::string Dog::toString() const {
  std::string result = "Dog: " + name + " " + std::to_string(age);
  return result;
}
