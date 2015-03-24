#ifndef _DLIST_H_
#define _DLIST_H_

template<class TYPE>
struct Node
{
	TYPE value;
	Node<TYPE>* next;
	Node<TYPE>* prev;

	Node<TYPE>(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}
};

template<class TYPE>
class cDlist
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
	cDlist()
	{
		start = end = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~cDlist()
	{
		Clear();
	}

	/*
	Methods
	*/
	TYPE Add(const TYPE& newValue)
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
	other utils
	*/

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
		unsigned int counter = 1;
		
		while (counter != index && tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		return tmp;
	}
	//poner aqui antes del examen
};

#endif // !_DLIST_H_
