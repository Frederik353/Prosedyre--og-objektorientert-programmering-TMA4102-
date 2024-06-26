#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <map>

// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public TDT4102::Button {
private:
  Cell _state = Cell::closed;
  bool _isMine = false;

public:
  // For aa sette labelfarge i henhold til hvor mange miner som er rundt
  const std::map<int, TDT4102::Color> minesToColor{
      {1, TDT4102::Color::blue},       {2, TDT4102::Color::red},
      {3, TDT4102::Color::dark_green}, {4, TDT4102::Color::dark_magenta},
      {5, TDT4102::Color::dark_blue},  {6, TDT4102::Color::dark_cyan},
      {7, TDT4102::Color::dark_red},   {8, TDT4102::Color::gold}};
  Tile(TDT4102::Point pos, int size);
  void set_label(std::string s) { this->setLabel(s); };
  void set_label_color(TDT4102::Color c) { this->setLabelColor(c); };

  void open();
  void flag();

  void resetTile();
  Cell getState() const { return _state; };
  bool hasMine() { return _isMine; };
  void setMine(bool isMine = true) { _isMine = isMine; };
  void setAdjMines(int n);
};
