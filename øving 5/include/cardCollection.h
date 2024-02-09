#pragma once
#include "card.h"
#include <optional>
#include <vector>

class CardCollection {
protected:
  std::vector<Card> cards;

public:
  CardCollection() = default;
  void swap(int i, int j);
  void print(int numFirstCards = -1);
  void printShort(int numFirstCards = -1);
  virtual void addCard(const Card &card);
  std::optional<Card> drawCard();
  std::optional<Card> removeCardByIndex(size_t index);
  bool removeCard();

  Card &at(size_t index);
  size_t size() const;
};