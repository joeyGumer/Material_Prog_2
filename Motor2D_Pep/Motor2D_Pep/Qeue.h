#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
template<class TYPE>
struct Node
{
	TYPE value;
	Node<TYPE>* next;
	Node<TYPE>* prev;

	inline Node<TYPE>(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}
};

template<class TYPE>
class Queue
{

public:

	Node<TYPE>* end;

private:

	unsigned int size;

public:
	/*
	Constructor
	*/
	inline Queue()
	{
		end = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~Queue()
	{
		Clear();
	}

	/*
	Methods
	*/
	unsigned int Push(const TYPE& newValue)
	{
		Node<TYPE>* newNode;
		newNode = new Node<TYPE>(newValue);

		if (start == NULL)
		{
			start = end = newNode;
		}
		else
		{
			start->prev = newNode;
			newNode->next = start;
			start = newNode;
		}
		size++;
		return size;
	}

	bool Pop(TYPE& valor)
	{
		Node<TYPE>* tmp = end;

		end = tmp->prev;
		end->next = NULL;

		return tmp->value;
	}

	void Clear()
	{
		Node<TYPE>* tmp = start;
		Node<TYPE>* tmp2;

		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}

		start = end = NULL;

		size = 0;
	}
	/*
	other utils
	*/

	
};

#endif // !_QUEUE_H_