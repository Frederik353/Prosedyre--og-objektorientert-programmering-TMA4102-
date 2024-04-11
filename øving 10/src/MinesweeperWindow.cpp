#include "MinesweeperWindow.h"
#include "widgets/TextInput.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <string>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height,
                                     int mines, const string &title)
    : // Initialiser medlemsvariabler, bruker konstruktoren til
      // AnimationWindow-klassen
      AnimationWindow{x, y, (width * cellSize) + 5, (height + 1) * cellSize + 5,
                      title},
      width{width}, height{height}, _mineCount{mines} {

  int toolbarPosY = height * cellSize + 5;

  _textField = std::make_shared<TextInput>(Point{-5, toolbarPosY}, 120, 5, "");

  _textField->setVisible(false);
  add(*_textField);

  std::string baseText = "Mines left: ";
  std::string fullText = baseText + std::to_string(mines);

  _minesLeftBox = std::make_shared<TextInput>(
      Point{(width * cellSize) - 120, toolbarPosY}, 140, 5, fullText);
  add(*_minesLeftBox);

  _resetBtn = std::make_shared<Button>(Point{95, toolbarPosY}, 110, 5, "");
  _resetBtn->setCallback(std::bind(&MinesweeperWindow::reset, this));
  _resetBtn->setVisible(false);
  add(*_resetBtn);

  // Legg til alle tiles i vinduet
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      tiles.emplace_back(new Tile{Point{j * cellSize, i * cellSize}, cellSize});
      tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
      auto temp = tiles.back().get();
      add(*temp);
    }
  }
  distributeMines();
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
  int count = 0;
  for (Point p : coords) {
    if (at(p)->hasMine()) {
      count++;
    }
  }
  return count;
};

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

  if (at(xy)->getState() != Cell::closed || _frozen) {
    return;
  }

  at(xy)->open();
  _openedTilesCount++;

  if (at(xy)->hasMine()) {
    _frozen = true;
    setMessage("You Lost");
    for (auto t : tiles) {

      if (t->getState() == Cell::flagged || t->hasMine()) {
        t->setLabelColor(TDT4102::Color::red);
      }

      if (t->hasMine()) {
        if (t->getState() == Cell::flagged) {
          //   t->flag();
          t->set_label("V");
          t->setLabelColor(TDT4102::Color::green);
        }
        t->open();
      }
    }
    return;
  }
  vector<Point> adjacent = adjacentPoints(xy);
  int adjacentMines = countMines(adjacent);
  if (adjacentMines == 0) {
    for (Point p : adjacent) {
      openTile(p);
    }
  } else {
    at(xy)->setAdjMines(adjacentMines);
  }
  if (won()) {
    setMessage("You Won");
    for (auto t : tiles) {
      if (t->getState() == Cell::flagged) {
        t->flag();
      }
      if (t->hasMine()) {
        t->flag();
      }
    }
  }
}

void MinesweeperWindow::setMessage(std::string m) {
  //   int xPos = static_cast<int>(Width() / 2);
  //   int yPos = static_cast<int>(Height() / 2);
  //   unsigned int textWidth = static_cast<unsigned int>(x / 2);
  //   unsigned int textHeight = static_cast<unsigned int>(width / 2);
  //   _textField = std::make_unique<TextInput>(Point{xPos, yPos}, textWidth,
  //   textHeight, m);
  //   std::cout << x << " " << y << " " << width << " " << height << " " << m
  //   << std::endl; _textField =

  _textField->setVisible(true);
  _textField->setText(m);
  _resetBtn->setVisible(true);
}

bool MinesweeperWindow::won() {
  if (_openedTilesCount == (height * width) - _mineCount) {
    return true;
  }
  return false;
}

void MinesweeperWindow::updateMinesLeft() {
  std::string baseText = "Mines left: ";
  std::string fullText =
      baseText + std::to_string(_mineCount - _flaggedTilesCount);
  _minesLeftBox->setText(fullText);
}

void MinesweeperWindow::flagTile(Point xy) {
  at(xy)->flag();
  if (at(xy)->getState() == Cell::flagged) {
    _flaggedTilesCount++;
  } else if (at(xy)->getState() == Cell::closed) {
    _flaggedTilesCount--;
  }
  updateMinesLeft();
}

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

void MinesweeperWindow::distributeMines() {
  std::random_device rd;
  std::mt19937 eng(rd());

  int placedMines = 0;
  std::uniform_int_distribution<int> distrWidth(0, width - 1);
  std::uniform_int_distribution<int> distrHeight(0, height - 1);

  while (placedMines < _mineCount) {
    int x = distrWidth(eng);
    int y = distrHeight(eng);
    int index = y * width + x;
    Tile *tile = tiles[index].get();

    if (!tile->hasMine()) {
      tile->setMine();
      placedMines++;
    }
  }
}

void MinesweeperWindow::resetTiles() {
  for (auto t : tiles) {
    t->resetTile();
  }
}

void MinesweeperWindow::reset() {
  _textField->setVisible(false);
  _resetBtn->setVisible(false);
  resetTiles();
  distributeMines();
  _frozen = false;
  _openedTilesCount = 0;
  _flaggedTilesCount = 0;
}
