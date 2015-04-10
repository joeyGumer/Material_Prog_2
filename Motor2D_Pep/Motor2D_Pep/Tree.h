#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include "Dlist.h"

template <class TYPE>
struct tNode
{
	TYPE data;
	tNode* father;//el node previ, el pare
	cDlist<tNode*> sons;//els nodes segueents, ramificacions, els fills

	tNode(TYPE& newValue) : data(newValue), father(NULL), son(NULL){};
	tNode(TYPE& newValue, tNode* dad) : data(newValue), father(dad), son(NULL){};
};

template <class TYPE>
class Tree
{
	/*
	//Atributes
	*/
public:
	tNode* rootNode;

	/*
	//Methods
	*/
	
	//Constructor and Destructor
	Tree()
	{
		rootNode = NULL;
	}

	~Tree()
	{

	}

	//Add
	void Add(TYPE& newData)
	{
		tNode<TYPE>* newNode = new tNode(newData);
		rootNode->sons->Add(newNode);
		newNode->father = rootNode;
	}

	void Add(TYPE& newData, tNode<TYPE>* newNode)
	{
		tNode<TYPE>* newNode = new tNode(newData);
		if (rootNode == NULL)
			rootNode = newNode;
		else
		{
			rootNode->sons
		}
	}

};





#endif _TREE_H_