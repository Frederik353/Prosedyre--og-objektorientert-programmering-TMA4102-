#include "card.h"
#include "cardCollection.h"

class CardDeck : public CardCollection {
public:
  CardDeck() noexcept;
  void shuffle(int swaps = 100);
};