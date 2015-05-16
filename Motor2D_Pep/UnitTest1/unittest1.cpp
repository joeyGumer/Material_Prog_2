#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Motor2D_Pep\Dlist.h"
#include "..\Motor2D_Pep\String.h"
#include "..\Motor2D_Pep\DynArray.h"
#include "..\Motor2D_Pep\Projectile.h"
#include "..\Motor2D_Pep\Tree.h"
#include "..\Motor2D_Pep\Stack.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		/*
		//Unit test after the examen
		*/

		// TREE -------------------------------------------
		TEST_METHOD(TreeAdd)
		{
			Tree<int> tree(1);

			Assert::AreEqual((int)tree.rootNode->data, 1);

			tree.Add(2);
			tree.Add(3);

			Assert::AreEqual((int)tree.rootNode->sons.start->value->data, 2);
			Assert::AreEqual((int)tree.rootNode->sons.end->value->data, 3);

			tree.Add(4, 2);
			tree.Add(5, 2);

			Assert::AreEqual((int)tree.rootNode->sons.start->value->sons.start->value->data, 4);
			Assert::AreEqual((int)tree.rootNode->sons.start->value->sons.end->value->data, 5);
		}

		TEST_METHOD(TreePreOrder)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			Dlist<tNode<char>*> list;
			tree.PreOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}


		TEST_METHOD(TreePostOrder)
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

			Dlist<tNode<char>*> list;
			tree.PostOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder)
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

			Dlist<tNode<char>*> list;
			tree.InOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');

			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(TreePreOrderIterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			Dlist<tNode<char>*> list;

			tree.PreOrderIterative(&list);

			Assert::AreEqual((int)list.GetCapacity(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(TreePostOrderIterative)
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

			Dlist<tNode<char>*> list;
			tree.PostOrderIterative(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrderIterative)
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

			Dlist<tNode<char>*> list;
			tree.InOrderIterative(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Clear)
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

			tree.Clear('B');


			Dlist<tNode<char>*> list;

			tree.PreOrderIterative(&list);

			Assert::IsTrue(list.GetCapacity() == 4);
			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'G');
			Assert::AreEqual((char)list[2]->data, 'I');
			Assert::AreEqual((char)list[3]->data, 'H');


		}

		//STACK------------------------------------------------
		TEST_METHOD(Stack_test)
		{
			Stack<int> lifo;

			lifo.Push(10);
			lifo.Push(20);
			lifo.Push(30);
			lifo.Push(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.Peek(1)), 20);

			int result;
			bool r = lifo.Pop(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}
		/*
		//QEUE-------------------------------------------------
		TEST_METHOD(Qeue_test)
		{
			Qeue<int> fifo;


			fifo.Push(11);
			fifo.Push(22);
			fifo.Push(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)*(fifo.Peek(1)), 22);


			int result;
			bool r = fifo.Pop(result);
			
			//
			//Assert::AreEqual((int)result, 33);
			//Assert::AreEqual((int)fifo.Count(), 2);
			//
		}*/

		/*
		Unit Test that are exercises from examn
		*/
		// Projectile ----------------------------------------
		TEST_METHOD(Projectile_test)
		{
			Projectile p;
			p.point.x = 10.0f;
			p.point.y = 10.0f;
			p.speed.x = 2.0f;
			p.speed.y = 0.0f;
			Point2D<float> current = p.GetCurrentPosition(3.0f);
			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}
		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynArray<int> array(10);
			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((unsigned int)10, array.GetCapacity());
			unsigned int wasted = array.removeWastedMemory();
			Assert::AreEqual((unsigned int)3, array.GetCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_mid)
		{
			Dlist<int> l;
			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);
			l.delNodes(1, 2);
			Assert::AreEqual((int)1, l.start->value);
			Assert::AreEqual((int)4, l.end->value);
			Assert::AreEqual((unsigned int)2, l.GetCapacity());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_begin)
		{
			Dlist<int> l;
			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);
			l.delNodes(0, 3);
			Assert::AreEqual((int)4, l.start->value);
			Assert::AreEqual((int)4, l.end->value);
			Assert::AreEqual((unsigned int)1, l.GetCapacity());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_end)
		{
			Dlist<int> l;
			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);
			l.delNodes(2, 100);
			Assert::AreEqual((int)1, l.start->value);
			Assert::AreEqual((int)2, l.end->value);
			Assert::AreEqual((unsigned int)2, l.GetCapacity());
		}
		// String prefix ----------------------------------------
		/*TEST_METHOD(String_prefix)
		{
			cString a("1234567890");
			cString b(50);
			b = "hola";
			a.Prefix(b);
			b.Prefix("1234567890");
			Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
		}*/
		
		/*
		Unit test previous to the examen
		*/
		// DYN ARRAY -----------------------------------------
		TEST_METHOD(DynArray_CombSort)
		{
			DynArray<int> array;
			array.PushBack(5);
			array.PushBack(4);
			array.PushBack(10);
			array.PushBack(8);
			array.PushBack(3);

			Assert::AreEqual((int)array.Count(), 5);

			array.CombSort();

			Assert::AreEqual(array[0], 3);
			Assert::AreEqual(array[1], 4);
			Assert::AreEqual(array[2], 5);
			Assert::AreEqual(array[3], 8);
			Assert::AreEqual(array[4], 10);
		}

		TEST_METHOD(DynArray_CocktailSort)
		{
			DynArray<int> array;
			array.PushBack(5);
			array.PushBack(4);
			array.PushBack(10);
			array.PushBack(8);
			array.PushBack(3);

			Assert::AreEqual((int)array.Count(), 5);

			array.CocktailSort();

			Assert::AreEqual(array[0], 3);
			Assert::AreEqual(array[1], 4);
			Assert::AreEqual(array[2], 5);
			Assert::AreEqual(array[3], 8);
			Assert::AreEqual(array[4], 10);
		}

		TEST_METHOD(DynArray_Bubble)
		{
			DynArray<int> array;
			array.PushBack(5);
			array.PushBack(4);
			array.PushBack(10);
			array.PushBack(8);
			array.PushBack(3);

			Assert::AreEqual((int)array.Count(), 5);

			array.BubbleSort();

			Assert::AreEqual(array[0], 3);
			Assert::AreEqual(array[1], 4);
			Assert::AreEqual(array[2], 5);
			Assert::AreEqual(array[3], 8);
			Assert::AreEqual(array[4], 10);
		}

		TEST_METHOD(DynArray_ctor)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			int a, b;

			Assert::IsTrue(array.Pop(a));
			Assert::IsTrue(array.Pop(b));

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 1);
			Assert::AreEqual(a, 3);
			Assert::AreEqual(b, 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> array;

			for (int i = 0; i < DYN_ARRAY_BLOCK_SIZE; ++i)
			{
				array.PushBack(i);
			}

			array.Insert(999, 3);
			array.Insert(888, 17);
			array.Insert(777, 50);

			Assert::IsFalse(array.Insert(777, 50));
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE * 2);
			Assert::AreEqual((int)array.Count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}
		
		// p2SString -----------------------------------------
		TEST_METHOD(SString_Substiture)
		{
			cString s("Hola mundo");
			Assert::AreEqual((int)s.Length(), 10);

			s.Substitute("Hola","Pepito");

			Assert::AreEqual(s.GetString(), "Pepito mundo");

			s.Substitute("Pepito", "PC");
			
			Assert::AreEqual(s.GetString(), "PC mundo");
		}

		TEST_METHOD(SString_Trim)
		{
			cString s("  Hola  ");
			Assert::AreEqual((int)s.Length(), 8);

			s.Trim();

			Assert::AreEqual((int)s.Length(), 4);

			Assert::AreEqual(s.GetString(), "Hola");
		}

		TEST_METHOD(SString_empty_ctor)
		{
			cString s;
			Assert::AreEqual((int)s.Length(), 0);
		}
		TEST_METHOD(SString_char_ctor)
		{
			cString s("Hola mundo");
			Assert::AreEqual((int)s.Length(), 10);
		}
		TEST_METHOD(SString_format_ctor)
		{
			cString s("%s %s %d", "hola", "mundo", 12);
			Assert::AreEqual((int)s.Length(), 13);
		}
		TEST_METHOD(SString_copy_ctor)
		{
			cString s("%s %s %d", "hola", "mundo", 12);
			cString s2(s);
			Assert::AreEqual((int)s2.Length(), 13);
		}
		TEST_METHOD(SString_op_equal)
		{
			cString s1("Hola mundo");
			cString s2("Hola mundo");
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(SString_op_notequal)
		{
			cString s1("Hola mundo 1");
			cString s2("Hola mundo 2");
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(SString_op_equal_cstr)
		{
			cString s1("Hola mundo");
			Assert::IsTrue(s1 == "Hola mundo");
		}
		TEST_METHOD(SString_op_notequal_cstr)
		{
			cString s1("Hola mundo 1");
			Assert::IsTrue(s1 != "Test");
		}
		TEST_METHOD(SString_op_assign)
		{
			cString s1("Hola mundo");
			cString s2;
			s2 = s1;
			Assert::IsTrue(s2 == "Hola mundo");
		}
		TEST_METHOD(SString_op_assign_cstr)
		{
			cString s1("Hola mundo");
			s1 = "this is a test";
			Assert::IsTrue(s1 == "this is a test");
		}
		TEST_METHOD(SString_op_concat)
		{
			cString s1("Hola mundo");
			cString s2("this is a test");
			s1 += s2;
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_op_concat_cstr)
		{
			cString s1("Hola mundo");
			s1 += "this is a test";
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_length)
		{
			cString s1("Hola mundo");
			Assert::AreEqual((int)s1.Length(), 10);
		}
		TEST_METHOD(SString_capacity)
		{
			cString s1("Hola mundo");
			Assert::AreEqual((int)s1.GetCapacity(), 11);
		}
		TEST_METHOD(SString_getstr)
		{
			cString s1("Hola mundo");
			Assert::AreEqual((int)strcmp("Hola mundo", s1.GetString()), 0);
		}
		TEST_METHOD(SString_clear)
		{
			cString s1("Hola mundo");
			s1.Clear();
			Assert::AreEqual((int)s1.Length(), 0);
		}

		// p2List --------------------------------------------
		TEST_METHOD(ListAdd)
		{
			Dlist<int> mylist;
			Assert::AreEqual((int)mylist.Add(5), 1);
		}

		TEST_METHOD(ListDel)
		{
			Dlist<int> mylist;
			mylist.Add(5);
			Assert::IsTrue(mylist.Delete(mylist.start));
			Assert::AreEqual((int)mylist.GetCapacity(), 0);
		}

		TEST_METHOD(ListClear)
		{
			Dlist<int> mylist;
			mylist.Add(1); mylist.Add(2); mylist.Add(3);
			mylist.Clear();
			Assert::AreEqual((int)mylist.GetCapacity(), 0);
		}
	};
}
