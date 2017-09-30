#include "stdafx.h"
#include "CppUnitTest.h"

/*
 * Documentation
 * https://blogs.msdn.microsoft.com/vcblog/2017/04/19/cpp-testing-in-visual-studio/
 */

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessPlayerTest
{		
	TEST_CLASS(ChessGame)
	{
	public:
		
        TEST_METHOD(Test1)
        {
            // TODO: Your test code here
            Assert::AreEqual(1, 1);
        }

		TEST_METHOD(Test2)
		{
			// TODO: Your test code here
            Assert::AreNotEqual(1, 2);
		}

	};
}