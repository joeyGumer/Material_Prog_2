#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#include <assert.h>
#include <stdlib.h>
#include "Swap.h"

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class DynArray
{

private:

	TYPE* data;
	unsigned int allocMemory;
	unsigned int numElements;

public:

	//Constructors
	DynArray() : data(NULL), allocMemory(0), numElements(0)
	{ 
		Reallocate(DYN_ARRAY_BLOCK_SIZE);
	}
	DynArray(const unsigned int memSize) : data(NULL), allocMemory(0), numElements(0)
	{ 
		Reallocate(memSize); 
	}

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

		allocMemory = newSize;
		data = new TYPE[newSize];
		if (newSize < numElements)
		{
			numElements = newSize;
		}

		for (unsigned int i = 0; i < numElements; i++)
		{
			data[i] = tmp[i];
		}
		
	};

	//Puts an element at the end of the array
	void PushBack(const TYPE newElement)
	{
		if (numElements + 1 > allocMemory)
		{
			Reallocate(allocMemory + DYN_ARRAY_BLOCK_SIZE);
		}
		data[numElements] = newElement;
		numElements++;
	}

	//Puts out the last element
	bool Pop(TYPE& value)
	{
		if (numElements != 0)
		{
			value = data[--numElements];
			return true;
		}
		return false;
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

		if (numElements + 1 > allocMemory) 
		{ 
			Reallocate(allocMemory + DYN_ARRAY_BLOCK_SIZE);
		}
		
		for (unsigned int i = numElements; i > position; i--)
		{
			data[i] = data[i--];
		}

		data[position] = newElement;
		numElements++;

		return true;
	}

	//other util methods
	unsigned int GetCapacity() const
	{ 
		return allocMemory; 
	}
	
	unsigned int Count() const
	{ 
		return numElements; 
	}
	
	void Clear() 
	{ 
		numElements = 0; 
	}

	/*
	Method for the exercise 2
	*/
	unsigned int removeWastedMemory()
	{
		unsigned int wasted = allocMemory - numElements;
		allocMemory = allocMemory - wasted;
		Reallocate(allocMemory);

		return wasted;
	}

	//Sort Algorithms
	unsigned int BubbleSort()//the most simple
	{
		unsigned int counter = 0;
		bool change = true;
		//for the optimization

		while (change == true)
		{
			change = false;
			for (int i = 0; i < numElements - 1; i++)
			{
				counter++;
				if (data[i]>data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					change = true;
				}
			}
		}
		return counter;
	}

	unsigned int BubbleSortOptimized()//the previous but optimized, cause the last elements dosen't get count on each itineration
	{
		unsigned int counter = 0;
		bool change = true;
		int peeks = numElements - 1;//for the optimization

		while (change == true)
		{
			change = false;
			for (int i = 0; i < peeks; i++)
			{
				counter++;
				if (data[i]>data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					change = true;
				}
			}
			peeks--;
		}
		return counter;
	}

	unsigned int CocktailSort()
	{
		unsigned int counter = 0;
		bool change = true;
		int right = 0;
		int left = numElements - 1;

		while (change == true && left > right)
		{
			change = false;
			for (int i = right; i < left; i++)
			{
				counter++;
				if (data[i] > data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					change = true;
				}
			}
			left--;

			for (int j = left; j > right; j--)
			{
				counter++;
				if (data[j] < data[j - 1])
				{
					Swap(data[j], data[j - 1]);
					change = true;
				}
			}
			right++;
		}
		return counter;
	}

	unsigned int CombSort()
	{

		bool change = true;
		int gap = numElements - 1;
		unsigned int counter = 0;

		while (gap > 1 || change == true)
		{
			gap /= 1.3;

			if (gap < 1)
				gap = 1;
			
			change = false;
			for (int i = 0; i + gap < numElements; i++)
			{
				counter++;
				if (data[i]>data[i + gap])
				{
					Swap(data[i], data[i + gap]);
					change = true;
				}
			}
		}
		return counter;
	}

};

#endif // !_DYNAMIC_ARRAY_H_