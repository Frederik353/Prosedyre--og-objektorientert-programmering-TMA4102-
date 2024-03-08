#include "Cat.h"
#include <string>

std::string Cat::toString() const {
  std::string result = "Cat: " + name + " " + std::to_string(age);
  return result;
}