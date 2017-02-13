#include "HomeCellArea.h"



HomeCellArea::HomeCellArea() : m_home_cells(Array<Stack<Card>>(4,0)) // creates the array of stacks 4 long
{
	for (int i = 0; i < 4; i++)
		m_home_cells[i].setLength(13); //sets the length to 13 so that it fits all the cards
}

HomeCellArea::HomeCellArea(const HomeCellArea & copy)
{
	*this = copy;
}

HomeCellArea & HomeCellArea::operator=(const HomeCellArea & rhs)
{
	if (this != &rhs)
	{
		m_home_cells = rhs.m_home_cells;
	}
	return *this;
}


HomeCellArea::~HomeCellArea()
{
}

Card HomeCellArea::GetTop(int column)
{
	return m_home_cells[column].Peek(); // shows the top card in that home cell
}

bool HomeCellArea::GetEmpty(int column)
{
	return m_home_cells[column].isEmpty(); //checks to see if the home cell is empty or not
}

bool HomeCellArea::SetHomeCell(Card home, int pass)
{
	bool found = true;
	Card temp;
	Card compare;

	temp.SetSuit(home.GetSuit()); // sets the temp suit to the suit that is being passed in
	temp.SetRank(home.GetRank()); // sets the temp rank to the rank that was being passed in

	if (temp.GetRank() != compare.Ace && pass != 99) // if the rank doesn't == ace and the pass is not 99
	{
		if (temp.GetSuit() == compare.Spades && temp.GetRank() == (m_home_cells[0].Peek().GetRank() + 1)) //maybe needs a plus 1 to compare
			m_home_cells[0].Push(home);

		else if (temp.GetSuit() == compare.Diamonds && temp.GetRank() == (m_home_cells[1].Peek().GetRank() + 1))
			m_home_cells[1].Push(home);

		else if (temp.GetSuit() == compare.Hearts && temp.GetRank() == (m_home_cells[2].Peek().GetRank() + 1))
			m_home_cells[2].Push(home);

		else if (temp.GetSuit() == compare.Clubs && temp.GetRank() == (m_home_cells[3].Peek().GetRank()+1))
			m_home_cells[3].Push(home);

		else
			found = false;
	}

	else
	{
		if (temp.GetSuit() == compare.Spades)
			m_home_cells[0].Push(home);

		else if (temp.GetSuit() == compare.Diamonds)
			m_home_cells[1].Push(home);

		else if (temp.GetSuit() == compare.Hearts)
			m_home_cells[2].Push(home);

		else if (temp.GetSuit() == compare.Clubs)
			m_home_cells[3].Push(home);

		else
			found = false;
	}

	return found;
}

bool HomeCellArea::Winner()
{
	bool win = false;
	Card compare;
	for (int i = 0; i < 4; i++)
	{
		try
		{
			if (m_home_cells[i].Peek().GetRank() == compare.King) // if the rank is king then the game is over and they win
				win = true;
			else
				win = false;
		}
		catch (Exception E)
		{
			win = false;
		}
	}
	return win;
}

void HomeCellArea::Display()
{
	Card temp;
	for (int i = 0; i < 4; i++) // should go through each of the home cells
	{
		if (GetTop(i).GetRank() == temp.Ace - 1) // fix this equation if it doesn't work 
			cout << "empty space" << endl;
		else
		{
			cout << "    " << endl;
			GetTop(i);
			cout << "    " << endl;
		}
	}
}
