#include <iostream>
#include <vector>
#include <cstdlib>
#include "Deck.h"
#include "Card.h"

using namespace std;

int player_total = 0;
int dealer_total = 0;
vector<Card> player_cards;
vector<Card> dealer_cards;

void PrintTable()
{
	system("clear"); //cls for windows
	cout << "Dealer: " << dealer_total << endl;
	for (int i = 0; i < dealer_cards.size(); ++i)
	{
		if (i != 0 )
		{
			cout << dealer_cards.at(i).suite << dealer_cards.at(i).value << " ";	
		}
		else
		{
			cout << "XX" << " ";				
		}
	}
	cout << endl << endl;

  	cout << "Player: " << player_total << endl;
	for (int i = 0; i < player_cards.size(); ++i)
	{
		cout << player_cards.at(i).suite << player_cards.at(i).value << " ";
	}
	cout << endl;
}

int CalculateCardValues(vector<Card> cards)
{
	int value = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		if(cards.at(i).value == 1)
		{
			if(value <= 21 - 11)
			{
				value += 11;
			}
			else
			{
				value += 1;
			}
		}
		else if (cards.at(i).value > 10)
		{
			value +=  10;
		}
		else
		{
			value += cards.at(i).value;
		}
	}
	return value;
}


int main()
{
	int nbr_of_decks = 4;
 
    cout << "Black Jack Game" << endl;

    vector<Deck> decks;

    for (int i = 0; i < nbr_of_decks; ++i)
    {
    	decks.push_back(Deck());
    }
 
    Deck bj_deck = Deck(decks);
    bj_deck.Shuffle();

    char input = ' ';
    int card_nbr = 0;

	while(true)
	{
		//Dealer draw first card
	    dealer_cards.push_back(bj_deck.GetTopCard());
	    dealer_total = CalculateCardValues(dealer_cards);

	    //player draw first card
	    player_cards.push_back(bj_deck.GetTopCard());
	    player_total = CalculateCardValues(player_cards);

	    ++card_nbr;

	    PrintTable();

	    if (dealer_total > 21 || player_total > 21) break;

	    cin >> input;
	} 

    return 0;
}