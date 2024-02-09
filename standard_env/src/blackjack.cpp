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
  char response;
  std::cin >> response;
  if (response == 'y') {
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

void Blackjack::drawCardForPlayer(Player &player, bool silent) {
  std::optional<Card> card = deck.drawCard();
  if (card) {
    player.addCardToHand(*card);
    if (!silent) {
      std::cout << player.getName() << " drew: " << (*card).toString()
                << std::endl;
    }
  } else {
    std::cout << "No more cards in deck" << std::endl;
  }
}

void Blackjack::setup() {
  addPlayer("Player 1");

  deck.shuffle();

  for (Player &player : players) {

    // todo idk
    drawCardForPlayer(player, true);
    drawCardForPlayer(player, true);
  }

  drawCardForPlayer(dealer, true);
  drawCardForPlayer(dealer, true);
}

void Blackjack::printStatus(Player &player) {
  std::cout << "--------   " << player.getName() << "   --------" << std::endl;
  std::cout << "Dealers hand: ";
  dealer.printHand(1);

  std::cout << "Your hand: ";
  player.printHand();
  std::cout << "your score: ";
  for (int i : player.getHandSum()) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

void Blackjack::play() {
  setup();

  for (Player &player : players) {
    printStatus(player);
    bool wantToDraw = true; // Indicates if the player wants to draw a card
    while (wantToDraw) {
      wantToDraw = askPlayerDrawCard(player);

      if (wantToDraw) {
        drawCardForPlayer(player);

        if (player.getHandSum().at(0) > 21) {
          std::cout << "You lost!" << std::endl;
          break;
        }
      } else {
        break;
      }
    }
  }

  std::cout << std::endl
            << "---------------------------------" << std::endl
            << std::endl;
  bool draw = true;
  while (draw) {
    int sum = dealer.getHandSum().back();
    if (sum > 17) { // soft 17
      draw = false;
      break;
    }
    drawCardForPlayer(dealer, true);
  }
  std::cout << "--------   " << dealer.getName() << "   --------" << std::endl;
  std::cout << "Dealers hand: ";
  dealer.printHand();
  std::cout << "Dealers score: ";
  for (int i : dealer.getHandSum()) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  int dealerPoints = dealer.getHandSum().back();
  if (dealerPoints > 21) {
    std::cout << "Dealer lost!" << std::endl;
  } else {
    for (Player &player : players) {
      player.printHand();
      int points = player.getHandSum().back();
      if (points > 21) {
        std::cout << player.getName() << " lost with: " << points << std::endl;
      } else if (points > dealerPoints) {
        std::cout << player.getName() << " won with: " << points << std::endl;
      } else if (points < dealerPoints) {
        std::cout << player.getName() << " lost with: " << points << std::endl;
      } else {
        std::cout << player.getName() << " tied with dealer!" << std::endl;
      }
    }
  }
}
