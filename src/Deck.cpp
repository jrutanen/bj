#include "Deck.h"
#include <iostream>
<<<<<<< HEAD
#include <ctime>
#include <cstdlib>
=======
#include <math>
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2

Deck::Deck()
{
    //ctor
<<<<<<< HEAD
    char suites[4];
    suites[0] = 'S';
    suites[1] = 'H';
    suites[2] = 'D';
    suites[3] = 'C';
=======
    //cards = new vector();
    char suites[4];
    suites[0] = '\u2660';
    suites[1] = '\u2665';
    suites[2] = '\u2666';
    suites[3] = '\u2663';
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
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
<<<<<<< HEAD
}

Deck::Deck(std::vector<Deck> deck_list)
{
    for (int i=0; i < deck_list.size(); ++i)
    {
        std::vector<Card> deck_cards = deck_list.at(i).GetCards();
        cards.insert(cards.end(), deck_cards.begin(), deck_cards.end());
=======

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
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
    }
}


Deck::~Deck()
{
    //dtor
}

<<<<<<< HEAD
std::vector<Card> Deck::GetCards()
=======
Deck::GetCards()
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
{
    return cards;
}

<<<<<<< HEAD
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
=======
Deck::Shuffle()
{

>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
}

