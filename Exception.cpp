#include "Exception.h"

/**********************************************************************
* Purpose: This function initialized m_msg to nullptr.
*
* Precondition:	None.
*
* Postcondition: m_msg is set to nullptr.
************************************************************************/
Exception::Exception() :m_msg(nullptr)
{

}

/**********************************************************************
* Purpose: This function base member initialize m_msg to nullptr.
*
* Precondition:	a word is passed in.
*
* Postcondition: m_msg is set to whatever was passed in.
************************************************************************/
Exception::Exception(char * copy) : m_msg(nullptr)
{
	if (copy != nullptr)
	{
		m_msg = new char[strlen(copy) + 1]; // allocates enough memory to copy over 
		strcpy(m_msg, copy); // assigns the characters entered to the data member
	}
}

/**********************************************************************
* Purpose: This functionis a copy ctor.
*
* Precondition:	the thing to be copied if it is not nullptr.
*
* Postcondition: m_msg is set to whatever was passed in.
************************************************************************/
Exception::Exception(const Exception & copy) :m_msg(nullptr)
{
	if (copy.m_msg != nullptr)
	{
		m_msg = new char[strlen(copy.m_msg) + 1]; // allocates enough memory to copy over 
		strcpy(m_msg, copy.m_msg); // assigns the characters entered to the data member
	}
}

/**********************************************************************
* Purpose: This function is an overloaded operator =.
*
* Precondition:	the right hand side.
*
* Postcondition: if the rhs is not null then m_msg = rhs.m_msg.
************************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	// TODO: insert return statement here
	if (this != &rhs) // checks for self assignment
	{
		if (rhs.m_msg != nullptr) //  checks to see if m_msg has anyting inside of it 
		{
			delete[] m_msg;
			m_msg = new char[strlen(rhs.m_msg) + 1]; // allocates enough memory to copy over the rhs's message and gives room for the null
			strcpy(m_msg, rhs.m_msg);//copies over the rhs message into the data member m_msg
		}
	}

	return *this;
}

/**********************************************************************
* Purpose: This function releases the memory.
*
* Precondition:	None
*
* Postcondition: m_msg is deleted and set to nullptr.
************************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}

/**********************************************************************
* Purpose: This function gets m_msg.
*
* Precondition:	None.
*
* Postcondition: Returns m_msg.
************************************************************************/
char * Exception::GetMessage() const
{
	return m_msg;
}

/**********************************************************************
* Purpose: This function sets m_msg.
*
* Precondition:	a char * is passed in.
*
* Postcondition: m_msg is set to what was passed in.
************************************************************************/
void Exception::SetMessage(char * msg)
{
	m_msg = msg;
}

/**********************************************************************
* Purpose: This function overloads the << operator.
*
* Precondition:	the ostream and the exception.
*
* Postcondition: Returns the m_msg and displays it to the window.
************************************************************************/
ostream & operator<<(ostream & stream, const Exception & except)
{
	// TODO: insert return statement here
	return stream << except.GetMessage();
}
