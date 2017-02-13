#include <stdlib.h>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
#include "Deck.h"

int Deck::m_current_card = 0;

/**********************************************************************
* Purpose: This creates the deck of cards
*
* Precondition: None
*
* Postcondition: The deck of cards
*
************************************************************************/
Deck::Deck()
{
	static int card = 0; // makes a card at this index

	m_deck = new Card *[52];

	for (int suit = 0; suit < 4; suit++) //removed comma, and initilized suit to 1
	{
		for (int rank = 1; rank <= 13; rank++) //This was the major problem!!!
		{
			m_deck[card++] = new Card(static_cast<Card::Rank>(rank),
				static_cast<Card::Suit>(suit + 2));
		}
	}

} // added closing brackets

Deck::Deck(const Deck & copy)
{
	*this = copy;
}

//Deck & Deck::operator=(const Deck & rhs)
//{
//	if (this != &rhs)
//	{
//		for (int i = 0; i < m_current_card; i++)
//		{
//			if (m_deck[i] != nullptr)
//				delete m_deck[i];
//			m_deck[i] = nullptr;
//		}
//		m_current_card = rhs.m_current_card;
//		int index = 0;
//		for (int i = 0; i < 3)
//	}
//		
//	return *this;
//}


  /**********************************************************************
  * Purpose: This deletes the deck of cards
  *
  * Precondition: None
  *
  * Postcondition: no memory leaks
  *
  ************************************************************************/
Deck::~Deck()
{
	for (int i = 0; i < 52; i++)
	{
		delete m_deck[i];
	}

	delete[] m_deck;
	m_deck = nullptr;
}

/**********************************************************************
* Purpose: This shuffles the deck of cards created
*
* Precondition: None
*
* Postcondition: The randomly created cards
*
************************************************************************/
void Deck::Shuffle() // removed s
{

	Card * temp = nullptr; // changed to nullptr because its safer
	m_current_card = 0;
	int number = 0;
	srand(time(0));

	for (int shuffle = 3; shuffle < 4; shuffle++) //removed the this pointer 
	{
		for (int cur = 0; cur <= 26; cur++) //  changed = < to <= and removed semicolon
		{
			number = rand() % 51;
			temp = m_deck[cur];
			m_deck[cur] = m_deck[number]; // changed -> to =
			m_deck[number] = temp;
		}
		//cout << "SHUFFFLLLINGGGGGGGGGGGGGGGG!!!" << endl;

	}
}

/**********************************************************************
* Purpose: This displays the number of cards delt
*
* Precondition: None
*
* Postcondition: None
*
************************************************************************/
int Deck::GetCards()
{
	return m_current_card;
}


/**********************************************************************
* Purpose: This deals one card at a time
*
* Precondition: None
*
* Postcondition: The card
*
************************************************************************/
Card Deck::Deal()
{
	Card c = *m_deck[m_current_card++];
	return c; //having access violations here!!!! FIX!!!
}
