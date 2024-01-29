// Utdelt kode, visualisering av cannonball-spillet i øving 3.
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef DELETE

#include "AnimationWindow.h"

#include "cannonball.h"
#include "cannonball_viz.h"
#include <chrono>
#include <iostream>
// #include <thread>

// Pass på sirkulaer headerinkludering.
using namespace TDT4102;

void cannonBallViz(double targetPosition, int fieldLength, double initVelocityX,
                   double initVelocityY, int timeSteps, double vizTime) {
  const unsigned long sleepTime = static_cast<unsigned long>(
      (vizTime * 1000) / timeSteps); // round down for code execution time

  constexpr int w_width = 800;
  constexpr int w_height = 500;
  AnimationWindow window(
      100, 100, w_width, w_height,
      "Cannonball Visualizer"); // 100, 100 angir x og y, som er overst til
                                // venstre i vinduet
  window.keep_previous_frame(false);
  unsigned long timeToSleep;

  // forste tidssteg er 0
  for (int i = 0; i <= timeSteps; ++i) {
    auto start = std::chrono::high_resolution_clock::now();
    // Lag en ny frame ved starten av løkken slik at siste bildet er vist naar
    // animasjonen er ferdig
    window.next_frame();

    // Plot target. targetPosition er [100, 1000] i main programmet
    // denne funksjonen mapper 0 til 0, og fieldLength til w_width
    int target_x = static_cast<int>((targetPosition * w_width) / fieldLength);
    window.draw_rectangle(Point{target_x - 10, w_height - 20}, 20, 20,
                          Color::dark_green);

    double time = i * (flightTime(initVelocityY) / timeSteps);

    // maa skalere x til w_width, som beskrevet over
    int xPos =
        static_cast<int>(posX(0, initVelocityX, time) * w_width) / fieldLength;
    window.draw_circle(
        Point{xPos, static_cast<int>(w_height - posY(0, initVelocityY, time))},
        8, Color::red);

    // std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
            .count();
    // std::cout << "Time taken by code: " << duration.count() << "
    // milliseconds" << std::endl;
    if (duration >= sleepTime) {
      timeToSleep = 0; // or a minimal value, e.g., 1
    } else {
      timeToSleep = sleepTime - static_cast<unsigned long>(duration);
    }

    Sleep(timeToSleep);
  }

  std::cout << std::endl << "Close the window to continue." << std::endl;
  window.wait_for_close();
}
