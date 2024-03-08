#include "Emoji.h"
#include "AnimationWindow.h"
#include "EmptyFace.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

void emojiMain() {

  const Point tl{100, 100};
  const string win_label{"Emoji factory"};
  AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

  /* TODO:
   *  - initialiser emojiene
   *  - Tegn emojiene til vinduet
   **/
  EmptyFace emptyFace(
      Point{static_cast<int>(xmax / 2), static_cast<int>(ymax / 2)},
      static_cast<int>((ymax / 2) - 100), Color::yellow, Point{100, 100},
      Point{100, 50}, 100, 50);
  emptyFace.draw(win);

  win.wait_for_close();
}
