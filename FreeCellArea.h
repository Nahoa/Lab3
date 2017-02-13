#ifndef FREECELLAREA_H
#define FREECELLAREA_H

#include "Array.h"
#include "Card.h"

const int MAXAREA = 4; // only 4 spaces for the freecell

class FreeCellArea
{
public:
	FreeCellArea();
	FreeCellArea(FreeCellArea & copy);
	FreeCellArea operator=(const FreeCellArea &rhs);
	~FreeCellArea();

	int getOpenSpace();
	bool isFull();
	void MovetoFreeCell(Card * free_card);
	void RemovefromFreeCell(int index);
	Array<Card*> &getFree(); // gets the array of cards in the freecell
	int Calculate(); //Magic formula to get the ammount of cards to move 
	void Display();
private:
	Array<Card*> m_free_cells;
	int m_current_spots;
};
#endif