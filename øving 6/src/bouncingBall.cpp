#include "bouncingBall.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800};
constexpr int BOUNCE_WINDOW_HEIGHT{500};

std::map<int, Color> colorMap = {
    {1, Color::red}, {2, Color::green}, {3, Color::blue}, {4, Color::yellow}};

// oppgave 4 b
std::istream &operator>>(std::istream &is, Config &cfg) {
  int colorUpInt, colorDownInt, velocity;
  is >> colorUpInt >> colorDownInt >> velocity;

  cfg.ballColorUp = colorMap.at(colorUpInt);
  cfg.ballColorDown = colorMap.at(colorDownInt);
  cfg.velocity = velocity;

  return is;
}

/*

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
*/

void bouncingBall() {
  AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y,
                         BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT,
                         "Bouncing ball"};

  // oppgave 4 a
  const int radius{30};
  int alpha{1};
  int velocity{2};
  Color colorUp{Color::blue};
  Color colorDown{Color::blue};
  int x{0};
  int y{360};
  int increment_x{0};
  int increment_y{0};
  int count_bounce_top{0};
  int count_bounce_bottom{0};
  int count_num_passes{0};

  //   std::filesystem::path config_file{"konfigurasjon.txt"};
  std::ifstream is{"./konfigurasjon.txt"};

  if (!is) {
    // std::cerr << "Kunne ikke apne filen " << config_file << std::endl;
    return;
  }

  std::vector<Config> configs;
  Config tempConfig;
  while (is >> tempConfig) {
    configs.push_back(tempConfig);
  }

  if (configs.empty()) {
    std::cerr << "Ingen konfigurasjoner funnet i filen." << std::endl;
    return; // As above, ensure this matches the expected behavior of your
            // function
  }

  // Update variables with the first configuration
  colorUp = configs[0].ballColorUp;
  colorDown = configs[0].ballColorDown;
  velocity = configs[0].velocity;

  Color ballColor = colorUp;
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

      //   std::cout << "count num passes: " << count_num_passes << std::endl;
      //   std::cout << "mod 5: " << count_num_passes % 5 << std::endl;
      if (count_num_passes % 5 == 0) {
        int index = (count_num_passes / 5) % configs.size();
        std::cout << "index: " << index << std::endl;
        colorUp = configs[index].ballColorUp;
        colorDown = configs[index].ballColorDown;
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
      if (y - increment_y - radius < 0) {
        count_bounce_top++;
        y = 0 + radius;
        ballColor = colorDown;
      } else {
        // move upwards
        y -= increment_y;
      }
    } else {
      if (y + increment_y + radius > window.height()) {
        count_bounce_bottom++;
        y = window.height() - radius;
        ballColor = colorUp;
      } else {
        // move downward
        y += increment_y;
      }
    }

    window.draw_circle(Point{x, y}, radius, ballColor);

    window.next_frame();
  }
}
