#include "card.h"
#include "cardcollection.h"

class CardDeck : public CardCollection {
public:
  void shuffle();
}