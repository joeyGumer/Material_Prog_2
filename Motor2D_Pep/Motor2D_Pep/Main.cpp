#include "Point2D.h"
#include "String.h"
#include "Dlist.h"
#include "DynArray.h"
#include "Log.h"


int Fibonacci(const unsigned int index)
{
	if (index > 1)
		return Fibonacci(index - 2) + Fibonacci(index - 1);
	
	else
		return 1;
}

void main(int argc, char** argv)
{
	Dlist<int> mylist;

	mylist.Add(5);
	mylist.Add(4);
	mylist.Add(10);
	mylist.Add(8);
	mylist.Add(3);

	mylist.BubbleSort();

}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}


