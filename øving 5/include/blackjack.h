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
  bool askPlayerDrawCard();
  void drawCardForPlayer(Player &player, bool silent = false);
  void printStatus(Player &player, bool isDealer = false);
  void play();
  void setup();
};