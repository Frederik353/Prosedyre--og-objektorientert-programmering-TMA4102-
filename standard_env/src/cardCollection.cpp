#include "cardcollection.h"
#include <iostream>
#include <optional>
#include <string>
#include <vector>


CardCollection::CardCollection() {}

void CardCollection::addCard(const Card &card) { cards.push_back(card); }

// oppgave 2 f
bool CardCollection::drawCard(){return drawCardByIndex(cards.size() - 1)}

std::optional<Card> removeCardByIndex(size_t index) {
  if (index < cards.size()) {
    Card removedCard = cards[index];
    cards.erase(cards.begin() + index);
    return removedCard;
  }
  return std::nullopt;
}

void CardCollection::swap(int i, int j) { std::swap(cards[i], cards[j]); }

// oppgave 2 d
void CardCollection::print() {
  for (Card card : cards) {
    std::cout << card.toString() << std::endl;
  }
}

void CardCollection::printShort() {
  for (Card card : cards) {
    std::cout << card.toShortString() << std::endl;
  }
}
