#include "cannonball_viz.h"
#include "std_lib_facilities.h"
#include "utils.h"
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
  int h = static_cast<int>(std::round((time / 3600)));
  int min = static_cast<int>(std::round((time - h * 3600) / 60));
  int sec = static_cast<int>(std::round(time - h * 3600 - min * 60));
  if (h > 0) {
    cout << h << " timer, ";
  }
  if (min > 0) {
    cout << min << " minutter ";
  }
  if (h != 0 || min != 0) {
    cout << "og ";
  }
  cout << sec << " sekunder";
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
  cout << "skriv inn en vinkel i grader: ";
  cin >> value;
  return value;
}

// Ber brukeren om en startfart
double getUserInputInitVelocity() {
  double value;
  cout << "skriv inn en startfart: ";
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

void playTargetPractice() {
  int target = randomWithLimits(100, 1000);
  bool hit = false;
  for (int i = 0; i < 10; i++) {
    double theta = getUserInputTheta();
    double velocity = getUserInputInitVelocity();
    vector<double> velocityVector = getVelocityVector(theta, velocity);

    double distanceToTarget =
        targetPractice(target, velocityVector[0], velocityVector[1]);
    if (abs(distanceToTarget) < 5) {
      hit = true;
      break;
    }

    cout << "-------------------------------" << endl << endl;
    cout << "distanse til maal: " << distanceToTarget << endl;
    cout << "skuddet var for " << (distanceToTarget > 0 ? "kort" : "langt")
         << endl;

    cout << "kulen brukte: ";
    printTime(flightTime(velocityVector[1]));
    cout << " i luften" << endl;
    // 120 hz
    int hz = 60;
    double speed = 1;
    double vizTime = (flightTime(velocityVector[1]) / speed);
    cannonBallViz(target, 1000, velocityVector[0], velocityVector[1],
                  static_cast<int>(std::ceil(vizTime)) * hz, vizTime);
  }

  if (hit) {

    cout << "Gratulerer, du traff!" << endl;
  } else {
    cout << "" << endl;
  }
}