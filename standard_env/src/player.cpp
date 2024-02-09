#include "player.h"
#include <string>

std::string Player::getName() { return name; }

void Player::addCardToHand(const Card &card) { hand.addCard(card); }

int Player::getHandSum() { return hand.getHandSum(); }

// -1 means print all cards
void Player::printHand(int numFirstCards) { hand.print(numFirstCards); };

// -1 means print all cards
void Player::printHandShort(int numFirstCards) {
  hand.printShort(numFirstCards);
};
