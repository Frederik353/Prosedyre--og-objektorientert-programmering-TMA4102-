#include "cannonball.h"
#include "std_lib_facilities.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

void testDeviation(double compareOperand, double toOperand, double maxError,
                   string name) {
  double error = abs(compareOperand - toOperand);
  if (error < maxError) {
    cout << name << " passed with error rate: " << error << endl;
  } else {
    cout << name << " failed with error rate: " << error << endl;
  }
}

void test() {
  // t= 2.5
  // antar startposisjon er 0,0
  double maxError = 0.0001;
  testDeviation(0.475, velY(50.0, 2.5), maxError, "velY");
  testDeviation(125.0, posX(0.0, 50.0, 2.5), maxError, "posX");
  testDeviation(31.84, posY(0.0, 50.0, 2.5), maxError, "posY");

  // t= 5
  testDeviation(-24.05, velY(50.0, 5.0), maxError, "velY");
  testDeviation(250.0, posX(0.0, 50.0, 5.0), maxError, "posX");
  testDeviation(2.375, posY(0.0, 50.0, 5.0), maxError, "posY");
}

// t = 2.5 t = 5.0
// velX 50.0 50.0
// velY 0.475 -24.05
// posX 125.0 250.0
// posY 31.84 2.375

void testDegToRad() {
  assert(degToRad(0) == 0);
  assert(degToRad(180) == M_PI);
  assert(degToRad(90) == M_PI / 2);
}

void testGetVelocityX() {
  static_assert(std::is_same<decltype(getVelocityX(0, 10)), double>::value,
                "x is not an int");

  assert(getVelocityX(0, 10) == 10);
  cerr << "get velocity x 0 10: " << getVelocityX(90, 10) << endl;
  cerr << "get velocity x 90 10: " << std::setprecision(10)
       << getVelocityX(90, 10) << endl;

  const double epsilon = 1e-6;
  assert(std::abs(getVelocityX(90, 10) - 6.12303e-16) < epsilon);
}

void testGetVelocityY() {
  assert(getVelocityY(0, 10) == 0.0);
  assert(getVelocityY(90, 10) == 10.0);
}

void testGetVelocityVector() {

  vector<double> testVec;
  testVec = getVelocityVector(0, 10);
  assert(testVec[0] == 10 && testVec[1] == 0);

  testVec = getVelocityVector(90, 10);

  for (auto i : testVec) {
    cerr << i << endl;
  }

  const double epsilon = 1e-6;
  assert(std::abs(testVec[0] - 6.12303e-16) < epsilon &&
         std::abs(testVec[1] - 10) < epsilon);
}

void testGetDistanceTraveled() {
  // Todo
}

void testTargetPractice() {
  // Todo
}

int main() {
  testDegToRad();
  testGetVelocityX();
  testGetVelocityY();
  testGetVelocityVector();
  test();

  cout << "All tests passed!" << endl;
  return 0;
}
