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

int FibonacciIterative(const unsigned int index)
{
	int prev = 0;
	int next = 1;

	for (int i = 0; i < index; i++)
	{
		next += prev;
		prev = next - prev;
	}

	return next;
}

void main(int argc, char** argv)
{

}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}


