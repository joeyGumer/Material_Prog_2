#ifndef _SWAP_H_
#define _SWAP_H_

template<class TYPE>
void Swap(TYPE& a, TYPE& b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}
#endif _SWAP_H_