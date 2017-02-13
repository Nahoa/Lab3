#ifndef STACK_H
#define STACK_H
#include "Array.h"
#include "Exception.h"

template<typename T>
class Stack
{
public:
	Stack();
	Stack(int stack_size);
	Stack(const Stack & copy);
	Stack<T>& operator=(const Stack & rhs);
	~Stack();
	void Push(T data);
	T Pop(); //pops the top element and returns that data
	T Peek(); //returns the data at the top but doesn't remove it
	int Size(); //returns the number of elements on the stack
	bool isEmpty(); //returns true if the stack is empty
	bool isFull(); // returns true if the stack is full
	void setLength(int length);

private:
	Array<T> m_stack;
	int m_stack_size;
	int m_current_size;
	int m_start_index;
};


template<typename T>
inline Stack<T>::Stack(): m_current_size(0), m_stack_size(0), m_start_index(0)
{
}

template<typename T>
inline Stack<T>::Stack(int stack_size) :  m_current_size(0), m_stack_size(stack_size), m_start_index(0)
{
}

template<typename T>
inline Stack<T>::Stack(const Stack & copy)
{
	if (copy.m_stack != nullptr)
	{
		m_stack = copy.m_stack;
		m_current_size = copy.m_current_size;
		m_stack_size = copy.m_stack_size;
		m_start_index = copy.m_start_index;
	}

}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack & rhs)
{
			m_stack = rhs.m_stack;
			m_current_size = rhs.m_current_size;
			m_stack_size = rhs.m_stack_size;
			m_start_index = rhs.m_start_index;

	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{
	m_current_size = 0;
	m_stack_size = 0;
	m_start_index = 0;
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	m_current_size++;
	if (m_current_size > m_stack_size)
	{
		m_current_size--;
		throw Exception("Exception! Cannot push! The stack is full!");
	}
	else
	{
		Array<T> temp(m_current_size, 0);
		temp = m_stack;

		temp.SetLength(m_current_size);
		temp[m_current_size - 1] = data;
		m_stack.SetLength(m_current_size);
		//Copy everything over to the old array
		m_stack = temp;
	}

}

template <typename T>
T Stack<T>::Pop()
{
	T pop_return;

	if (m_current_size <= 0)
		throw Exception("Exception! Cannot pop! The stack is empty");
	else
	{
		pop_return = m_stack[m_current_size - 1];
		m_current_size--;


		m_stack.SetLength(m_current_size);
	}
	return pop_return;
}


template <typename T>
T Stack<T>::Peek()
{
	return m_stack[m_current_size - 1];
}

template <typename T>
int Stack<T>::Size()
{
	return m_current_size;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	bool empty = true;
	if (m_current_size > 0)
		empty = false;
	return empty;

}

template <typename T>
bool Stack<T>::isFull()
{
	bool full = false;
	if (m_current_size >= m_stack_size)
		full = true;
	return full;
}

template <typename T>
void Stack<T>::setLength(int length)
{
	m_stack_size = length;
}
#endif