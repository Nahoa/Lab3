#ifndef LLSTACK_H
#define LLSTACK_H
#include "Exception.h"
#include "List.h"

template<typename T>
class LLStack
{
public:
	LLStack();
	LLStack(const LLStack<T> & copy);
	LLStack<T>& operator= (const LLStack<T> & rhs);
	~LLStack();
	void Push(T data);
	T Pop(); //pops the top element and returns that data
	T Peek(); //returns the data at the top but doesn't remove it
	int Size(); //returns the number of elements on the stack
	bool isEmpty(); //returns true if the stack is empty
	void Display();

private:
	List<T> m_stack;
	int m_current_size;

};


template<typename T>
LLStack<T>::LLStack() : m_stack(List<T>()), m_current_size(0)
{
}

template<typename T>
inline LLStack<T>::LLStack(const LLStack<T>& copy)
{
	m_stack = copy.m_stack;
	m_current_size = copy.m_current_size;
}

template<typename T>
inline LLStack<T>& LLStack<T>::operator=(const LLStack<T>& rhs)
{
	// TODO: insert return statement here
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;
		m_current_size = rhs.m_current_size;
	}
	return *this;
}

template<typename T>
LLStack<T>::~LLStack()
{
	m_current_size = 0;
}

template<typename T>
inline void LLStack<T>::Push(T data)
{
	m_stack.Append(data);
	m_current_size++;
}

template<typename T>
inline T LLStack<T>::Pop()
{
	T pop_return;

	if (m_current_size <= 0)
		throw Exception("Exception! Cannot pop! The stack is empty");
	else
	{
		m_current_size--;
		pop_return = m_stack.First(); // shows the last element 

		m_stack.Extract(m_stack.First()); // removes it from the list
	}

	return pop_return;
}

template<typename T>
inline T LLStack<T>::Peek()
{
	return m_stack.Last();
}

template<typename T>
inline int LLStack<T>::Size()
{
	return m_current_size;
}

template<typename T>
inline bool LLStack<T>::isEmpty()
{
	bool empty = true;

	if (m_current_size > 0)
		empty = false;

	return empty;
}

template<typename T>
inline void LLStack<T>::Display()
{
	for (int i = 0; i < m_current_size; i++)
	{
		cout << endl;
		m_stack.Display();
	}
}

#endif