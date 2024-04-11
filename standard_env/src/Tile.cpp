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
    _state = Cell::open;
    setButtonColor(TDT4102::Color::white);
    if (hasMine()) {
      set_label("X");
      set_label_color(TDT4102::Color::red);
    } else {
      setButtonColor(TDT4102::Color::white);
    }
    break;
  }
  }
}

void Tile::flag() {
  switch (_state) {
  case Cell::flagged: {
    _state = Cell::closed;
    set_label(cellToSymbol.at(_state));
    break;
  }
  case Cell::closed: {
    _state = Cell::flagged;
    set_label(cellToSymbol.at(_state));
    set_label_color(TDT4102::Color::black);
    break;
  }
  }
}

void Tile::setAdjMines(int n) {
  std::string num = std::to_string(n);
  set_label(num);
  set_label_color(minesToColor.at(n));
}
