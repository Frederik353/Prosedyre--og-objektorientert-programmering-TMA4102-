#include "hand.h"

// oppgave 3 b
bool Hand::isAce(Card card) { return card.getRank() == Rank::ACE; }

// oppgave 3 c
int Hand::getCardValue(Card card) {
  int value = static_cast<int>(card.getRank());
  return value > 10 ? 10 : value;
}

int Hand::getHandSum() { return handSum; }

// int Hand::sumHand() {
//   handSum = 0;
//   for (Card card : cards) {
//     handSum += getCardValue(card);
//   }
// }

void Hand::addCard(const Card &card) override {
  CardCollection::addCard(card); // Call base class implementation
  handSum += getCardValue(card);
  // sumHand()
}