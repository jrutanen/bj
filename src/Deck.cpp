#include "Deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Deck::Deck()
{
    //ctor
    char suites[4];
    suites[0] = 'S';
    suites[1] = 'H';
    suites[2] = 'D';
    suites[3] = 'C';
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
}

Deck::Deck(std::vector<Deck> deck_list)
{
    for (int i=0; i < deck_list.size(); ++i)
    {
        std::vector<Card> deck_cards = deck_list.at(i).GetCards();
        cards.insert(cards.end(), deck_cards.begin(), deck_cards.end());
    }
}


Deck::~Deck()
{
    //dtor
}

std::vector<Card> Deck::GetCards()
{
    return cards;
}

void Deck::Shuffle()
{
  std::vector<Card> shuffled_deck;
  std::vector<Card> temp_deck;
  temp_deck = cards;
  int card_pos = -1;

  // seed the random number generator
  srand (time(NULL));

  for(int i = 0; i < cards.size(); ++i)
  {
    //if there is more than one card to select from
    if (temp_deck.size() > 1)
    {
      card_pos = rand() % (temp_deck.size()-1);
      shuffled_deck.push_back(temp_deck.at(card_pos));
      temp_deck.erase(temp_deck.begin() + card_pos);
    }
    else
    {
      shuffled_deck.push_back(temp_deck.front());
    }
  }
  cards = shuffled_deck;
}

void Deck::ShowCards()
{
//    std:cout << "Card count: " << cards.size() << endl;

    for (int i = 0; i < cards.size(); ++i)
    {
        std::cout << cards.at(i).suite << cards.at(i).value;
        if (i != cards.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

Card Deck::GetTopCard()
{
    Card top_card = cards.at(0);
    cards.erase (cards.begin());
    return top_card;
}

