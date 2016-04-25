#include <iostream>
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

	cout << endl;
}

int CalculateCardValues(vector<Card> cards)
{
	int value = 0;
	int ace_count = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		if(cards.at(i).value == 1)
		{
            value += 11;
            ++ace_count;
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
    for (int i = 0; i < nbr_of_decks; ++i)
    {
    	decks.push_back(Deck());
    }

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
