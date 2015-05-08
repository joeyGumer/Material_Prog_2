#include "Point2D.h"
#include "String.h"
#include "Dlist.h"
#include "DynArray.h"


int main(int argc, char** argv)
{
	cString a("1234567890");
	cString b(50);
	b = "hola";
	a.Prefix(b);
	b.Prefix("1234567890");
	
	return (0);
}

//factorial (!4 = 24)
int Factorial(int a)
{
	return(a > 1) ? a = Factorial(a - 1) : 1;
}

