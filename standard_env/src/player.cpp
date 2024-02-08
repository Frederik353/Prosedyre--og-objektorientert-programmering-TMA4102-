#include "player.h"
#include <string>

std::string Player::getName() { return name; }

void Player::addCardToHand(const Card &card) { hand.addCard(card); }

int Player::getHandSum() { return hand.getHandSum(); }
void printHand() { hand.print(); };

void printHandShort() { hand.printShort(); };
