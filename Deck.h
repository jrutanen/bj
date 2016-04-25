#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

class Deck
{
    public:
        Deck();
        Deck(std::vector<Deck> deck_list);
        virtual ~Deck();
        std::vector<Card> GetCards();
        void Shuffle();
        void ShowCards();
        Card GetTopCard();
    protected:

    private:
        std::vector<Card> cards;
};

#endif // DECK_H
