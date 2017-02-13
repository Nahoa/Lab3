#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <iostream>
using std::ostream;
/************************************************************************
* Class: Exception
*
* Purpose: This class manages exceptions and the message associated with
*		   each one, describing the reason for the error.
*
* Manager functions:
* 	Exception ()
* 		The default msg is set to nullptr.
*	Exception (char * msg)
*		Assigns the m_msg to msg.
*	Exception (const Exception & copy)
*		Sets m_msg to copy.m_msg.
*	operator= (const Exception & rhs)
*		Checks for self-assignment, then sets m_msg to copy.m_msg.
*	~Exception()
*		Deletes m_msg and resets it to nullptr.
*
Methods:
*	GetMessage() const
*		Returns m_msg;
*	SetMessage(char * msg)
*		Sets m_msg to msg;
*	operator<<
*		Overloads the ouptut operator to allow simple output of an exception.
*************************************************************************/

class Exception
{
public:
	Exception();
	Exception(char * copy); // ctor with a char * parameter
	Exception(const Exception & copy); // copy ctor
	Exception& operator=(const Exception & rhs);
	~Exception();
	char * GetMessage() const;
	void SetMessage(char * msg);

private:
	char * m_msg;
};
//output operator cannot be in the class because it has to be a data memeber this was the overloaded operator is free

#endif
