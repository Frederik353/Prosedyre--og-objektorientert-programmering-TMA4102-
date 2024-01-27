#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Funksjonen heter 'add', den tar inn to heltall, legger sammen
// tallene og returnerer resultatet, som er et heltall
int add(int a, int b) { return a + b; }

// Funksjonen tar ikke inn noe og returnerer ingenting
// Input kommer fra brukeren av programmet: cin,
// og output skrives til brukeren av programmet: cout.
void inputIntegersAndPrintProduct() {
  int x = 0;
  int y = 0;
  cout << "Skriv inn to heltall: ";
  cin >> x;
  cin >> y;
  int product = x * y;
  cout << x << " * " << y << " = " << product << endl;
}

// #-- -- -- -- -- -- -- -- -- -- -- oppgave 1 -- -- -- -- -- -- -- -- -- -- --

// oppgave 1 b
void inputAndPrintIntager() {
  int x;
  cout << "Skriv inn et heltall: ";
  cin >> x;
  cout << "Du skrev: " << x << endl;
}

// oppgave 1 c
int inputIntager() {
  int x;
  cout << "Skriv inn et heltall: ";
  cin >> x;
  return x;
}

// opppgave 1 d
void inputIntagersAndPrintSum() {
  int x = inputIntager();
  int y = inputIntager();
  int sum = x + y;
  cout << "Summen av tallene er:" << sum << endl;
}

// oppgave 1 e
// I deloppgave d) valgte vi å bruke inputInteger i stedet for
// inputAndPrintInteger fordi vi trenger å bruke de innskrevne tallene for å
// beregne summen. inputInteger returnerer det innskrevne tallet, noe som gjør
// det mulig å lagre og videre bruke disse verdiene noe InputAndPrintIntager
// ikke gjør.

// oppgave 1 f
bool isOdd(int number) { return number % 2 != 0; }

// #-- -- -- -- -- -- -- -- -- -- -- -- oppgave 2 -- -- -- -- -- -- -- -- -- --

// oppgave 2 a

int sumArray(const int *arr, size_t size) {
  int sum = 0;
  for (std::vector<int>::size_type i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

std::vector<int> inputIntagers() {
  std::vector<int> intagers;
  std::string input;
  int value;

  cout << "skriv inn heltall separert med mellomrom: ";

  std::getline(std::cin, input);

  std::istringstream iss(input);
  while (iss >> value) {
    intagers.push_back(value);
  }

  return intagers;
}

int inputAndSumIntagers() {
  std::vector<int> intagers = inputIntagers();
  cout << "du skrev inn:";
  for (std::vector<int>::size_type i = 0; i < intagers.size(); i++) {
    cout << intagers[i] << " ";
  }
  cout << endl;
  int sum = sumArray(intagers.data(), intagers.size());
  cout << "summen av tallene er: " << sum << endl;

  return sum;
}

// oppgave 2 b
int inputAndSumIntegers2() {
  int sum = 0;
  int input;
  bool run = true;
  while (run) {
    cout << "skriv inn et heltall: ";
    cin >> input;
    if (input == 0) {
      run = false;
    } else {
      sum += input;
    }
  }
  cout << "summen av tallene er: " << sum << endl;

  return sum;
}

// oppgave c
// hvis man vet på forhånd hvor mange tall man skal summere funker for loop
// bra hvis ikke er while loop bedre

// oppgave 2 d
double inputDouble() {
  double value;
  cout << "skriv inn et desimaltall: ";
  cin >> value;

  return value;
}

// oppgave 2 e
double convertCurrency(double conversionRate, double value) {
  return value * conversionRate;
}

double inputEuroToNOKandPrint() {
  double value = inputDouble();
  double res = convertCurrency(9.75, value);
  cout << value << " euro er " << res << " NOK" << endl;
  return res;
}

// oppgave f
// fordi valutta regninger ofte inneholder desimaltall, det sagt foretrekker
// banker og finansinstitusjoner å bruke heltall for pengeverdier av grunner
// knyttet til nøyaktighet og sikkerhet. Heltallsaritmetikk er nøyaktig og
// unngår rundingsfeil som kan oppstå med flyttall, noe som er avgjørende for
// å forebygge svindel og feil i finansielle transaksjoner. I tillegg gjør
// bruk av heltall sporing og revisjon av finansielle operasjoner mer
// håndterbart, siden det gir en mer direkte og forutsigbar måte å
// representere pengeverdier på. Dette speiler også hvordan fysiske
// valutaenheter, som cent eller øre, fungerer, og bidrar til konsistens i
// håndteringen av penger både i digitale og fysiske formater. Men hvis dette
// er til en valutta kalkulator funker det fint med desimaltall.

// oppgave 2 g
void printMultiplicationTable() {
  int height, width;
  cout << "skriv inn hoyde og bredde pa tabellen:";
  cin >> height >> width;
  for (int i = 1; i < height + 1; i++) {
    for (int j = 1; j < width + 1; j++) {
      cout << i * j << setw(5);
    }
    cout << setw(0) << endl;
  }
}

// #-- -- -- -- -- -- -- -- -- -- -- -- oppgave 3 -- -- -- -- -- -- -- -- -- --

// oppgave a
double discriminant(double a, double b, double c) { return b * b - 4 * a * c; }

// oppgave b
void printRealRoots(double a, double b, double c) {
  double dis = discriminant(a, b, c);
  if (dis < 0 or a == 0) {
    cout << "ingen reelle rotter" << endl;
    return;
  }
  double root1 = (-b + sqrt(dis)) / (2 * a);
  if (dis == 0) {
    cout << "en reell rot: " << root1 << endl;
    return;
  } else {
    double root2 = (-b - sqrt(dis)) / (2 * a);
    cout << "to reelle rotter: " << root1 << " og " << root2 << endl;
    return;
  }
}

// opppgave c
void solveQuadraticEquation() {
  double a = inputDouble();
  double b = inputDouble();
  double c = inputDouble();
  printRealRoots(a, b, c);
}

// #-- -- -- -- -- -- -- -- -- -- -- -- oppgave 4 -- -- -- -- -- -- -- -- -- --

void drawPythagoras() {

  int w = 800;
  int h = 600;
  AnimationWindow win{100, 100, w, h, "Pythagoras"};

  int vw = w / 100;
  int vh = h / 100;

  Point A{40 * vw, 40 * vh};
  Point B{40 * vw, 60 * vh};
  Point C{60 * vw, 60 * vh};

  win.draw_triangle(A, B, C, Color::black);

  // Draw squares on each side

  double hypotenuse = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
  double angle = atan2(C.y - A.y, C.x - A.x) + M_PI / 2; // Perpendicular angle

  int BCLength = static_cast<int>(sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2)));

  win.draw_quad(B, {B.x, B.y + BCLength}, {C.x, C.y + BCLength}, C,
                Color::red); // Square on BC

  int ABLength = static_cast<int>(sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)));
  win.draw_quad(A, {A.x - ABLength, A.y}, {B.x - ABLength, B.y}, B,
                Color::green);
  // Points for the square on the hypotenuse
  Point D{static_cast<int>(A.x + cos(angle) * -hypotenuse),
          static_cast<int>(A.y + sin(angle) * -hypotenuse)};
  Point E{static_cast<int>(D.x + (C.x - A.x)),
          static_cast<int>(D.y + (C.y - A.y))};

  win.draw_quad(A, D, E, C, Color::blue); // Square on AC
  // win.draw_quad(C, F, G, A, Color::green); // Square on AC

  win.wait_for_close();
}

// #-- -- -- -- -- -- -- -- -- -- -- -- oppgave 5 -- -- -- -- -- -- -- -- -- --

// oppgave 5 a
vector<int> calculateBalance(int inskudd, int rente, int antallAar) {
  vector<int> balance(static_cast<size_t>(antallAar));
  double lastBalance = inskudd;
  for (size_t i = 0; i < static_cast<size_t>(antallAar); i++) {
    lastBalance *= 1 + (static_cast<double>(rente) / 100);
    balance[i] = static_cast<int>(lastBalance);
    // balance[i] = inskudd * pow(1 + (static_cast<double>(rente) / 100), i);
  }
  return balance;
}

// oppgave 5 b
void printBalance(vector<int> balance) {
  cout << "aar" << setw(10) << "saldo" << endl;
  for (size_t i = 0; i < balance.size(); i++) {
    cout << i << setw(12) << balance[i] << endl;
  }
}

// oppgave 5 c
// cpp har ikke en innebygd funksjon til å skrive ut innholdet til en vektor
// dirkete til std::ostream (som cout som arver fra ostream, andre eksempler er
// cerr clog ofstream osv)

// #-- -- -- -- -- -- -- -- -- -- -- -- presentation -- -- -- -- -- -- -- -- --

void showTask(int task, char subTask) {
  cout << " ------ Oppgave " << task << " " << subTask << " ------" << endl;

  switch (task) {
  case 1: {
    switch (subTask) {
    case 'b': {
      cout << "input and print int" << endl;
      inputAndPrintIntager();

      break;
    }
    case 'c': {
      cout << "input int" << endl;
      inputIntager();
      break;
    }
    case 'd': {
      cout << "input and print sum" << endl;
      inputIntagersAndPrintSum();

      break;
    }
    case 'f': {
      cout << "is odd" << endl;
      for (int i = 0; i < 16; i++) {
        cout << i << " " << (isOdd(i) ? "true" : "false") << endl;
      }
    }
    default: {
      cout << "invalid subtask" << endl;
      break;
    }
    }
    break;
  }
  case 2: {
    switch (subTask) {
    case 'a': {
      cout << "input and sum (for) array sum" << endl;
      inputAndSumIntagers();
      break;
    }
    case 'b': {
      cout << "input and sum (while)" << endl;
      inputAndSumIntegers2();
      break;
    }
    case 'e': {
      cout << "eur to nok" << endl;
      inputEuroToNOKandPrint();
      break;
    }
    case 'g': {
      cout << "multiplication table" << endl;
      printMultiplicationTable();
      break;
    }
    default: {
      cout << "invalid subtask" << endl;

      break;
    }
    }
    break;
  }
  case 3: {
    switch (subTask) {
    case 'a': {
      cout << "gitt: a = 2, b = 3, c = 4" << endl;
      cout << "er diskriminanten: " << discriminant(2, 5, 4) << endl;
      break;
    }
    case 'b': {
      cout << "print roots and get input (b-d)" << endl;
      solveQuadraticEquation();
      break;
    }
    case 'e': {
      cout << "rottene til x^2 + 2x + 4 = 0 er: ";
      printRealRoots(1, 2, 4);
      cout << "rottene til 4x^2 + 4x + 1 = 0 er: ";
      printRealRoots(4, 4, 1);
      cout << "rottene til 8x^2 + 4x - 1 = 0 er:";
      printRealRoots(8, 4, -1);
      break;
    }
    default: {
      cout << "invalid subtask" << endl;

      break;
    }
    }
    break;
  }
  case 4: {
    switch (subTask) {
    case 'a': {

      cout << "pytagoras visualisering" << endl;
      drawPythagoras();

      break;
    }
    default: {
      cout << "invalid subtask" << endl;

      break;
    }
    }
    break;
  }
  case 5: {
    switch (subTask) {
    case 'a': {

      cout << "calculate balance, (5000 in, 3\% intrest, 10 year  )" << endl;
      vector<int> balance = calculateBalance(5000, 30, 10);
      printBalance(balance);

      break;
    }
    case 'd': {

      cout << "debugging" << endl;

      vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      // size_t feil dtype
      // <= gir feil lengde
      for (size_t i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
      }
      break;
    }

    default: {
      cout << "invalid subtask" << endl;

      break;
    }
    }
    break;
  }
  default: {
    cout << "invalid task" << endl;

    break;
  }
  }
}

int main() {

  std::vector<std::pair<int, std::vector<char>>> tasks = {
      {1, {'b', 'c', 'd', 'f'}}, {2, {'a', 'b', 'e', 'g'}},
      {3, {'a', 'b', 'e'}},      {4, {'a'}},
      {5, {'a', 'd'}},
  };

  std::cout << "Vil du kjore alle oppgaver fra valgt oppgave? (ja/nei): ";
  std::string response;
  std::cin >> response;
  bool runAll = (response == "ja");

  if (runAll) {
    for (const auto &taskPair : tasks) {
      const int &task = taskPair.first;
      const std::vector<char> &subTasks = taskPair.second;

      for (const char &subTask : subTasks) {
        showTask(task, subTask);
      }
    }
  } else {
    cout << "Velg oppgave: ";
    int task;
    cin >> task;

    cout << "Velg underoppgave oppgave: ";
    char subTask;
    cin >> subTask;

    showTask(task, subTask);
  }

  // int sumOfOneAndTwo = add(1, 2);
  // cout << "1 + 2 = " << sumOfOneAndTwo << endl;
  // cout << "2 + 2 = " << add(2, 2) << endl;
  // inputIntegersAndPrintProduct();
  return 0;
}