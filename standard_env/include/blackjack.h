#pragma once

#include "Card.h"
#include "carddeck.h"
#include "hand.h"
#include <optional>
#include <vector>

class Blackjack {
private:
  std::vector<Hand> players;
  CardDeck deck;

public:
  void askPlayerDrawCard();
}