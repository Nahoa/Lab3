#ifndef FREECELLGAME_H
#define FREECELLGAME_H

#include "Board.h"

class FreeCellGame
{
public: // missing public here so it made everything private 
	FreeCellGame();
	~FreeCellGame();
	void RunGame();

	int getcolumn();
	int Getnum();
	int Getmoving();

	void PutinFreeCell(Card free, int position);
	void PutinHome(Card home);
	void clear(int position);
	void cheat(int pass);
private:
	Board m_board;
	int m_column;
	int m_numofcards;
	int m_moving;
};
#endif
 