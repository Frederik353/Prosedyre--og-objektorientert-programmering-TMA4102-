#include "MinesweeperWindow.h"
#include <algorithm>
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height,
                                     int mines, const string &title)
    : // Initialiser medlemsvariabler, bruker konstruktoren til
      // AnimationWindow-klassen
      AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
      width{width}, height{height}, mines{mines} {
  // Legg til alle tiles i vinduet
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      tiles.emplace_back(new Tile{Point{j * cellSize, i * cellSize}, cellSize});
      tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
      auto temp = tiles.back().get();
      add(*temp);
    }
  }
  // Legg til miner paa tilfeldige posisjoner
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<int> distrWidth(0, width - 1);
  std::uniform_int_distribution<int> distrHeight(0, height - 1);

  int placedMines = 0;
  int attempts = 0;
  while (placedMines < mines) {
    int x = distrWidth(eng);
    int y = distrHeight(eng);
    std::shared_ptr<Tile> tile = at(Point{x, y});
    if (!tile->hasMine()) {
      tile->setMine();
      placedMines++;
    }
  }
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
  vector<Point> points;
  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      if (di == 0 && dj == 0) {
        continue;
      }

      Point neighbour{xy.x + di * cellSize, xy.y + dj * cellSize};
      if (inRange(neighbour)) {
        points.push_back(neighbour);
      }
    }
  }
  return points;
}

void MinesweeperWindow::openTile(Point xy) {
  std::shared_ptr<Tile> tile_ptr = at(xy);
  tile_ptr->open();
  if (!tile_ptr->hasMine()) {
    int mines = countMines(adjacentPoints(xy));
    if (mines > 0) {
      tile_ptr->set_label(std::to_string(mines));
      tile_ptr->set_label_color(tile_ptr->minesToColor.at(mines));
    }
  }
}

void MinesweeperWindow::flagTile(Point xy) { at(xy)->flag(); }

// Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {

  Point xy{this->get_mouse_coordinates()};

  if (!inRange(xy)) {
    return;
  }
  if (this->is_left_mouse_button_down()) {
    openTile(xy);
  } else if (this->is_right_mouse_button_down()) {
    flagTile(xy);
  }
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
  int mines = 0;
  for (Point xy : coords) {
    if (at(xy)->hasMine()) {
      mines++;
    }
  }
  return mines;
}
