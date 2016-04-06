#include "Deck.h"
#include <iostream>
#include <math>

Deck::Deck()
{
    //ctor
    //cards = new vector();
    char suites[4];
    suites[0] = '\u2660';
    suites[1] = '\u2665';
    suites[2] = '\u2666';
    suites[3] = '\u2663';
    //add 52 cards into the deck
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j < 14; ++j)
        {
            Card new_card;
            new_card.value = j;
            new_card.suite = suites[i];
            cards.push_back(new_card);
        }
    }

    for (int i = 0; i < cards.size(); ++i)
    {
        std::cout << cards.at(i).suite << cards.at(i).value << ", ";
    }
}

Deck::Deck(std::vector<std::vector<Deck>> deck_list)
{
    for (int i = 0; i < deck_list.size(); ++i)
    {
        cards.insert(cards.end(), deck_list.at(i).begin, deck_list.at(i).end);
    }
}


Deck::~Deck()
{
    //dtor
}

Deck::GetCards()
{
    return cards;
}

Deck::Shuffle()
{

}

