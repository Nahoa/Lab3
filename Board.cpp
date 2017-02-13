#include "Board.h"
#include <windows.h> // needed to display Ranks color
#include <iomanip>  // needed to align stuff
using std::setw;


Board::Board() : m_deck(Deck()), m_free_cell_area(FreeCellArea()), m_home_cell_Area(HomeCellArea()), m_play_area(PlayArea())
{
	Populate();
}

Board::Board(const Board & copy)
{
	m_deck = copy.m_deck;
	m_free_cell_area = copy.m_free_cell_area;
	m_home_cell_Area = copy.m_home_cell_Area;
	m_play_area = copy.m_play_area;
}

Board & Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_deck = rhs.m_deck;
		m_free_cell_area = rhs.m_free_cell_area;
		m_home_cell_Area = rhs.m_home_cell_Area;
		m_play_area = rhs.m_play_area;
	}
	return *this;
}


Board::~Board()
{
}

void Board::PlayA()
{
	COORD cursor;

	cursor.X = 5;
	cursor.Y = 5;

	for (int i = 0; i < 8; i++)
	{
		m_play_area.Display(i); // probably wont work will have to fix the display
	}
}

void Board::HomeA() // should display the home area
{
	COORD cursor;

	cursor.X = 15;
	cursor.Y = 5;

	for (int i = 0; i < 4; i++)
		cout << "HOME CELL " << i + 1 << "  ";

	cout << endl; 

	//cursor.X = 40;
	//cursor.Y = 1;
	m_home_cell_Area.Display();

}

void Board::FreeA()
{
	for (int i = 0; i < 4; i++)
		cout << "FREE CELL " << i + 1 << "  ";

	cout << "\n";
	//setw(40);
	m_free_cell_area.Display();
}

void Board::Populate()
{
	Card temp;

	for (int i = 0; i < 52; i++)
	{
		temp = m_deck.Deal();
		m_play_area.getStack()[i % 8].Push(&temp); // puts the card on the stack "should"
	}
}

bool Board::isValidMove(Card move, Card bottom)
{
	bool valid = false;
	Card tempmove;
	Card tempbottom;
	Card compare1;
	Card compare2;

	tempmove.SetRank(move.GetRank());
	tempmove.SetSuit(move.GetSuit());

	tempbottom.SetRank(bottom.GetRank());
	tempbottom.SetSuit(bottom.GetSuit());

	//moving a red on black card
	if (tempmove.GetSuit() == compare1.Hearts || tempmove.GetSuit() == compare2.Diamonds)
	{
		if (tempbottom.GetSuit() == compare1.Clubs || tempbottom.GetSuit() == compare2.Spades)
		{
			if (tempmove.GetRank() == tempbottom.GetRank() - 1) // this might be a problem
				valid = true;
		}
	}

	if (tempmove.GetSuit() == compare1.Clubs || tempmove.GetSuit() == compare2.Spades)
	{
		if (tempbottom.GetSuit() == compare1.Hearts || tempbottom.GetSuit() == compare2.Diamonds)
		{
			if (tempmove.GetRank() == tempbottom.GetRank() - 1) // this might be a problem (compares the ranks together)
				valid = true;
		}

	}


	return valid;
}

PlayArea & Board::GetPlay()
{
	return m_play_area;
}

FreeCellArea & Board::GetFree()
{
	return m_free_cell_area;
}

HomeCellArea & Board::GetHome()
{
	return m_home_cell_Area;
}
