#ifndef _DLIST_H_
#define _DLIST_H_

template<class TYPE>
struct Node
{
	TYPE value;
	Node<TYPE>* next;
	Node<TYPE>* prev;
};

template<class TYPE>
class cDlist
{

public:

	Node<TYPE>* start;
	Node<TYPE>* end;//with the end it goes faster

public:
	/*
	Constructor
	*/
	cDlist()
	{
		start = end = NULL;
	}
	/*
	Destructor
	*/
	~cDlist()
	{

	}

	/*
	Methods
	*/
	void Add(const TYPE& newValue)
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
	}
	/*
	other utils
	*/
	//poner aqui antes del examen
};

#endif // !_DLIST_H_
