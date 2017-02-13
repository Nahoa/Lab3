#ifndef NODE_H
#define NODE_H
//forward declaration NEEDED
template <typename T>
class List;


template <typename T>
class Node
{
	friend class List<T>;
public:
	Node();
	Node(T Data);
	Node(const Node & copy);
	Node & operator=(const Node & rhs);
	~Node();
private:
	T Data;
	Node * m_next;
	Node * m_previous;
};


template<typename T>
inline Node<T>::Node() : m_next(nullptr), m_previous(nullptr) //base memeber so the first node created points to null both ways
{
}

template<typename T>
inline Node<T>::Node(T Data) : Data(Data), m_next(nullptr),m_previous(nullptr) // creates a node with Data in it 
{

}

template<typename T>
inline Node<T>::Node(const Node & copy) :m_Data(copy.m_Data), m_Next(copy.m_Next), m_Previous(copy.m_Previous)
{
}

template<typename T>
inline Node<T> & Node<T>::operator=(const Node & rhs)
{
	if (this != &rhs)
	{
		m_Data = rhs.m_Data;
	}
	return *this;
}

template<typename T>
inline Node<T>::~Node()
{

}
#endif