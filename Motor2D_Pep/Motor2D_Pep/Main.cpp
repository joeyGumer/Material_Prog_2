#include "Point2D.h"
#include "String.h"
#include "Dlist.h"
#include "DynArray.h"
#include "Log.h"
#include "Tree.h"


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
	Tree<char> tree('F');

	tree.Add('B', 'F');
	tree.Add('G', 'F');
	tree.Add('A', 'B');
	tree.Add('D', 'B');
	tree.Add('C', 'D');
	tree.Add('E', 'D');
	tree.Add('I', 'G');
	tree.Add('H', 'I');
	
	tree.Clear('F');

	Dlist<tNode<char>*> list;
	tree.PreOrderIterative(&list);
}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}


