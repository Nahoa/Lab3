#ifndef DECK_H
#define DECK_H

#include "Card.h" 

class Deck
{

public:

	Deck();
	Deck(const Deck & copy);
	//Deck & operator=(const Deck & rhs);
	~Deck();
	void Shuffle();
	static int GetCards();
	Card Deal();

protected:
	Card ** m_deck = nullptr; 
	static int m_current_card;
};

#endif 