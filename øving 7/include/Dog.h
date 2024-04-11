#include "Animal.h"
#include <string>

class Dog : public Animal {
public:
  Dog(std::string name, int age) : Animal(name, age){};
  std::string toString() const override;
};
