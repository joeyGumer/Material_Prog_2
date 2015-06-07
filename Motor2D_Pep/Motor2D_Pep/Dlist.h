#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdlib.h>
#include <assert.h>

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
class Dlist
{

public:

	Node<TYPE>* start;
	Node<TYPE>* end;//with the end it goes faster

private:

	unsigned int size;

public:
	/*
	Constructor
	*/
	inline Dlist()
	{
		start = end = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~Dlist()
	{
		Clear();
	}

	/*
	Methods
	*/
	//Add
	int Add(const TYPE& newValue)
	{
		Node<TYPE>* newNode;
		newNode = new Node<TYPE>(newValue);

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

		size++;
		return size;
	}

	bool Delete(Node<TYPE>* delNode)
	{
		if (delNode == NULL)
		{
			return (false);
		}

		if (delNode != start)
		{
			delNode->prev->next = delNode->next;

			if (delNode != end)
			{
				delNode->next->prev = delNode->prev;
			}
			else
			{
				end = delNode->prev;
			}
		}
		else
		{
			if (delNode != end)
			{
				delNode->next->prev = NULL;
				start = delNode->next;
			}
			else
			{
				end = start = NULL;
			}
		}

		delete[] delNode;
		size--;
		return (true);
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
	Sort
	*/
	unsigned int BubbleSort()
	{
		Node<TYPE>* tmp = start;
		bool change = true;
		unsigned int counter = 0;

		while (change == true)
		{
			change = false;
			for (int i = 0; i < size - 1; i++)
			{
				counter++;
				if (tmp->value > tmp->next->value)
				{
					NodeSwap(tmp, tmp->next);
					change = true;
				}
				else
					tmp = tmp->next;
			}
			tmp = start;
		}

		return counter;
	}
	/*
	other utils
	*/
	//Comrpovar si esta ben fet
	void NodeSwap(Node<TYPE>* a, Node<TYPE>* b)
	{
		a->next = b->next;
		b->next = a;

		b->prev = a->prev;
		a->prev = b;

		if (start != a)
			b->prev->next = b;
		else
			start = b;
		
		if (end != b)
			a->next->prev = a;
		else
			end = a;

	}

	unsigned int GetCapacity() const
	{
		return size;
	}

	Node<TYPE>* GetFirst() const
	{
		return start;
	}

	Node<TYPE>* GetLast() const
	{
		return end;
	}

	Node<TYPE>* GetByIndex(const unsigned int index) const
	{
		Node<TYPE>* tmp = start;
		unsigned int counter = 0;

		while (counter != index && tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		if (tmp != NULL)
			return tmp;

		return NULL;
	}

	/*
	operator
	*/

	const Dlist<TYPE>& operator += (const Dlist<Node<TYPE>*>& list)
	{
		Node<TYPE>* tmp = list.start;

		for (; tmp != NULL; tmp = tmp->next)
		{
			Add(tmp);
		}

		return(this*);
	}

	const TYPE& operator [] (const unsigned int index) const
	{
		Node<TYPE>* ret = GetByIndex(index);

		assert(ret != NULL);
		
		return ret->value;
	}

	TYPE& operator [] (const unsigned int index) 
	{
		Node<TYPE>* ret = GetByIndex(index);

		assert(ret != NULL);

		return ret->value;
	}

	/*
	Method for the exercise 3
	*/
	unsigned int delNodes(const unsigned int index, const unsigned int delSize)
	{
		Node<TYPE>* tmp = GetByIndex(index);
		Node<TYPE>* tmp2;

		unsigned int counter = 0;

		while (counter != delSize && tmp != NULL)
		{
			tmp2 = tmp->next;
			Delete(tmp);
			tmp = tmp2;

			counter++;
		}

		return counter;
	}
};

#endif // !_DLIST_H_