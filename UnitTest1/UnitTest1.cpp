#include "pch.h"
#include "CppUnitTest.h"
#include "../FileName.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int n = 7;
			int a[n] = { 2, 1, 3, 4, 3, 1, 4 };
			int expectedSortedArray[n] = { 2, 3, 3, 4, 1, 1,4 };
			Sort(a, n, 0);
			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(a[i], expectedSortedArray[i]);
			}
		}
	};
}
