#include <iostream>
<<<<<<< HEAD
#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

int player_cards_value = 0;
int dealer_cards_value = 0;
vector<Card> player_cards;
vector<Card> dealer_cards;
bool test = false;

void PrintTable(Player p1, Player dealer)
{
	system("CLS");//system("clear"); //CLS for windows, clear for Linux/OS X
    cout << "Black Jack Game" << endl <<endl;

	cout << "Dealer: " << dealer.HandValue() << endl;
	cout << dealer.ShowHand();

	if(dealer.HandValue() >= 17 && dealer.HandValue() < 22) cout << "Dealer Stays";
	if(dealer.HandValue() > 21) cout << "Dealer Busted";
	cout << endl << endl;

  	cout << "Player: " << p1.HandValue() << endl;
	cout << p1.ShowHand();
	if(p1.HandValue() >= 18 && p1.HandValue() < 22) cout << "Player Stays";
	if(p1.HandValue() > 21) cout << "Player Busted";

=======
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
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
	cout << endl;
}

int CalculateCardValues(vector<Card> cards)
{
	int value = 0;
<<<<<<< HEAD
	int ace_count = 0;
=======
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
	for (int i = 0; i < cards.size(); ++i)
	{
		if(cards.at(i).value == 1)
		{
<<<<<<< HEAD
            value += 11;
            ++ace_count;
=======
			if(value <= 21 - 11)
			{
				value += 11;
			}
			else
			{
				value += 1;
			}
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
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
<<<<<<< HEAD

	while (value > 21 && ace_count > 0)
    {
        value -= 10;
        --ace_count;
    }
	return value;
}

int main()
{
    cout << "Black Jack Game" << endl;

    //Prepare card Decks
	int nbr_of_decks = 4;
    vector<Deck> decks;
=======
	return value;
}


int main()
{
	int nbr_of_decks = 4;
 
    cout << "Black Jack Game" << endl;

    vector<Deck> decks;

>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
    for (int i = 0; i < nbr_of_decks; ++i)
    {
    	decks.push_back(Deck());
    }
<<<<<<< HEAD

    //combine all decks to one and shuffle
    Deck bj_deck = Deck(decks);
    bj_deck.Shuffle();

    Player player1 = new Player(true);
    Player dealer = new Player(true);

    char input = ' ';

	while(true && !test)
	{
        bool game = true;
        //Dealer draws card
        if(dealer.HandValue() < 17)
        {
            dealer.AddCard(bj_deck.GetTopCard());
        }
        //player draws card
        if(player1.HandValue() < 18)
        {
            player1.AddCard(bj_deck.GetTopCard());
        }

        PrintTable(player1, dealer);

        if (dealer_cards_value > 21 || player_cards_value > 21) break;
        cout << "Type in key for new card" << endl;
        cin >> input;
//        if(input == 'Q') game = false;
	}
	if(test)
    {
        Card ace;
        ace.value = 1;
        Card jack;
        jack.value = 11;
        Card nine;
        nine.value = 9;

        vector<Card> two_aces_21;
        two_aces_21.push_back(ace);
        two_aces_21.push_back(nine);
        two_aces_21.push_back(ace);
        two_aces_21.push_back(jack);

        int result = CalculateCardValues(two_aces_21);
        if (result == 21)
        {
            cout << "TEST Two Aces 21 PASSED";
        }
        else
        {
            cout << "TEST Two Aces 21 FAILED";
        }
    }
    return 0;
}
=======
 
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
>>>>>>> 517edaa29116b62582332267df104cfb03f853a2
