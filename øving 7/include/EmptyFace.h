#pragma once
#include "AnimationWindow.h"
#include "Face.h"
#include <functional>
#include <vector>

class EmptyFace : public Face {
private:
  Point leftEyePos;
  Point rightEyePos;
  Point mouthPos;
  std::function<void(AnimationWindow &, Point, int)> drawLeftEye;
  std::function<void(AnimationWindow &, Point, int)> drawRightEye;
  std::function<void(AnimationWindow &, Point, int)> drawMouth;
  std::vector<std::function<void(AnimationWindow &, Point, int)>> drawFunctions;

public:
  EmptyFace(Point c, int r, Color fc, Point le,
            std::function<void(AnimationWindow &, Point, int)> dle, Point re,
            std::function<void(AnimationWindow &, Point, int)> dre, Point m,
            std::function<void(AnimationWindow &, Point, int)> dm)
      : Face(c, r, fc), leftEyePos{c.x - le.x, c.y - le.y},
        rightEyePos{c.x + re.x, c.y - re.y}, mouthPos{c.x + m.x, c.y + m.y},
        drawLeftEye(dle), drawRightEye(dre), drawMouth(dm){};

  void draw(AnimationWindow &win) override;
};
