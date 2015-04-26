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
class cQueue
{

public:

	Node<TYPE>* end;

private:

	unsigned int size;

public:
	/*
	Constructor
	*/
	inline cQueue()
	{
		end = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~cQueue()
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

	bool Pop(TYPE& _value)
	{
		if (start != NULL)
		{
			Node<TYPE>* tmp = end;
			
			_value = tmp;

			end = tmp->prev;
			end->next = NULL;

			delete tmp;
			return true;
		}
		return false;
	}

	const TYPE Pick(){}


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