#include "Point2D.h"
#include "String.h"
#include "Dlist.h"
#include "DynArray.h"
#include "Log.h"
#include <assert.h>


void main(int argc, char** argv)
{
	cString s("Hola mundo");
	

	s.Substitute("Hola", "Pepito");
	LOG("%s", s);
	s.Substitute("Pepito", "PC");
	LOG("%s", s);

	/*DynArray<int> array1, array2, array3, array4;
	int r;
	for (int i = 0; i < 10000; i++)
	{
		r = rand() % 10;
		array1.PushBack(r);
		array2.PushBack(r);
		array3.PushBack(r);
		array4.PushBack(r);
	}
	LOG("se ha iterado: %d veces ", array2.BubbleSort());
	LOG("se ha iterado: %d veces ", array1.BubbleSortOptimized());
	LOG("se ha iterado: %d veces ", array3.CocktailSort());
	LOG("se ha iterado: %d veces ", array4.CombSort());

	for (int j = 0; j < 10000; j++)
	{
		if (array1[j] != array4[j])
			LOG("No se ha ordenado correctamente");
	}
	
	return array1.BubbleSort();*/
}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}

