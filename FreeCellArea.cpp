#include "FreeCellArea.h"



FreeCellArea::FreeCellArea() : m_free_cells(Array<Card*>(4,0)), m_current_spots(0) // creates the free cell area with an array of cards
{
	for (int i = 0; i < MAXAREA; i++)
		m_free_cells[i] = nullptr;
}

FreeCellArea::FreeCellArea(FreeCellArea & copy)
{
	for (int i = 0; i < MAXAREA; i++)
		m_free_cells[i] = copy.m_free_cells[i];
	m_current_spots = copy.m_current_spots;
}

FreeCellArea FreeCellArea::operator=(const FreeCellArea & rhs)
{
	if (this != &rhs)
	{
		m_free_cells = rhs.m_free_cells;
		m_current_spots = rhs.m_current_spots;
	}

	return *this;
}


FreeCellArea::~FreeCellArea()
{
	for (int i = 0; i < MAXAREA; i++)
		m_free_cells[i] = nullptr;
}

int FreeCellArea::getOpenSpace()
{
	return m_current_spots;
}

bool FreeCellArea::isFull()
{
	bool full = false;
	if (m_current_spots == MAXAREA)
		full = true;
	return full;
}

void FreeCellArea::MovetoFreeCell(Card * free_card)
{
	if (m_current_spots == 4)
		throw Exception("There are no more free cells for this card");
	else
	{
		m_free_cells[m_current_spots] = free_card;
		m_current_spots++;
	}
}

void FreeCellArea::RemovefromFreeCell(int index)
{
	m_free_cells[index] = nullptr;
	m_current_spots--;
}

Array<Card*>& FreeCellArea::getFree()
{
	return m_free_cells;
}

int FreeCellArea::Calculate()
{
	int max = 0;
	max = getOpenSpace();

	if (max == 0) // if all 4 spaces are open
		max = 5; //can move 5 cards

	else if (max == 1)// if all 3 spaces are open
		max = 4; //can move 4 cards

	else if (max == 2)// if all 2 spaces are open
		max = 3; //can move 3 cards

	else if (max == 3)// if 1 spaces are open
		max = 2; //can move 2 cards

	else // if 0 spaces are open
		max = 1; //can move 1 cards


	return max;
}

void FreeCellArea::Display() // this display might work 
{
	for (int i = 0; i < MAXAREA; i++)
	{
		if (m_free_cells[i] == nullptr)
			cout << "empty cell   ";
		else
			cout << "  " << m_free_cells[i] << "   ";
	}
}
