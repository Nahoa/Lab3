#ifndef HOMECELLAREA_H
#define HOMECELLAREA_H

#include "Stack.h"
#include "Array.h"
#include "Card.h"

class HomeCellArea
{
public:
	HomeCellArea();
	HomeCellArea(const HomeCellArea & copy);
	HomeCellArea &operator=(const HomeCellArea &rhs);
	~HomeCellArea();

	Card GetTop(int column);
	bool GetEmpty(int column);
	bool SetHomeCell(Card home, int pass);
	bool Winner();
	void Display();
private:
	Array<Stack<Card>> m_home_cells; // creates an array of stacks
};
#endif