#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include "Dlist.h"
#include "Stack.h"
#include "Queue.h"

template <class TYPE>
class tNode
{
	TYPE data;
	tNode* father;//el node previ, el pare
	cDlist<tNode*> sons;//els nodes segueents, ramificacions, els fills

	//Constructors
	
	tNode(TYPE& newValue) : data(newValue), father(NULL){};

	bool AddChild(tNode* node)
	{
		if (node != NULL)
		{
			sons.Add(node);
			node->parent = this;

			return true;
		}
		return false;
	}

	//Functions that gets all the nodes (recursive)
	//fer apunts dels diferents tipus d'ordentacio perque no m'he enterat a casa
	//amb l'arbre fet a clase  la preOrder dona: F,B,A,D,C,E,G,I,H (per montarla)
	//fer les mateixers funcions per iteratives (s'ha d'utilitzar una pila)


	void PreOrderRecursive(cDlist<TYPE>* list)
	{
		list.Add(data);
		Node<tNode*>* item = sons.start;
		

		while (item != NULL)
		{
			tNode->PreOrderRecursive(list);
			item = item->next;
		}
	}

	void PostOrderRecursive(cDlist<TYPE>* list)
	{
		
		Node<tNode*>* item = sons.start;

		while (item != NULL)
		{
			tNode->PostOrderRecursive(list);
			item = item->next;
		}
		list.Add(data);
	}

	void InOrderRecursive(cDlist<TYPE>* list)
	{
		Node<tNode*>* item = sons.start;
		unsigned int counter = 0;

		while (item != NULL && counter != sons.GetCapacity()/2)
		{
			tNode->InOrderRecursive(list);
			item = item->next;
			counter++;
		}
		
		list.Add(data);
		
		while (item != NULL)
		{
			tNode->PostOrderRecursive(list);
			item = item->next;
		}
	}
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
	Tree(const TYPE& value )
	{
		rootNode->data = value;
	}

	~Tree()
	{

	}

	//Add
	tNode<TYPE>* Add(TYPE& newData)
	{
		tNode<TYPE>* newNode = new tNode(newData);
		rootNode->sons->Add(newNode);
		newNode->father = rootNode;
		return newNode;
	}

	tNode<TYPE>* Add(TYPE& newData, tNode<TYPE>* dad)
	{
		tNode<TYPE>* newNode = new tNode(newData);
		dad->sons->Add(newNode);
		newNode->father = dad;
		return newNode;
	}

	//Function that returns all the nodes (recursive)
	void PreOrderRecursive(cDlist<TYPE>* list) const
	{
		root.PreOrderRecursive(list);
	}

	void PostOrderRecursive(cDlist<TYPE>* list) const
	{
		root.PostOrderRecursive(list);
	}

	void InOrderRecursive(cDlist<TYPE>* list) const
	{
		root.InOrderRecursive(list) const;
	}

	//Function that returns all the nodes (iterative)
	void PreOrderIterative(cDlist<TYPE>* list) const
	{
		cStack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = &rootNode;

		while (node != NULL || stack.Pop(node))
		{
			list.Add(node);

			Node<tNode<TYPE>*>* tmp = node->sons.end;

			while (tmp != node->sons.start)
			{
				stack.Push(tmp->value);
				tmp = tmp->prev;
			}

			if (tmp != NULL)
				node = tmp->value;
			else
				node = NULL;
		}
	}

	/*void PostOrderIterative(cDlist<TYPE>* list) const
	{
		cStack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = &rootNode;

		while ()
		{
			stack.Push(node);

			Node<tNode<TYPE>*>* tmp = node->sons.end;

			if (tmp != NULL)
			{
				node = tmp->value;
			}
			else
			{
				node = node
			}
		}

	}*/




};





#endif _TREE_H_