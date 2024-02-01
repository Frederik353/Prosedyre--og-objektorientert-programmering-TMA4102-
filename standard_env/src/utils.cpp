#include "utils.h"
#include <iostream>
#include <random>
// #include <utility>

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
  for (int i = 0; i < numTimes; i++) {
    startValue += increment;
  }
  return startValue;
}

int incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
  for (int i = 0; i < numTimes; i++) {
    startValue += increment;
  }
  return startValue;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
  //   std::swap(a,b);
}

// oppgave 2 b

void printStudent(student s) {
  std::cout << "Name: " << s.name << std::endl;
  std::cout << "Study program: " << s.studyProgram << std::endl;
  std::cout << "Age: " << s.age << std::endl;
}

// oppgave 2 c

bool studiesProgram(student s, std::string studyProgram) {
  return s.studyProgram == studyProgram;
}

// oppgave b b
std::string randomizeString(int length, char lower, char upper) {
  if (upper < lower) {
    std::swap(upper, lower);
  }
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(lower, upper);

  std::string randomString;
  for (int i = 0; i < length; i++) {
    char c = distribution(generator);
    std::cout << c;
    randomString += c;
  }
  std::endl;
}

std::string