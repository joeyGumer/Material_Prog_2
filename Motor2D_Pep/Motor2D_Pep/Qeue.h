#ifndef _QEUE_H_
#define _QEUE_H_

template<class TYPE>
struct qNode
{
	TYPE value;
	qNode<TYPE>* next;
	qNode<TYPE>* prev;
	

	inline qNode<TYPE>(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}
};

template<class TYPE>
class Qeue
{

public:

	qNode<TYPE>* start;
	qNode<TYPE>* end;

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
		qNode<TYPE>* newNode;
		newNode = new qNode<TYPE>(newValue);

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
			qNode<TYPE>* tmp = end;

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
		qNode<TYPE>* tmp = start;
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
		qNode<TYPE>* tmp = start;
		qNode<TYPE>* tmp2;

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