
#pragma once
#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include <map>
#include <string>

struct Config {
  Color ballColorUp;
  Color ballColorDown;
  int velocity;
};

// extern std::map<int, Color> colorMap;
void bouncingBall();