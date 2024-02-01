#include "tests.h"
#include "utils.h"
#include <cassert>
#include <iostream>

void testCallByValue() {
  int startValue = 5;
  int result = incrementByValueNumTimes(startValue, 2, 10);
  // Verify that result is correct
  assert(result == 25);
  // Verify that startValue remains unchanged
  assert(startValue == 5);
  std::cout << "testCallByValue Passed!" << std::endl;
}

void testCallByRef() {
  int startValue = 5;
  incrementByValueNumTimesRef(startValue, 2, 10);
  // Verify that startValue has been updated correctly
  assert(startValue == 25);
  std::cout << "testCallByRef Passed!" << std::endl;
}

void testStudiesProgram() {
  student s = {"Bob", "Mathematics", 22};
  assert(studiesProgram(s, "Mathematics") == true); // Should return true
  assert(studiesProgram(s, "Physics") == false);    // Should return false
  std::cout << "studiesProgram test passed." << std::endl;
}

// oppgave 3
void testString() {}

int main() {
  testCallByValue();
  testCallByRef();
  testStudiesProgram();
  return 0;
}