#include "Tile.h"
#include <iostream>
#include <sstream>
#include <string>
// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{
    {Cell::closed, ""}, {Cell::open, ""}, {Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size)
    : Button({pos.x, pos.y}, 1.5 * size, size, "") {
  setButtonColor(TDT4102::Color::silver);
}

void Tile::open() {
  switch (_state) {
  case Cell::closed: {
    if (hasMine()) {
      set_label_color(TDT4102::Color::red);
      set_label("X");
    } else {
      setButtonColor(TDT4102::Color::white);
      _state = Cell::open;
    }
    break;
  }
  }
}

void Tile::flag() {
  switch (_state) {
  case Cell::flagged: {
    _state = Cell::closed;
    break;
  }
  case Cell::closed: {
    _state = Cell::flagged;
    set_label_color(TDT4102::Color::black);
    break;
  }
  }
  set_label(cellToSymbol.at(_state));
}

void Tile::setAdjMines(int n) {
  std::string num = std::to_string(n);
  set_label(num);
  set_label_color(minesToColor.at(n));
}
