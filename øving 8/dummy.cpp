#include "dummy.h"

Dummy Dummy::operator=(const Dummy &d) {
  if (this != &d) {
    delete num;
    num = new int;
    *num = *d.num;
  }
  return *this;
}

void dummyTest() {
  Dummy a;
  *a.num = 4;
  Dummy b{a};
  Dummy c;
  c = a;
  std::cout << "a: " << *a.num << '\n';
  std::cout << "b: " << *b.num << '\n';
  std::cout << "c: " << *c.num << '\n';
  *b.num = 3;
  *c.num = 5;
  std::cout << "a: " << *a.num << '\n';
  std::cout << "b: " << *b.num << '\n';
  std::cout << "c: " << *c.num << '\n';

  //   std::cout << "a: " << *a.num << std::endl;
  //   std::cout << "b: " << *b.num << std::endl;
  //   std::cout << "c: " << *c.num << std::endl;
  //   *b.num = 3;
  //   *c.num = 5;
  //   std::cout << "a: " << *a.num << std::endl;
  //   std::cout << "b: " << *b.num << std::endl;
  //   std::cout << "c: " << *c.num << std::endl;
}

int main() {
  dummyTest();
  return 0;
}

/*
oppgave 3 a / b
a = 4
b = a # 4
c = a # 4
b = 3 => a = b = 3
c = 5 => a = b = 5
alle pekte på samme minneadresse, så endring i en endrer alle

forventer derfor først 4, 4, 4 så 5, 5, 5
men siden \n brukes i stead for std::endl vil ikke output bufferen flushes med
en gang, vanligvis vil bufferen flushes når programet avsluttes, men siden alle
pekerne peker på samme minneadresse vil dette føre til at programmet prøver å
fri samme minneadresse 3 ganger. Dette vil gi en error som vil avslutte
programmet før bufferen flushes, så vi vil ikke se noen output.


*/