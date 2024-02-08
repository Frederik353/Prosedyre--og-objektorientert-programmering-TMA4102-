#include "blackjack.h"
#include <iostream>

Blackjack::Blackjack() : deck(1) {}

Blackjack::addPlayer(const std::string &name) {
  players.push_back(Player(name));
}

void Blackjack::askPlayerDrawCard() {
  std::cout << "Do you want to draw a card? (y/n)" << std::endl;
  if (std::cin.get() == 'y') {
    // player.addCardToHand(deck.drawCard());
    return true;
  }
  return false;
}

void Blackjack::drawCardForPlayer(Player &player) {
  Card card = deck.drawCard();
  player.addCardToHand(deck.drawCard());
}

void play() {
  drawCardForPlayer(dealer);
  for (Player &player : players) {
    while (askPlayerDrawCard()) {
      drawCardForPlayer(player);
      std::cout << "Your hand: " << player.printShort() << std::endl;
      std::cout << "your score: " << player.getHandSum() << std::endl;
      if (player.getHandSum() > 21) {
        std::cout << "You lost!" << std::endl;
        break;
      }
    }
  }
}
