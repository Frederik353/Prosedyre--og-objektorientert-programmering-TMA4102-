#include "EmptyFace.h"
#include "AnimationWindow.h"

void EmptyFace::draw(AnimationWindow &win) {
  Face::draw(win);
  drawMouth(win, mouthPos, radius);
  drawLeftEye(win, leftEyePos, radius);
  drawRightEye(win, rightEyePos, radius);
  for (const auto &feature : drawFunctions) {
    feature(win, center, radius);
  }
}
