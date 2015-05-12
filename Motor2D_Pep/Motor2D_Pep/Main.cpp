#include "Point2D.h"
#include "String.h"
#include "Dlist.h"
#include "DynArray.h"
#include "Log.h"


int main(int argc, char** argv)
{
	DynArray<int> array1, array2, array3;
	int r;
	for (int i = 0; i < 10000; i++)
	{
		r = rand() % 10;
		array1.PushBack(r);
		array2.PushBack(r);
		array3.PushBack(r);
	}
	LOG("se ha itinerado: %d veces ", array2.BubbleSort());
	LOG("se ha itinerado: %d veces ", array1.BubbleSortOptimized());
	LOG("se ha itinerado: %d veces ", array3.CocktailSort());

	for (int j = 0; j < 10000; j++)
	{
		if (array1[j] != array3[j])
			LOG("No se ha ordenado correctamente");
	}
	
	return array1.BubbleSort();
}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}

