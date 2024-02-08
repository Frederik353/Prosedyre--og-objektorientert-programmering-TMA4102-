#pragma once
#include "card.h"
#include <optional>
#include <vector>


class CardCollection {
protected:
  std::vector<Card> cards;

public:
  void swap();
  void print();
  void printShort();
  void addCard(const Card &card);
  bool drawCard();
  std::optional<Card> removeCardByIndex(size_t index);
  bool removeCard();
}