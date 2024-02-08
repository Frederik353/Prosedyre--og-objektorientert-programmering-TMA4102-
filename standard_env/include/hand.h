#pragma once
#include "card.h"
#include "cardColletion.h"
#include <vector>

class Hand : public CardCollection {
private:
  int handSum;

public:
  int sumHand();
  int getHandSum();
  bool isAce();
  int getCardValue();
};