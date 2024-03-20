#include "Car.h"
#include "MeetingWindow.h"
#include "Person.h"
#include <iostream>

int main() {
  Car car(10);
  Person person("Jhon doe", "Joe@gmail.com");
  std::cout << person << std::endl;
  MeetingWindow win{100, 100, 600, 400, "MeetingWindow"};

  win.wait_for_close();

  return 0;
}
