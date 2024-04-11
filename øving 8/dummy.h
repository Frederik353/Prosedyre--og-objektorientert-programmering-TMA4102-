#pragma once
#include <iostream>
#include <utility>

class Dummy {
public:
  int *num;
  Dummy() { num = new int{0}; }
  Dummy(const Dummy &d) {
    num = new int;
    *num = *d.num;
  };
  ~Dummy() { delete num; }
  Dummy operator=(const Dummy &m);
};
