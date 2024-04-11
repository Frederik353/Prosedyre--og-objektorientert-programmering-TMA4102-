#pragma once
#include "AnimationWindow.h"
#include "Face.h"

class EmptyFace : public Face {
private:
  Point leftEyePos;
  Point rightEyePos;
  int leftEyeRadius;
  int rightEyeRadius;

public:
  EmptyFace(Point c, int r, Color fc, Point le, Point re, int ler, int rer)
      : Face(c, r, fc), leftEyePos{c.x - le.x, c.y - le.y},
        rightEyePos{c.x + re.x, c.y - re.y}, leftEyeRadius{ler},
        rightEyeRadius{rer} {};

  void draw(AnimationWindow &win) override;
};
