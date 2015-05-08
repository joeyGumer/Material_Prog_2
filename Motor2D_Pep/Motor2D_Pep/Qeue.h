#ifndef _QEUE_H_
#define _QEUE_H_

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
class Qeue
{

public:

	Node<TYPE>* start;
	Node<TYPE>* end;

private:

	unsigned int size;

public:
	/*
	Constructor
	*/
	inline Qeue()
	{
		end = start = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~Qeue()
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

	bool Pop(TYPE& value)
	{
		if (end != NULL)
		{
			Node<TYPE>* tmp = end;

			end = tmp->prev;
			end->next = NULL;

			value = tmp->value;

			delete[] tmp;
			size--;
			
			return true;
		}
		return false;
	}

	const TYPE* Peek(const unsigned int index)const
	{
		Node<TYPE>* tmp = start;
		unsigned int counter = 0;

		while (counter != index && tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		if (tmp != NULL)
			return &(tmp->value);

		return NULL;
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
	unsigned int Count() const
	{
		return size;
	}
	
};

#endif // !_QUEUE_H_