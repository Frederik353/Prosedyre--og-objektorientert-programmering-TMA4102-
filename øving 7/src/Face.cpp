#include "Face.h"
#include "AnimationWindow.h"

void Face::draw(AnimationWindow &win) {
  win.draw_circle(center, radius, Color::yellow);
}
