#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#include <assert.h>
#include <stdlib.h>

template<class TYPE>
class DynArray
{

private:

	TYPE* data;
	unsigned int allocMemory;
	unsigned int numElements;

public:

	//Constructors
	DynArray(){ data = NULL; allocMemory = 0; numElements = 0; }
	DynArray(const unsigned int memSize){ numElements = 0; Reallocate(memSize); }

	//Destructors
	~DynArray(){ delete data; }

	//Operators
	TYPE& operator [](unsigned int index)
	{
		assert(index < numElements);
		return data[index];
	}
	const TYPE& operator [] (unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}

	//Methods

	//Changes the array size
	void Reallocate(const unsigned int newSize)
	{
		TYPE* tmp = data;

		if (newSize >= allocMemory)
		{
			allocMemory = newSize;
			data = new TYPE[newSize];
			for (int i = 0; i < numElements; i++)
			{
				data[i] = tmp[i];
			}
		}
		else
		{
			allocMemory = newSize;
			data = new TYPE[newSize];
			if (newSize < numElements)
			{
				numElements = newSize;
			}

			for (int i = 0; i < numElements; i++)
			{
				data[i] = tmp[i];
			}
		}
	};

	//Puts an element at the end of the array
	void PushBack(const TYPE newElement)
	{
		if (numElements + 1 > allocMemory)
		{
			Reallocate(allocMemory + 1);
		}
		data[numElements] = newElement;
		numElements++;
	}

	//Puts out the last element
	int Pop()
	{
		if (numElements != 0)
		{
			numElements--;
			return numElements;
		}
	}

	//Like the PushBack but you can put an element where you say
	bool Insert(const TYPE newElement, const unsigned int position)
	{
		if (position > allocMemory)
		{
			return false;
		}
		if (position == allocMemory)
		{
			PushBack(newElement);
			return true;
		}

		if (numElements + 1 > allocMemory) { Reallocate(allocMemory); }
		for (int i = numElements; i > position; i--)
		{
			data[i] = data[i--];
		}

		data[position] = newElement;
		numElements++;

		return true;
	}

	//other util methods
	int GetCapacity(){ return allocMemory; }
	int Counter(){ return numElements; }
	int Clear(){ numElements = 0; }
};

#endif // !_DYNAMIC_ARRAY_H_