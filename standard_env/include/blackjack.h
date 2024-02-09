#pragma once

#include "card.h"
#include "carddeck.h"
#include "hand.h"
#include "player.h"
#include <optional>
#include <vector>

class Blackjack {
private:
  std::vector<Player> players;
  CardDeck deck;
  Player dealer;

public:
  //   Blackjack() = default;
  Blackjack() : dealer("Dealer"){};
  void addPlayer(const std::string &name);
  bool askPlayerDrawCard(Player &player);
  void drawCardForPlayer(Player &player);
  void play();
  void setup();
};