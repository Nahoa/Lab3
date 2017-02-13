#include "PlayArea.h"



PlayArea::PlayArea() : m_stack(8)
{
}

PlayArea::PlayArea(const PlayArea & copy)
{
	*this = copy;
}

PlayArea & PlayArea::operator=(const PlayArea & rhs)
{
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;
	}
	return *this;
}


PlayArea::~PlayArea()
{
}


Array<LLStack<Card*>>& PlayArea::getStack()
{
	return m_stack;
}

void PlayArea::Display(int index)
{
	//for (int i = 0; i < 8; i++) // this controls the column (Array)
	//{
	m_stack[index].Display(); // maybe this'll work
	//}
}
