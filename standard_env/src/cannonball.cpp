#include "std_lib_facilities.h"
#include <cmath>
#include <vector>

using namespace std;

// oppgave 1 a
double acclY() { return -9.81; }

// oppgave 1 b
double velY(double initVelocityY, double time) {
  return initVelocityY + acclY() * time;
}

// oppgave 1 c
double posY(double initPositionY, double initVelocityY, double time) {
  return initPositionY + (initVelocityY * time + 0.5 * acclY() * time * time);
}

double posX(double initPositionX, double initVelocityX, double time) {
  return initPositionX + (initVelocityX * time);
}

// oppgave 1 d
void printTime(double time) {
  int hours = static_cast<int>(std::round((time / 3600)));
  int minutes = static_cast<int>(std::round((time - hours * 3600) / 60));
  int seconds =
      static_cast<int>(std::round(time - hours * 3600 - minutes * 60));
  cout << "Time: " << hours << " hours, " << minutes << " minutes, " << seconds
       << " seconds" << endl;
}

// oppgave 1 e
double flightTime(double initVelocityY) { return -2 * initVelocityY / acclY(); }

// #-- -- -- -- -- -- -- -- -- -- -- -- oppgave 4 -- -- -- -- -- -- -- -- -- --

// oppgave 4 a

double inputDouble() {
  double value;
  cout << "skriv inn et desimaltall: ";
  cin >> value;

  return value;
}

// Ber brukeren om en vinkel i grader
double getUserInputTheta() {
  double value;
  cout << "skriv inn en vinkel i grader:";
  cin >> value;
  return value;
}

// Ber brukeren om en startfart
double getUserInputInitVelocity() {
  double value;
  cout << "skriv inn en startfart:";
  cin >> value;
  return value;
}
// Konverterer fra grader til radianer
double degToRad(double deg) { return deg * M_PI / 180; }

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity) {
  return initVelocity * cos(degToRad(theta));
}

double getVelocityY(double theta, double initVelocity) {
  return initVelocity * sin(degToRad(theta));
}

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
// x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity) {
  vector<double> velocityVector(2);

  velocityVector[0] = (getVelocityX(theta, initVelocity));
  velocityVector[1] = (getVelocityY(theta, initVelocity));

  return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY) {
  double time = flightTime(velocityY);
  return posX(0, velocityX, time);
}

double targetPractice(double distanceToTarget, double velocityX,
                      double velocityY) {
  double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
  return distanceToTarget - distanceTraveled;
}