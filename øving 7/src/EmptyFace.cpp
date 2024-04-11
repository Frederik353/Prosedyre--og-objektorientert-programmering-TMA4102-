#include "EmptyFace.h"
#include "AnimationWindow.h"

void EmptyFace::draw(AnimationWindow &win) {
  Face::draw(win);
<<<<<<< HEAD

  win.draw_circle(Point(center.x, center.y + 40),
                  static_cast<int>(radius * 0.75), Color::white);
  win.draw_circle(Point(center.x, center.y - 40),
                  static_cast<int>(radius * 0.8), Color::yellow);

  // eyes
  win.draw_circle(leftEyePos, leftEyeRadius, Color::white);
  win.draw_circle(leftEyePos, leftEyeRadius / 5, Color::black);
  win.draw_circle(rightEyePos, rightEyeRadius, Color::white);
  win.draw_circle(rightEyePos, rightEyeRadius / 3, Color::black);
=======
  drawMouth(win, mouthPos, radius);
  drawLeftEye(win, leftEyePos, radius);
  drawRightEye(win, rightEyePos, radius);
  for (const auto &feature : drawFunctions) {
    feature(win, center, radius);
  }
>>>>>>> 9f68d2af774a82832a9195216befe9382088acac
}
