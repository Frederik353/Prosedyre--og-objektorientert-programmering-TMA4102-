#include "bouncingBall.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800};
constexpr int BOUNCE_WINDOW_HEIGHT{500};

// oppgave 4 b
std::istream &operator>>(std::istream &is, Config &cfg) {
  int colorUp, colorDown, velocity;
  is >> colorUpInt >> colorDownInt >> velocity;

  cfg.ballColorUp = colorMap.at(colorUpInt);
  cfg.ballColorDown = colorMap.at(colorDownInt);
  cfg.velocity = velocity;

  return is;
}

std::filesystem::path config_file{"konfigurasjon.txt"};
std::ifstream file(config_file);
if (!file) {
  std::cerr << "Kunne ikke åpne filen " << config_file << std::endl;
  return 1;
}
std::vector<Config> configs;
Config tempConfig;
while (file >> tempConfig) {
  configs.push_back(tempConfig);
}

void bouncingBall() {
  AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y,
                         BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT,
                         "Bouncing ball"};

  // oppgave 4 a
  const int radius{30};
  int alpha{1};
  int velocity{2};
  Color colour_up{Color::blue};
  Color colour_down{Color::blue};
  int x{0};
  int y{360};
  int increment_x{0};
  int increment_y{0};
  int count_bounce_top{0};
  int count_bounce_bottom{0};
  int count_num_passes{0};

  // read from configuration file
  std::filesystem::path config_file{"konfigurasjon.txt"};
  std::ifstream is{config_file};
  Config slow;

  if (!file) {
    std::cerr << "Kunne ikke åpne filen " << config_file << std::endl;
    return;
  }

  std::vector<Config> configs;
  Config tempConfig;
  while (file >> tempConfig) {
    configs.push_back(tempConfig);
  }
  if (configs.empty()) {
    std::cerr << "Ingen konfigurasjoner funnet i filen." << std::endl;
    return;
  }

  // Oppdaterer variabler med den første konfigurasjonen
  color_up = configs[0].ballColorUp;
  color_down = configs[0].ballColorDown;
  velocity = configs[0].velocity;

  // initialise the run
  while (!window.should_close()) {
    // determine increments based on the velocity
    increment_x = velocity * cos(alpha);
    increment_y = velocity * sin(alpha);

    // movement i x-direction
    if ((increment_x + x) > window.width()) {
      // reached right side - wrap around to the leftmost
      x = 0;
      // increment counter which counts number of full left-to-right passes
      count_num_passes++;
      // alternate between slow and fast configuration every fifth pass
      if (count_num_passes % 5 == 0) {
        index = (count_num_passes % 5) % 2;
        color_up = configs[index].ballColorUp;
        color_down = configs[index].ballColorDown;
        velocity = configs[index].velocity;

        // change configuration
        // update both velcity and colors
      }
    } else {
      // moving rightwards
      x += increment_x;
    }

    // movement i y-direction
    if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
      if (y - increment_y < 0) {
        count_bounce_top++;
        y = 0;
      } else {
        // move upwards
        y -= increment_y;
      }
    } else {
      if (y + increment_y > window.height()) {
        count_bounce_bottom++;
        y = window.height();
      } else {
        // move downward
        y += increment_y;
      }
    }

    window.next_frame();
  }
}
