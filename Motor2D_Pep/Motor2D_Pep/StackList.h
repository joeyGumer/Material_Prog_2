#ifndef _STACKLIST_H_
#define _STACKLIST_H_

#include <assert.h>
#include <stdlib.h>
#include "Dlist.h"

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class StacklIST
{

private:
	Node<TYPE>* start, end;


public:

	//Constructors
	Stack()
	{
		start = end = NULL;
	}

	//Destructors
	~Stack()
	{
	}

	//Methods

	//Puts an element at the end of the stack
	void Push(const TYPE newValue)
	{
		Node<TYPE>* newNode = new Node<TYPE>(newValue)

		if (start == NULL)
		{
			start = end = newNode;
		}
		else
		{
			end->next = newNode;
			newNode->prev = end;
			end = newNode;
		}
	}

	//Puts out the last element
	bool Pop(TYPE& value)
	{
		if (start != NULL)
		{
			value = end->value;
			end->prev = end;
			return true;
		}
		return false;
	}

	//Chooses an element from the stack
	const TYPE* Peek(const unsigned int index)const
	{
		TYPE* ret = NULL;

		if (index < numElements)
			return ret = &data[index];

		return ret;
	}
}
#endif