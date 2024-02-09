#pragma once
#include "card.h"
#include "cardCollection.h"
#include <vector>

class Hand : public CardCollection {
private:
  int handSum = 0;

public:
  Hand() = default;
  //   int sumHand();
  int getHandSum();
  bool isAce(Card card);
  int getCardValue(Card card);
  void addCard(const Card &card) override;
};