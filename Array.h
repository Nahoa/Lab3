#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base.
*
* Manager functions:
* 	Array ( )
* 		The default length is zero and the start index is zero.
*	Array (int length, int start_index = 0)
*		Creates an appropriate sized array with the starting index
*              either zero or the supplied starting value.
*	Array (const Array & copy)
*		Creates a new array of size m_length and copies over the data
*		from existing array into the new one.
*	operator= (const Array & rhs)
*		Checks for self-assignment,creates a new array of size m_length 
*		and copies over the data from the old array into the new one.
*	~Array()
*		Releases allocated/borrowed memory.
*
* Methods:
*	operator[](int index)
*		Overloads the subscript operator to allow indexing for this array
*		type. Returns (index-srating_index).
*	GetStartIndex() const
*		Returns the starting index of the array.
*	SetStartIndex(int start_index)
*		Sets the starting index of the array to the index passed into it.
*	GetLength() const
*		Returns the length of the array.
*	SetLength(int length)
*		Sets the length of the array to the length passed into it.
*************************************************************************/

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);// sets the start index to zero
	Array(const Array & copy);//Copy Ctor
	~Array();
	Array& operator=(const Array &rhs); // overloading the = assignment operator
	T & operator[](int index); //overloads the template [] operator 
	int GetStartIndex() const; //returns the starting index of the array
	void SetStartIndex(int start_index); // sets the starting index of the array
	int GetLength() const;//gets the Length of the array
	void SetLength(int Length); // sets the length of the array

private:
	T * m_array;
	int m_length;
	int m_start_index;

};


/**********************************************************************
* Purpose: This function base member initializes the data members.
*
* Precondition:	None
*
* Postcondition: m_length is set to zero, m_start_index is set to zero,
*			     and m_array is set to nullptr.
************************************************************************/
template<typename T>
inline Array<T>::Array() : m_length(0), m_start_index(0), m_array(nullptr)
{
}

/**********************************************************************
* Purpose: This function base member initializes the data members.
*
* Precondition:	None
*
* Postcondition: m_length is set to length, m_start_index is set to start_index,
*			     and m_array is set to a new array of m_length.
************************************************************************/
template<typename T>
inline Array<T>::Array(int length, int start_index) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
	m_array = new T[m_length];
}

/**********************************************************************
* Purpose: This function is a copy ctor.
*
* Precondition:	The copy has to be empty. 
*
* Postcondition: If copy is empty then all the array is copied over
*
************************************************************************/
template<typename T>
inline Array<T>::Array(const Array & copy) : m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	m_array = new T[m_length];
	if (copy.m_array != nullptr)
	{

		for (int i = m_start_index; i < m_length; i++)//deep copy
		{
			m_array[i] = copy.m_array[i]; // copies anything that is in the OG array into the copyied array
		}
	}
}

/**********************************************************************
* Purpose: This function deletes the array and resets the data members.
*
* Precondition:	None
*
* Postcondition: The array is deleted and it and the data members are reset
*
************************************************************************/
template<typename T>
inline Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0; // restores the length to a default state
	m_start_index = 0; //restores the length to a default state
}

/**********************************************************************
* Purpose: This function is an overloaded operator = 
*
* Precondition:	It takes in the right hand side.
*		 
* Postcondition: Returns *this.
*
************************************************************************/
template<typename T>
inline Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs) //checks to see if the left side element is not the same as the right side element
	{
		if (rhs.m_array != nullptr)
		{
			delete[] m_array;
			m_length = rhs.m_length;
			m_start_index = rhs.m_start_index;

			m_array = new T[m_length];

			for (int i = 0; i < m_length; i++) // deep copy
			{
				m_array[i] = rhs.m_array[i];
			}
		}

	}
	return *this;
}

/**********************************************************************
* Purpose: This function is an overloaded operator []
*
* Precondition:	it takes in an index.
*
* Postcondition: returns the element of that index at that point in the array
*
************************************************************************/
template<typename T>
inline T & Array<T>::operator[](int index)
{
	index = index - m_start_index;

	if (index >= m_length) //checks to see if the thing being checked is in the length range // commented out >= to = 
	{
		//throws exception that the index is above the range
		throw Exception("Above Range");
	}
	else if (index < 0) //checks to see if the index being accessed is above the start index
	{
		//throws exception that the index is below the range
		throw Exception("Below Range");
	}

	return m_array[index];
}

/**********************************************************************
* Purpose: This function is a getter for the start index.
*
* Precondition:	None
*
* Postcondition: Returns m_start_index.
*
************************************************************************/
template<typename T>
inline int Array<T>::GetStartIndex() const
{
	return m_start_index;

}

/**********************************************************************
* Purpose: This function is a setter for the start index
*
* Precondition:	The index the user wants to start it at. 
*
* Postcondition: Returns m_start_index at whatever was passed through
*
************************************************************************/
template<typename T>
inline void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;

}

/**********************************************************************
* Purpose: This function gets the length of the array
*
* Precondition:	None.
*
* Postcondition: Returns m_length
*
************************************************************************/
template<typename T>
inline int Array<T>::GetLength() const
{
	return m_length;

}

/**********************************************************************
* Purpose: This function sets m_length to any new positive length
*
* Precondition:	a int of length.
*
* Postcondition: Returns a new array with the new length created and the
*		same data inside
*
************************************************************************/
template<typename T>
inline void Array<T>::SetLength(int Length)
{
	if (Length < 0)
	{
		throw Exception("You cannot have a negative array!");
	}
	else
	{
		int len = Length < m_length ? Length : m_length; //checks to see if the array is bigger or smaller and how much space is needed to copy

		T * temp = new T[Length]; // creates a new temp array

		for (int i = 0; i < len; i++) // copies all the elements from the old array into the new temp array
		{
			temp[i] = m_array[i];
		}

		delete[] m_array; // deletes the old array
		m_array = nullptr;

		m_array = new T[Length]; //makes a new array with the new length

		for (int i = 0; i < Length; i++) // puts everything in the temp array into the new array
		{
			m_array[i] = temp[i];
		}

		m_length = Length;

		delete[]temp; //deletes the old array
		temp = nullptr;

	}
}
#endif