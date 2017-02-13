#ifndef BOARD_H
#define BOARD_H

#include "PlayArea.h"
#include "FreeCellArea.h"
#include "HomeCellArea.h"
#include "Deck.h"

class Board
{
public:
	Board();
	Board(const Board & copy);
	Board & operator=(const Board &rhs);
	~Board();

	void PlayA(); //displays the play area
	void HomeA(); //displays the home area
	void FreeA(); // displays the free area

	void Populate();
	bool isValidMove(Card move, Card bottom);
	PlayArea &GetPlay();
	FreeCellArea &GetFree();
	HomeCellArea &GetHome();
private:
	Deck m_deck;
	PlayArea m_play_area;
	FreeCellArea m_free_cell_area;
	HomeCellArea m_home_cell_Area;
};
#endif
