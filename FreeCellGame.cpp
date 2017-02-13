#include "FreeCellGame.h"
#include <windows.h> // needed to display Ranks color


FreeCellGame::FreeCellGame()
{
	HANDLE hStdout = 0;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle, 8 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // makes the text gray might have to comment out
	m_board.FreeA(); // displays the free cell area
	m_board.HomeA(); // displays the home cell area
	m_board.PlayA(); // displays the play area
	RunGame();
}

FreeCellGame::~FreeCellGame()
{
}

void FreeCellGame::RunGame()
{
	while (m_board.GetHome().Winner() == false) // if the game is still going on
	{
		int columnchoice = 0;
		int numcards = 0;
		int moving = 0;

		columnchoice = getcolumn();
		if (columnchoice != -2)
			numcards = Getnum();
		moving = Getmoving();

		if (numcards > m_board.GetFree().Calculate())
			cout << "You can't move those many cards!" << endl;
		else
		{
			if (columnchoice == 808)
			{
				cheat(columnchoice);
				m_board.GetHome().Winner();
			}
			if (moving == -2)
			{
				if (m_board.GetFree().isFull() != true)
				{
					Card * temp;

					temp = m_board.GetPlay().getStack()[columnchoice - 1].Pop();
					m_board.GetFree().MovetoFreeCell(temp);

					PutinFreeCell(*temp, m_board.GetFree().getOpenSpace()); // puts the card in the free space and displays it

					//display the whole board again
					m_board.FreeA(); // displays the free cell area
					m_board.HomeA(); // displays the home cell area
					m_board.PlayA(); // displays the play area

				}
				else
					cout << "There is no more space in the free cells" << endl;
			}
			else if (moving == -1)
			{
				Card * temp;

				temp = m_board.GetPlay().getStack()[columnchoice - 1].Peek();

				if (m_board.GetHome().SetHomeCell(*temp, 0) == true)
				{
					Card * temp2;

					temp2 = m_board.GetPlay().getStack()[columnchoice - 1].Pop();

					PutinHome(*temp2);

					//display the whole board again
					m_board.FreeA(); // displays the free cell area
					m_board.HomeA(); // displays the home cell area
					m_board.PlayA(); // displays the play area
				}
				else
					cout << "You cannot put that card in a home cell!" << endl;
			}
			else if (columnchoice == -2)
			{
				if (m_board.GetFree().getOpenSpace() != 0)
				{
					bool valid = true;
					while (valid)
					{
						int move = 0;
						cout << endl << endl << " What card would you like to move?: ";
						cin >> move;

						if (move > 4 || move <= 0)
						{
							cout << "Invalid movement! Tray again";
							valid = true;
						}
						else
						{
							valid = false;
							if (m_board.isValidMove(*m_board.GetFree().getFree()[move - 1], *m_board.GetPlay().getStack()[moving - 1].Peek()))
							{
								m_board.GetPlay().getStack()[moving - 1].Push(m_board.GetFree().getFree()[move - 1]);
								m_board.GetFree().RemovefromFreeCell(move - 1);
								clear(move); // clears the spot the card was in back to empty

								//display the whole board again
								m_board.FreeA(); // displays the free cell area
								m_board.HomeA(); // displays the home cell area
								m_board.PlayA(); // displays the play area
							}
							else
							{
								cout << "invalid movement";
								valid = true;
							}
						}
					}
				}
				else
					cout << "The Free Cell Area is empty there is nothing to move!";
			}
			else if (columnchoice != 808)
			{
				if (numcards > 1) // checks to see if they are moving multiple cards or not
				{
					LLStack<Card*> temp;

					for (int i = 0; i < numcards; i++)
					{
						temp.Push(m_board.GetPlay().getStack()[columnchoice - 1].Pop());
						
						if (m_board.isValidMove(*temp.Peek(), *m_board.GetPlay().getStack()[moving - 1].Peek()))
						{
							for (int i = 0; i < numcards; i++)
							{
								m_board.GetPlay().getStack()[moving - 1].Push(temp.Pop());
							}

							//display the whole board again
							m_board.FreeA(); // displays the free cell area
							m_board.HomeA(); // displays the home cell area
							m_board.PlayA(); // displays the play area
						}
					}
				}
				else if (m_board.isValidMove(*m_board.GetPlay().getStack()[columnchoice - 1].Peek(),
					*m_board.GetPlay().getStack()[moving - 1].Peek()))
				{
					//this pushes the card onto the stack
					m_board.GetPlay().getStack()[moving - 1].Push(m_board.GetPlay().getStack()[columnchoice - 1].Pop());

					//display the whole board again
					m_board.FreeA(); // displays the free cell area
					m_board.HomeA(); // displays the home cell area
					m_board.PlayA(); // displays the play area
				}
				else
				{
					cout << "You cannot do that! You need the cards to be opposite color and more than 1 needed to be chosen";
				}
			}
		}

	}
	if (m_board.GetHome().Winner() == true)
	{
		cout << "YOU WIN!!!!!!!!!!" << endl;
	}
}

int FreeCellGame::getcolumn()
{
	COORD cursor;
	int column;
	bool valid = false;

	while (valid == false)
	{

		cursor.X = 0;
		cursor.Y = 20; // starts 20 down


		cout << "column: " << endl;
		cout << "Enter -2 if you want to take from a free cell" << endl;
		cin >> column;

		if (column > 8 || column == 0 || column == -1 || column < -2)
		{
			cursor.X = 0;
			cursor.Y = 23; // moves to 23 down;

			cout << "Not in range!" << endl;
		}
		else if (column == -2)
		{
			int answer = 0;
			cout << "Would you like to try to move from a free cell? yes = 1 no = 0 ";
			cin >> answer;

			if (answer == 1)
				valid = true; // means they can try to move from the freecell

		}
		else
		{
			valid = true;
		}

	}
	m_column = column;
	return column;
}

int FreeCellGame::Getnum()
{
	COORD cursor;
	int numcards;
	bool valid = false;

	while (valid == false)
	{

		cursor.X = 0;
		cursor.Y = 20; // starts 20 down


		cout << "# of cards you want to move: " << endl;
		cin >> numcards;

		if (numcards > 8 || numcards <= 0 )
		{
			cursor.X = 0;
			cursor.Y = 23; // moves to 23 down;

			cout << "Not in range!" << endl;
		}
		else
		{
			valid = true;
		}

	}
	m_numofcards = numcards;
	return numcards;
}

int FreeCellGame::Getmoving()
{
	COORD cursor;
	bool valid(false);
	int column;
	while (valid == false)
	{
		cursor.X = 0;
		cursor.Y = 20; // starts 20 down

		cout << "Move to Column:     ";
		cout << endl << endl << "Enter -1 to move to Home Cell " << endl;
		cout << "Enter -2 to move to Free Cells " << endl;

		cin >> column;

		if (column > 8 || column == 0 || column <= -3)
		{
			cursor.X = 0;
			cursor.Y = 30;

			cout << "Invalid Range";
		}

		else if (m_column == column)
		{
			cursor.X = 0;
			cursor.Y = 30;

			cout << "Cant move to the same column, dingus! Try again" << endl;
		}

		else if (column == -1)
		{
			cursor.X = 0;
			cursor.Y = 30;

			int answer = 0;
			cout << "Would you like to try to move to a home cell? yes = 1 no = 0 ";
			cin >> answer;

			if (answer == 1)
				valid = true; // means they can try to move from the freecell
		}

		else if (column == -2)
		{
			cursor.X = 0;
			cursor.Y = 30;

			int answer = 0;
			cout << "Would you like to try to move to a free cell? yes = 1 no = 0 ";
			cin >> answer;

			if (answer == 1)
				valid = true; // means they can try to move to a freecell
		}

		if (column == -1 && m_column == -2)
		{
			cursor.X = 0;
			cursor.Y = 35;

			cout << "cant move to that area!"; 
		}

		else
		{
			valid = true;
		}
	}
	m_moving = column;
	return column;
}

void FreeCellGame::PutinFreeCell(Card free, int position)
{
	COORD cursor;

	if (position == 1)
	{
		cursor.X = position;
		cursor.Y = 3;
	}
	else if (position == 2)
	{
		cursor.X = position + 5;
		cursor.Y = 3;
	}
	else if (position == 3)
	{
		cursor.X = position + 10;
		cursor.Y = 3;
	}
	else
	{
		cursor.X = position + 15;
		cursor.Y = 3;
	}

	free.Display();
}

void FreeCellGame::PutinHome(Card home)
{
	COORD cursor;

	int position(55);
	Card temp;
	Card Compare;
	temp.SetSuit(home.GetSuit());

	for (int i(0); i < 4; i++)
	{

		if (temp.GetSuit() == Compare.Spades)
		{
			cursor.X = position + 1;
			cursor.Y = 3;
		}
		else if (temp.GetSuit() == Compare.Diamonds)
		{
			cursor.X = position + 7;
			cursor.Y = 3;
		}
		else if (temp.GetSuit() == Compare.Hearts)
		{
			cursor.X = position + 13;
			cursor.Y = 3;
		}
		else if (temp.GetSuit() == Compare.Clubs)
		{
			cursor.X = position + 19;
			cursor.Y = 3;
		}
		home.Display();
	}
}

void FreeCellGame::clear(int position)
{
	COORD cursor;

	if (position == 1)
	{
		cursor.X = position;
		cursor.Y = 3;
	}
	else if (position == 2)
	{
		cursor.X = position + 5;
		cursor.Y = 3;
	}
	else if (position == 3)
	{
		cursor.X = position + 10;
		cursor.Y = 3;
	}
	else
	{
		cursor.X = position + 15;
		cursor.Y = 3;
	}

	cout << "    ";
}

void FreeCellGame::cheat(int pass)
{
	Card temp;

	Card c1;
	c1.SetRank(temp.King);
	c1.SetSuit(temp.Diamonds);
	m_board.GetHome().SetHomeCell(c1, pass);
	Card c2;
	c2.SetRank(temp.King);
	c2.SetSuit(temp.Hearts);
	m_board.GetHome().SetHomeCell(c2, pass);
	Card c3;
	c3.SetRank(temp.King);
	c3.SetSuit(temp.Clubs);
	m_board.GetHome().SetHomeCell(c3, pass);
	Card c4;
	c4.SetRank(temp.King);
	c4.SetSuit(temp.Spades);
	m_board.GetHome().SetHomeCell(c4, pass);
}


