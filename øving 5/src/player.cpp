#include "player.h"
#include <string>
#include <vector>

std::string Player::getName() { return name; }

void Player::addCardToHand(const Card &card) { hand.addCard(card); }

std::vector<int> Player::getHandSum() { return hand.getHandSum(); }

std::string Player::handSumToString() { return hand.handSumToString(); }

// -1 means print all cards
void Player::printHand(int numFirstCards) { hand.print(numFirstCards); };

// -1 means print all cards
void Player::printHandShort(int numFirstCards) {
  hand.printShort(numFirstCards);
};
