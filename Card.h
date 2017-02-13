#ifndef CARD_H //added n
#define CARD_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Card
{
public:
	enum Rank
	{
		Blank, Ace = 1, Duce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King //take blank out if it doesn't work
	};

	enum Suit
	{
		Spades = 3, Hearts, Clubs, Diamonds
	};

	Card(Rank rank = Ace, Suit suit = Spades);
	void Display();
	void SetRank(Rank rank);
	void SetSuit(Suit suit);
	Rank PlayerGetRank();
	Rank DealerGetRank(int currentvalue);
	Rank GetRank();
	Suit GetSuit();

private:
	Rank m_rank;
	Suit m_suit;
};

#endif

// getting a rank 0 thats why its breaking