#include <windows.h> // needed to display Ranks color
#include <iomanip>  // needed to align 
using std::setw;
#include <iostream>;
using std::cout;
using std::endl;// edited the 1 out and put l there


#include "Card.h"

/**********************************************************************
* Purpose: Default constructor
*
* Precondition: None
*
* Postcondition: None
*
************************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit) // chandged them to the right variables
{ }

/**********************************************************************
* Purpose: If the rank equals a certain value it outputs the word
* that coresponds to the value.
*
* Precondition: None
*
* Postcondition: The value of the rank and suit.
*
************************************************************************/
void Card::Display()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const char*rank_txt[] = { "Ace","Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Four","King" };
	int rank_ascii[] = { 3, 4, 5, 6 };//spades, hearts, clubs, diamonds  

	if (rank_ascii[m_suit] == 3 || rank_ascii[m_suit] == 5) //spades or clubs will be black 3 and 5
	{
		cout << setw(2) << rank_txt[m_rank];
		cout << setw(2) << char(rank_ascii[m_suit]);
	}

	else
	{
		SetConsoleTextAttribute(handle,
			12 | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // 12 is font color red

		cout << setw(2) << rank_txt[m_rank]; // displays the ascii char
		cout << setw(2) << char(rank_ascii[m_suit]);

		SetConsoleTextAttribute(handle,
			BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // resets the color back to black
		// Keep the black text for everything else 
	}

}

/**********************************************************************
* Purpose: This sets the value of the rank
*
* Precondition: None
*
* Postcondition: The rank
*
************************************************************************/
void Card::SetRank(Rank rank) // cant base member initilize a function 
{
	m_rank = rank;
}

/**********************************************************************
* Purpose: This sets the value of the suit
*
* Precondition: None
*
* Postcondition: The rank
*
************************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit; // made it m_suit
}

/**********************************************************************
* Purpose: This gets the value of the rank
*
* Precondition: None
*
* Postcondition: The rank
*
************************************************************************/
Card::Rank Card::PlayerGetRank()
{
	if (m_rank == King || m_rank == Queen || m_rank == Jack)
	{
		m_rank = Ten;
	}
	else if (m_rank == Ace)
	{
		int selection = 0;
		cout << "Do you want your ace to be 1 or 11?(Enter 0 for 1)";
		cin >> selection;
		if (selection == 0)
		{
			m_rank = Ace;//sets it to 1
		}
		else
		{
			m_rank = Jack;//sets it to 11
		}
	}

	return m_rank;

}

/**********************************************************************
* Purpose: Gets the Rank and converts them into ints to find totals
*
* Precondition: none
*
* Postcondition: none
*
************************************************************************/
Card::Rank Card::GetRank()
{
	if (m_rank == King || m_rank == Queen || m_rank == Jack)
	{
		m_rank = Ten;
	}
	if (m_rank == Ace)
	{
		m_rank = Jack;
	}
	return m_rank;
}

/**********************************************************************
* Purpose: Sets the ranks for the dealer
*
* Precondition: none
*
* Postcondition: none
*
************************************************************************/
Card::Rank Card::DealerGetRank(int currentvalue)
{
	if (m_rank == King || m_rank == Queen || m_rank == Jack)
	{
		m_rank = Ten;
	}
	if (currentvalue>17 && m_rank == Ace)
	{
		m_rank = Jack;
	}
	return m_rank;
}

/**********************************************************************
* Purpose: This gets the value of the suit
*
* Precondition: None
*
* Postcondition: The rank
*
************************************************************************/
Card::Suit Card::GetSuit()
{
	return m_suit;
}