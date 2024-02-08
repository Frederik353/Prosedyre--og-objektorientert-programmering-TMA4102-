#include "cardCollection.h"
#include <random>

// oppgave 2 b
CardDeck::CardDeck() {
  for (int i = 0; i < 4; i++) {     // suit
    for (int j = 2; j <= 14; j++) { // rank
      addCard(Card(static_cast<Suit>(i), static_cast<Rank>(j)));
    }
  }
}

// oppgave 2 e
void CardDeck::shuffle(int swaps = 100) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(0, 51);

  for (int i = 0; i < swaps; i++) {
    int j = distribution(generator);
    int k = distribution(generator);
    swap(k, j);
  }
}
