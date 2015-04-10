#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Motor2D_Pep\Dlist.h"
#include "..\Motor2D_Pep\String.h"
#include "..\Motor2D_Pep\DynArray.h"
#include "..\Motor2D_Pep\Projectile.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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
			cPoint2D<float> current = p.GetCurrentPosition(3.0f);
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
			cDlist<int> l;
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
			cDlist<int> l;
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
			cDlist<int> l;
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
		TEST_METHOD(String_prefix)
		{
			cString a("1234567890");
			cString b(50);
			b = "hola";
			a.Prefix(b);
			b.Prefix("1234567890");
			Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
		}



		
		
		
		
		
		
		/*
		Unit test previous to the examen
		*/
		// DYN ARRAY -----------------------------------------
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
			cDlist<int> mylist;
			Assert::AreEqual((int)mylist.Add(5), 1);
		}

		TEST_METHOD(ListDel)
		{
			cDlist<int> mylist;
			mylist.Add(5);
			Assert::IsTrue(mylist.Delete(mylist.start));
			Assert::AreEqual((int)mylist.GetCapacity(), 0);
		}

		TEST_METHOD(ListClear)
		{
			cDlist<int> mylist;
			mylist.Add(1); mylist.Add(2); mylist.Add(3);
			mylist.Clear();
			Assert::AreEqual((int)mylist.GetCapacity(), 0);
		}
	};
}
