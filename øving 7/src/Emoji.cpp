#include "Emoji.h"
#include "AnimationWindow.h"
#include "EmptyFace.h"

void smilingEye(AnimationWindow &win, Point p, int r) {
  win.draw_circle(Point(p.x, p.y - r * 0.1), r / 4, Color::white);
  win.draw_circle(Point(p.x, p.y - r * 0.1), r / 8, Color::black);
}

void smilingMouth(AnimationWindow &win, Point p, int r) {
  win.draw_circle(p, static_cast<int>(r * 0.75), Color::white);
  win.draw_circle(Point(p.x, p.y - r * 0.2), static_cast<int>(r * 0.8),
                  Color::yellow);
}

void happyMouth(AnimationWindow &win, Point center, int radius) {
  win.draw_arc(center, radius * 0.5, radius * 0.3, 200, 340, Color::black);
}

// ----------------------------

void sadEyes(AnimationWindow &win, Point p, int r) {
  win.draw_arc(Point(p.x, p.y - r * 0.1), r / 10, r / 5, 45, 135, Color::black);
}

void sadMouth(AnimationWindow &win, Point center, int radius) {
  win.draw_arc(center, radius * 0.5, radius * 0.3, 20, 160, Color::black);
}

// ----------------------------

void angryEyeL(AnimationWindow &win, Point eyeCenter, int emojiRadius) {
  int eyeRadius = emojiRadius /
                  10; // Adjust the eye radius based on your design preferences

  // Angled line for the left angry eye
  win.draw_line(Point(eyeCenter.x - eyeRadius, eyeCenter.y - eyeRadius),
                Point(eyeCenter.x + eyeRadius, eyeCenter.y), Color::black);
}

void angryEyeR(AnimationWindow &win, Point eyeCenter, int emojiRadius) {
  int eyeRadius = emojiRadius /
                  10; // Adjust the eye radius based on your design preferences

  // Angled line for the right angry eye
  win.draw_line(Point(eyeCenter.x - eyeRadius, eyeCenter.y),
                Point(eyeCenter.x + eyeRadius, eyeCenter.y - eyeRadius),
                Color::black);
}

void angryMouth(AnimationWindow &win, Point mouthCenter, int emojiRadius) {
  // The mouth is a segment of an arc, so the radius can be scaled relative to
  // the emoji's radius
  int mouthWidth = emojiRadius * 0.4;
  int mouthHeight = emojiRadius * 0.25;

  // Draw the arc representing the mouth
  win.draw_arc(mouthCenter, mouthWidth, mouthHeight, 20, 160, Color::black);
}

// ----------------------------

void winkingEye(AnimationWindow &win, Point eyeCenter, int emojiRadius) {
  // Calculate the line's length based on the emoji's radius, adjust as needed
  int lineLength = emojiRadius / 10;

  // Draw a line representing the winking eye
  win.draw_line(Point(eyeCenter.x - lineLength, eyeCenter.y),
                Point(eyeCenter.x + lineLength, eyeCenter.y), Color::black);
}

// ----------------------------

void surprisedMouth(AnimationWindow &win, Point center, int radius) {
  win.draw_circle(center, radius / 4, Color::black);
}

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 700;
Point c = Point(static_cast<int>(xmax / 2), static_cast<int>(ymax / 2));
int sx = xmax / 6;
int sy = ymax / 4;
int emojiRadius = sx / 2;
Color backgroundColor = Color::green;

void emojiMain() {
  const Point tl{100, 100};
  const string win_label{"Emoji factory"};
  AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
  Point ep = Point{static_cast<int>(sx * 0.2), static_cast<int>(sx * 0.2)};
  Point mp = Point(0, static_cast<int>(sx * 0.1));

  win.draw_rectangle(Point(0, 0), xmax, ymax, backgroundColor);

  EmptyFace emptyFace(Point{sx, sy}, emojiRadius, Color::yellow, ep, smilingEye,
                      ep, smilingEye, mp, smilingMouth);
  emptyFace.draw(win);

  EmptyFace happyFace(Point{3 * sx, sy}, emojiRadius, Color::yellow, ep,
                      smilingEye, ep, smilingEye, mp, happyMouth);
  happyFace.draw(win);

  EmptyFace sadFace(Point{5 * sx, sy}, emojiRadius, Color::yellow, ep, sadEyes,
                    ep, sadEyes, mp, sadMouth);
  sadFace.draw(win);

  EmptyFace angryFace(Point{sx, 3 * sy}, emojiRadius, Color::yellow, ep,
                      angryEyeL, ep, angryEyeR, mp, angryMouth);
  angryFace.draw(win);

  EmptyFace winkingFace(Point{3 * sx, 3 * sy}, emojiRadius, Color::yellow, ep,
                        smilingEye, ep, winkingEye, mp, happyMouth);
  winkingFace.draw(win);

  EmptyFace surprisedFace(Point{5 * sx, 3 * sy}, emojiRadius, Color::yellow, ep,
                          smilingEye, ep, smilingEye, mp, surprisedMouth);
  surprisedFace.draw(win);

  win.wait_for_close();
}
