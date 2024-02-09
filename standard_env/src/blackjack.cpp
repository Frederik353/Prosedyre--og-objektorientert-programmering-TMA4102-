#include "blackjack.h"
#include "card.h"
#include <iostream>
#include <optional>

// Blackjack::Blackjack() : dealer() {}

void Blackjack::addPlayer(const std::string &name) {
  players.push_back(Player(name));
}

bool Blackjack::askPlayerDrawCard(Player &player) {
  std::cout << "Do you want to draw a card? (y/n)" << std::endl;
  if (std::cin.get() == 'y') {
    std::optional<Card> card = deck.drawCard();
    if (card) {
      player.addCardToHand(*card);
      return true;
    } else {
      std::cout << "No more cards in deck" << std::endl;
    }
  }
  return false;
}

void Blackjack::drawCardForPlayer(Player &player) {
  std::optional<Card> card = deck.drawCard();
  if (card) {
    player.addCardToHand(*card);
  } else {
    std::cout << "No more cards in deck" << std::endl;
  }
}

void Blackjack::setup() {
  addPlayer("Player 1");

  deck.shuffle();

  for (Player &player : players) {

    // todo idk
    drawCardForPlayer(player);
    drawCardForPlayer(player);
  }

  drawCardForPlayer(dealer);
  drawCardForPlayer(dealer);

  std::cout << "Dealers hand: ";
  dealer.printHand(1);
  std::cout << std::endl;
}

// Todo: handle aces

void Blackjack::play() {
  setup();

  for (Player &player : players) {
    std::cout << "--------   " << player.getName() << "   --------"
              << std::endl;
    std::cout << "Your hand: ";
    player.printHand();
    std::cout << "your score: " << player.getHandSum() << std::endl;
    while (askPlayerDrawCard(player)) {
      drawCardForPlayer(player);
      std::cout << "Your hand: ";
      player.printHand();
      std::cout << "your score: " << player.getHandSum() << std::endl;

      if (player.getHandSum() > 21) {
        std::cout << "You lost!" << std::endl;
        break;
      }
    }
  }

  std::cout << std::endl
            << "---------------------------------" << std::endl
            << std::endl;
  while (dealer.getHandSum() < 17) {
    drawCardForPlayer(dealer);
  }
  std::cout << "Dealers hand: ";
  dealer.printHand();
  std::cout << "Dealers score: " << dealer.getHandSum() << std::endl;
  if (dealer.getHandSum() > 21) {
    std::cout << "Dealer lost!" << std::endl;
  } else {
    for (Player &player : players) {
      int points = player.getHandSum();
      if (points > 21) {
        std::cout << player.getName() << " lost with: " << points << std::endl;
      } else if (points > dealer.getHandSum()) {
        std::cout << player.getName() << " won with: " << points << std::endl;
      } else if (points < dealer.getHandSum()) {
        std::cout << player.getName() << " lost with: " << points << std::endl;
      } else {
        std::cout << player.getName() << " tied with dealer!" << std::endl;
      }
    }
  }
}
