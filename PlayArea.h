#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "LLStack.h"
#include "Array.h"
#include "Card.h"


class PlayArea
{
public:
	PlayArea();
	PlayArea(const PlayArea & copy);
	PlayArea &operator=(const PlayArea &rhs);
	~PlayArea();

	Array<LLStack<Card*>> &getStack();
	void Display(int index);
private:
	Array<LLStack<Card*>> m_stack;
};
#endif

