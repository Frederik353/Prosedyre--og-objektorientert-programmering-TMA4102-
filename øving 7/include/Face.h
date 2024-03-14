#pragma once
#include "AnimationWindow.h"
#include "Emoji.h"
#include <array>

class Face : public Emoji {
protected:
  Point center;
  int radius;
  Color faceColor;

public:
  Face(Point c, int r, Color fc) : center{c}, radius{r}, faceColor{fc} {};
  virtual void draw(AnimationWindow &) = 0;
};