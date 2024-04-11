#pragma once
#include "AnimationWindow.h"
#include "Face.h"
<<<<<<< HEAD
=======
#include <functional>
#include <vector>
>>>>>>> 9f68d2af774a82832a9195216befe9382088acac

class EmptyFace : public Face {
private:
  Point leftEyePos;
  Point rightEyePos;
<<<<<<< HEAD
  int leftEyeRadius;
  int rightEyeRadius;

public:
  EmptyFace(Point c, int r, Color fc, Point le, Point re, int ler, int rer)
      : Face(c, r, fc), leftEyePos{c.x - le.x, c.y - le.y},
        rightEyePos{c.x + re.x, c.y - re.y}, leftEyeRadius{ler},
        rightEyeRadius{rer} {};
=======
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
>>>>>>> 9f68d2af774a82832a9195216befe9382088acac

  void draw(AnimationWindow &win) override;
};
