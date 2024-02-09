#include "blackjack.h"
#include "card.h"
#include <iostream>
#include <limits>
#include <optional>

// Blackjack::Blackjack() : dealer() {}

void Blackjack::addPlayer(const std::string &name) {
  players.push_back(Player(name));
}

bool Blackjack::askPlayerDrawCard() {
  //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Do you want to draw a card? (y/n): ";
  if (std::cin >> std::ws && std::cin.get() == 'y') {
    std::cout << std::endl;
    return true;
  }
  std::cout << std::endl;
  return false;
}

void Blackjack::drawCardForPlayer(Player &player, bool silent) {
  std::optional<Card> card = deck.drawCard();
  if (card) {
    player.addCardToHand(*card);
    if (!silent) {
      std::cout << player.getName() << " drew: " << (*card).toString()
                << std::endl;

      std::cout << "For a total of: " << player.handSumToString() << std::endl
                << std::endl;
    }
  } else {
    std::cout << "No more cards in deck" << std::endl;
  }
}

void Blackjack::setup() {
  addPlayer("Player 1");
  addPlayer("Player 2");
  addPlayer("Player 3");
  addPlayer("Player 4");
  addPlayer("Player 5");
  addPlayer("Player 6");

  deck.shuffle();

  for (Player &player : players) {

    // todo idk
    drawCardForPlayer(player, true);
    drawCardForPlayer(player, true);
  }

  drawCardForPlayer(dealer, true);
  drawCardForPlayer(dealer, true);
}

void Blackjack::printStatus(Player &player, bool isDealer) {
  std::cout << "--------   " << player.getName() << "   --------" << std::endl;
  if (!isDealer) {
    std::cout << "Dealers hand: ";
    dealer.printHandShort(1);
  }
  std::cout << "hand: ";
  player.printHandShort();
  std::cout << "score: " << player.handSumToString() << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

void Blackjack::play() {
  setup();

  for (Player &player : players) {
    printStatus(player);
    while (askPlayerDrawCard()) {

      drawCardForPlayer(player);

      if (player.getHandSum().at(0) > 21) {
        std::cout << "You lost!" << std::endl;
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

  printStatus(dealer, true);

  int dealerPoints = dealer.getHandSum().back();
  if (dealerPoints > 21) {
    std::cout << "Dealer lost!" << std::endl;
  } else {
    for (Player &player : players) {
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
