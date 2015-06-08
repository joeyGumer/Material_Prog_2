#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include "Dlist.h"
#include "Stack.h"
#include "Qeue.h"

template <class TYPE>
class tNode
{
public:
	TYPE data;
	tNode* father;
	Dlist<tNode*> sons;

public:
	//Constructors
	tNode(const TYPE& newValue)
	{
		data = newValue;
		father = NULL;
	}

	tNode<TYPE>* FindRecursive(const TYPE& node)
	{
		if (node == data)
			return this;

		tNode<TYPE>* ret = NULL;
		Node<tNode<TYPE>*>* tmp = sons.start;
		while (tmp != NULL)
		{
			tNode<TYPE>* son = tmp->value;
			ret = son->FindRecursive(node);

			if (ret != NULL)
				break;

			tmp = tmp->next;
		}

		return ret;
	}

	/*
	Recursive order functions
	*/
	void PreOrderRecursive(Dlist<tNode<TYPE>*>* list)
	{
		list->Add(this);
		Node<tNode<TYPE>*>* node = sons.start;


		while (node != NULL)
		{
			node->value->PreOrderRecursive(list);
			node = node->next;
		}
	}

	void PostOrderRecursive(Dlist<tNode<TYPE>*>* list)
	{

		Node<tNode<TYPE>*>* node = sons.start;

		while (node != NULL)
		{
			node->value->PostOrderRecursive(list);
			node = node->next;
		}
		list->Add(this);
	}

	void InOrderRecursive(Dlist<tNode<TYPE>*>* list)
	{
		Node<tNode<TYPE>*>* node = sons.start;
		unsigned int counter = 0;

		while (node != NULL && counter != sons.GetCapacity() / 2)
		{
			node->value->InOrderRecursive(list);
			node = node->next;
			counter++;
		}
		list->Add(this);
		while (node != NULL)
		{
			node->value->InOrderRecursive(list);
			node = node->next;
		}
	}
	/*
	Utils
	*/
	bool RemoveChild(tNode* node)
	{
		if (node)
		{
			Node<tNode*>* tmp = sons.start;
			for (; tmp != NULL; tmp = tmp->next)
			{
				tNode* child = tmp->value;
				if (node == child)
				{
					sons.Delete(tmp);
					node->father = NULL;
					return true;
				}
			}
		}
		return false;
	}

	void GatherAll(Dlist<tNode*>* list)
	{
		list->Add(this);

		Node<tNode*>* tmp = sons.start;

		for (; tmp != NULL; tmp = tmp->next)
		{
			tNode* child = tmp->value;
			child->GatherAll(list);
		}
	}

};

template <class TYPE>
class Tree
{
public:
	tNode<TYPE>* rootNode;

public:
	Tree(const TYPE& value)
	{
		rootNode = new tNode<TYPE>(value);
	}

	~Tree()
	{

	}

	/*
	Add
	*/
	tNode<TYPE>* Add(const TYPE& newData)
	{
		tNode<TYPE>* newNode = new tNode<TYPE>(newData);

		rootNode->sons.Add(newNode);
		newNode->father = rootNode;

		return newNode;
	}

	tNode<TYPE>* Add(const TYPE& newData, const TYPE& dad)
	{
		tNode<TYPE>* parent = rootNode->FindRecursive(dad);
		tNode<TYPE>* newNode = new tNode<TYPE>(newData);

		parent->sons.Add(newNode);
		newNode->father = parent;

		return newNode;
	}

	/*
	Recursive order functions
	*/
	void PreOrderRecursive(Dlist<tNode<TYPE>*>* list) const
	{
		rootNode->PreOrderRecursive(list);
	}

	void PostOrderRecursive(Dlist<tNode<TYPE>*>* list) const
	{
		rootNode->PostOrderRecursive(list);
	}

	void InOrderRecursive(Dlist<tNode<TYPE>*>* list) const
	{
		rootNode->InOrderRecursive(list);
	}

	/*
	Iterative order functions
	*/
	void PreOrderIterative(Dlist<tNode<TYPE>*>* list) const
	{
		Stack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		while (node != NULL)
		{
			list->Add(node);

			tmp = node->sons.end;

			while (tmp != node->sons.start)
			{
				stack.Push(tmp->value);
				tmp = tmp->prev;
			}

			if (tmp != NULL)
				node = tmp->value;
			
			else
			{
				node = NULL;
				stack.Pop(node);
			}
		}
	}

	void PostOrderIterative(Dlist<tNode<TYPE>*>* list) const
	{
		Stack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		stack.Push(node);
		while (stack.Pop(node))
		{
			if (node->sons.start == NULL || list->Find(node->sons.end->value))
				list->Add(node);
			
			else
			{
				stack.Push(node);
				tmp = node->sons.end;

				for (; tmp != NULL; tmp = tmp->prev)
					stack.Push(tmp->value);
			}
		}
	}
	

	void InOrderIterative(Dlist<tNode<TYPE>*>* list) const
	{
		Stack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;
		int counter = 0;

		stack.Push(node);
		while (stack.Pop(node))
		{
			if (node->sons.start == NULL || list->Find(node->sons.start->value))
				list->Add(node);

			else
			{
				tmp = node->sons.end;
				counter = node->sons.GetCapacity();

				for (; counter > node->sons.GetCapacity() / 2; tmp = tmp->prev, counter--)
					stack.Push(tmp->value);

				stack.Push(node);
				
				for (; tmp != NULL; tmp = tmp->prev)
					stack.Push(tmp->value);

				if (node->sons.GetCapacity() == 1)
				{
					stack.Pop(node);
					list->Add(node);
				}
			}
		}
	}

	void TransversalOrder(Dlist<tNode<TYPE>*>* list)
	{
		Qeue<tNode<TYPE>*> qeue;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		qeue.Push(node);
		while (qeue.Pop(node))
		{
			list->Add(node);

			if (node->sons.start != NULL)
			{
				tmp = node->sons.start;
				for (; tmp != NULL; tmp = tmp->next)
					qeue.Push(tmp->value);
			}
		}
	}
	/*
	Clear
	*/
	bool Clear(const TYPE& node)
	{
		tNode<TYPE>* delNode = rootNode->FindRecursive(node);
		Node<tNode<TYPE>*>* tmp;
		Node<tNode<TYPE>*>* tmp2;
		unsigned int counter = 0;

		if (delNode == NULL)
		{
			return false;
		}
		
		else
		{
			tmp = delNode->sons.start;

			if (tmp != NULL)
			{
				while (counter < delNode->sons.GetCapacity())
				{
					tmp2 = tmp;
					Clear(tmp->value->data);
					tmp = tmp2->next;

					counter++;
				}
			}

			if (delNode != rootNode)
			{
				tmp = delNode->father->sons.start;
				delNode->father->sons.Delete(tmp);
			}
			else
				rootNode = NULL;
		}
		return true;
	}

	/*void Clear()
	{
		Dlist<tNode<TYPE>*> list;
		
		rootNode->GatherAll(&list);

		Node<tNode<TYPE>*>* tmp = list.start;
		for (; tmp != NULL; tmp = tmp->next)
		{
			tNode<TYPE>* child = tmp->value;
			if (child->father)
				child->father->RemoveChild(child);
		}
		delete[] rootNode;
	}*/
};

#endif _TREE_H_<