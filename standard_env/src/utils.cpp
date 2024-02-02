#pragma once

#include "utils.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <string>

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

bool studieProgram(student s, std::string studyProgram) {
  return s.studyProgram == studyProgram;
}

// oppgave b b
std::string randomizeString(int length, char lower, char upper) {
  lower = std::toupper(lower);
  upper = std::toupper(upper);
  if (upper < lower) {
    std::swap(upper, lower);
  }
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(lower, upper);

  std::string randomString;
  for (int i = 0; i < length; i++) {
    char c = static_cast<char>(distribution(generator));
    std::cout << c;
    randomString += c;
  }
  std::cout << std::endl;
  return randomString;
}

std::string readInputToString(int length, char lower, char upper) {

  lower = std::toupper(lower);
  upper = std::toupper(upper);
  std::string input;
  char c;
  int count = 0;
  while (count < length) {
    std::cin >> c;
    c = std::toupper(c);
    if (c >= lower && c <= upper) {
      input += c;
      count++;
    }
  }
  return input;
}

int countChar(std::string str, char c) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::toupperj(c); });
  c = std::toupper(c);
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == c) {
      count++;
    }
  }
  return count;
}
