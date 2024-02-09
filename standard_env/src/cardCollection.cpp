#include "cardCollection.h"
#include <iostream>
#include <optional>
#include <string>
#include <vector>

void CardCollection::addCard(const Card &card) { cards.push_back(card); }

// oppgave 2 f
std::optional<Card> CardCollection::drawCard() {
  return removeCardByIndex(cards.size() - 1);
}

std::optional<Card> CardCollection::removeCardByIndex(size_t index) {
  if (index < cards.size()) {
    Card removedCard = cards[index];
    cards.erase(cards.begin() + index);
    return removedCard;
  }
  return std::nullopt;
}

void CardCollection::swap(int i, int j) { std::swap(cards[i], cards[j]); }

// oppgave 2 d
void CardCollection::print(int numFirstCards) {
  if (numFirstCards < 0) {
    numFirstCards = cards.size();
  }
  int cardsToPrint = std::min(numFirstCards, static_cast<int>(cards.size()));

  for (int i = 0; i < cardsToPrint; ++i) {
    std::cout << cards[i].toString() << std::endl;
  }
}

void CardCollection::printShort(int numFirstCards) {
  if (numFirstCards < 0) {
    numFirstCards = cards.size();
  }
  int cardsToPrint = std::min(numFirstCards, static_cast<int>(cards.size()));

  for (int i = 0; i < cardsToPrint; ++i) {
    std::cout << cards[i].toShortString() << std::endl;
  }
}

Card &CardCollection::at(size_t index) {
  if (index >= cards.size()) {
    throw std::out_of_range("Index out of range");
  }
  return cards.at(index); // Using std::vector's at() for bounds checking
}

size_t CardCollection::size() const { return cards.size(); }