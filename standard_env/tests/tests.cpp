#include "tests.h"
#include "mastermind.h"
#include "utils.h"
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void testCallByValue() {
  int startValue = 5;
  int result = incrementByValueNumTimes(startValue, 2, 10);
  assert(result == 25);
  assert(startValue == 5);
  std::cout << "testCallByValue Passed!" << std::endl;
}

void testCallByRef() {
  int startValue = 5;
  incrementByValueNumTimesRef(startValue, 2, 10);
  assert(startValue == 25);
  std::cout << "testCallByRef Passed!" << std::endl;
}

void testStudieProgram() {
  student s = {"Bob", "Matematikk", 22};
  assert(studieProgram(s, "Matematikk") == true);
  assert(studieProgram(s, "fysikk") == false);
  std::cout << "studieProgram test passed." << std::endl;
}

// oppgave 3
void testString() {
  std::cout << "test random string" << std::endl;
  std::string grades = randomizeString(8, 'A', 'F');
  std::vector<int> counter(6);
  int sum = 0;
  for (int i = static_cast<int>('a'); i <= static_cast<int>('f'); i++) {
    counter[i] = countChar(grades, static_cast<char>(i));
    sum += counter[i] * (6 - (i - static_cast<int>('a')));
    std::cout << counter[i] << " * " << (6 - (i - static_cast<int>('a')))
              << std::endl;
  }
  std::cout << sum << std::endl;
  double average =
      static_cast<double>(sum) / static_cast<double>(grades.length());
  std::cout << "snittkarakter: " << average << std::endl;
}

void countChartest() {
  std::string text = "AAaabbBbAA"; // 5 A, 4 B
  assert(countChar(text, 'A') == 6);
  assert(countChar(text, 'b') == 4);
  std::cout << "countChar passed" << std::endl;
}

void checkCharactersTest() {

  std::cout << "check characters test" << std::endl;
  std::cout << "Test 1: " << checkCharacters('a', 'z', "hello", "hello")
            << " (Expected: 5)" << std::endl;
  std::cout << "Test 2: " << checkCharacters('a', 'z', "hello", "world")
            << " (Expected: 2)" << std::endl;
  std::cout << "Test 3: " << checkCharacters('a', 'z', "abc", "xyz")
            << " (Expected: 0)" << std::endl;
  std::cout << "Test 4: " << checkCharacters(' ', '~', "h@llo", "w@rld")
            << " (Expected: 2)" << std::endl;
  std::cout << "Test 5: " << checkCharacters('A', 'Z', "HELLO", "hello")
            << " (Expected: 0)" << std::endl;
  std::cout << "Test 6: " << checkCharacters('\0', '\xFF', "hello", "world")
            << " (Expected: 1)" << std::endl;
  std::cout << "Test 7: " << checkCharacters('a', 'z', "", "")
            << " (Expected: 0)" << std::endl;
  std::cout << "Test 8: " << checkCharacters('a', 'z', "hello", "")
            << " (Expected: 0)" << std::endl;
}

int main() {
  testCallByValue();
  testCallByRef();
  testStudieProgram();
  testString();
  countChartest();
  checkCharactersTest();

  return 0;
}
