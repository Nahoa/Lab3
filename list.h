#ifndef LIST_H
#define LIST_H
#include "Node.h"

template<typename T>
class List
{

public:
	List();
	List(const List & copy);
	List & operator=(const List & rhs);
	~List();
	int Search(T Data);
	Node<T> * gethead() { return m_head; }
	Node<T> * gettail() { return m_tail; }
	bool isEmpty();
	T & First() const;
	T & Last() const;
	void Display();
	void Prepend(T Data); //adds to the front of the list
	void Append(T Data); //adds to the end of the list maybe pointer?
	void Extract(T Data);
	void InsertAfter(T NData, T insertafter); //(element to insert, after other node)
	void InsertBefore(T NData, T insertbefore); //(element to insert, before other node)
	void Purge();

private:
	Node<T> * m_head;
	Node<T> * m_tail;
};

template<typename T>
inline List<T>::List() : m_head(nullptr), m_tail(nullptr) //base member so the head and the tail both point to null
{

}

template<typename T>
inline List<T>::List(const List & copy) :m_head(nullptr), m_tail(nullptr)
{
	*this = copy;
}


template<typename T>
inline List<T> & List<T>::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		if (this->m_head != nullptr)
		{
			Purge();
		}

		Node<T> * travel = rhs.m_head;
		while (travel)
		{
			this->Append(travel->Data);
			travel = travel->m_next;
		}
	}
	return *this;
}

template<typename T>
inline List<T>::~List()
{
	Purge(); //calls the purge function
}

template<typename T>
inline int List<T>::Search(T Data)
{
	Node<T> * travel = m_head;
	int i = 0; //starts at 0
	bool found = false;
	while (travel != nullptr && found == false)
	{
		if (Data == travel->Data)
		{
			i = i - 1;
			found = true;
		}
		travel = travel->m_next;
		i++;
	}

	if (found == false)
	{
		i = -1; // if the data isn't found it returns -1
	}

	return i;
}

template<typename T>
inline void List<T>::Purge()
{
	Node<T> * travel = m_head;

	while (m_head) // while m_head != nullptr
	{
		travel = m_head;
		m_head = m_head->m_next;

		delete travel;
	}

	m_head = nullptr; //sets the head back to nullptr
	m_tail = nullptr; //sets the tail back to nullptr
}

template<typename T>
inline bool List<T>::isEmpty()
{
	bool found = false;

	if (m_head == nullptr && m_tail == nullptr) // if the head and tail point to nullptr then the string is empty
		found = true;

	return found;
}
template<typename T>
inline T & List<T>::First() const
{
	if (m_head == nullptr)
	{
		throw Exception("Head is Empty!!");
	}

	return m_head->Data;
}

template<typename T>
inline T & List<T>::Last() const
{	
	if (m_tail == nullptr)
	{
		throw Exception("Head is Empty!!");
	}

	return m_tail->Data;
}

template<typename T>
inline void List<T>::Display()
{
	Node<T> * travel = m_head;
	Node<T> * back = m_tail;

	if (m_head == nullptr)
	{
		cout << "list is empty" << endl;
	}

	/*while (travel)
	{
		cout << travel->Data << " ";
		travel = travel->m_next;
	}

	cout << endl;*/

	// uncomment to see it in reverse
	while (back)
	{
		cout << back->Data << endl;
		back = back->m_previous;
	}

	cout << std::endl;

}

template<typename T>
inline void List<T>::Prepend(T Data)
{
	//nn stands for new node
	Node<T> * nn = new Node<T>(Data); // creates a new node
	if (m_head == nullptr) // when the first node is created it will allways be the tail
	{
		m_tail = nn;
		m_head = nn; //head is always going to be the new node
	}
	else
	{
		m_head->m_previous = nn;
		nn->m_next = m_head; //assigning the m_head to new nodes m_next pointer
		m_head = nn; //head is always going to be the new node
		nn->m_previous = nullptr;
	}
}

template<typename T>
inline void List<T>::Extract(T Data)
{
	Node<T> * travel = m_head;

	int index = Search(Data);

	for (int i = 0; i < index; i++)
	{
		travel = travel->m_next;
	}

	if (index == -1)
	{
		throw Exception("Data not found!");
	}
	else
	{
		if (travel->Data == m_head->Data) // head pointer reassigns
		{
			m_head = m_head->m_next;
			delete travel;
			travel = nullptr;
		}
		else if (travel->Data == m_tail->Data) //tail pointer reassigns
		{
			m_tail = m_tail->m_previous;
			m_tail->m_next = nullptr;
			delete travel;
			travel = nullptr;
		}
		else
		{
			travel->m_next->m_previous = travel->m_previous; // reassigns pointer
			travel->m_previous->m_next = travel->m_next;
			delete travel;
			travel = nullptr;
		}
	}
}

template<typename T>
inline void List<T>::Append(T Data)
{
	Node<T> * nn = new Node<T>(Data); // creates a new node
	if (m_head == nullptr) // when the first node is created it will allways be the tail
	{
		m_tail = nn;
		m_head = nn;
	}
	else
	{
		m_tail->m_next = nn;
		nn->m_previous = m_tail;
		m_tail = nn;
		nn->m_next = nullptr;
	}

}


template<typename T>
inline void List<T>::InsertAfter(T NData, T insertafter)
{
	Node<T> * travel = m_head;

	int index = Search(insertafter);

	for (int i = 0; i < index; i++)
	{
		travel = travel->m_next;
	}

	if (index == -1)
	{
		throw Exception("Data not found!");
	}
	else
	{
			 if (travel->Data == m_tail->Data) //tail pointer reassigns
			{
				Append(NData);
			
			}
			else
			{

				Node<T> * nn = new Node<T>(NData);
				nn->m_next = travel->m_next;
				nn->m_previous = travel;//assigns the old pointer 
				travel->m_next = nn;
				nn->m_next->m_previous = nn;
				

			}
		}
}

template<typename T>
inline void List<T>::InsertBefore(T NData, T insertbefore)
{
	Node<T> * travel = m_head;

	int index = Search(insertbefore);

	for (int i = 0; i < index; i++)
	{
		travel = travel->m_next;
	}

	if (index == -1)
	{
		throw Exception("Data not found!");
	}
	else
	{
		if (travel->Data == m_head->Data) //tail pointer reassigns
		{
			Prepend(NData);

		}
		else
		{

			Node<T> * nn = new Node<T>(NData);
			nn->m_previous = travel->m_previous;
			nn->m_next = travel;//assigns the old pointer 
			travel->m_previous = nn;
			travel->m_previous->m_previous->m_next = nn;
		}
	}
}

#endif