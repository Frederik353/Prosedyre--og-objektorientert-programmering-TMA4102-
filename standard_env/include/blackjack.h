#pragma once

#include "Card.h"
#include "carddeck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include <optional>
#include <vector>

class Blackjack {
private:
  std::vector<Player> players;
  CardDeck deck;
  Dealer dealer;

public:
  void askPlayerDrawCard();
  void drawCardForPlayer(Player &player);
  void play();
}