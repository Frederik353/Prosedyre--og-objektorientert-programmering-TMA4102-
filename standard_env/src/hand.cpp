#include "hand.h"

// oppgave 3 b
bool Hand::isAce(Card card) { return card.getRank() == Rank::ACE; }

// oppgave 3 c
int Hand::getCardValue(Card card) {
  if (isAce(card)) {
    numAces++;
    return 0;
  }
  int value = static_cast<int>(card.getRank());
  return value > 10 ? 10 : value;
}

std::vector<int> Hand::getHandSum() {
  std::vector<int> validSums;
  int minimumSum = handSum + numAces;
  validSums.push_back(minimumSum);
  for (int i = 0; i < numAces; ++i) {
    if (minimumSum + 10 <= 21) {
      minimumSum += 10;
      validSums.push_back(minimumSum);
    } else {
      break;
    }
  }
  return validSums;
}

// int Hand::sumHand() {
//   handSum = 0;
//   for (Card card : cards) {
//     handSum += getCardValue(card);
//   }
// }

void Hand::addCard(const Card &card) {
  CardCollection::addCard(card); // Call base class implementation
  handSum += getCardValue(card);
  // sumHand()
}