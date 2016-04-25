#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "Card.h"

class Player
{
    public:
        Player();
        Player(bool ai);
        virtual ~Player();
        int HandValue();
        void AddCard(Card card);
        std::string ShowHand();
    protected:

    private:
        bool ai;
        int hand_value;
        std::vector<Card> player_hand;
        int CalculateHandValue(std::vector<Card> hand);
};

#endif // PLAYER_H
