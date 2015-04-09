#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserUnitTest
{		
	TEST_CLASS(ParserUnitTestClass)
	{
	public:
		
		Utility utility;

		TEST_METHOD(Parser_ParseAddFloatTask)
		{
			// TODO: Your test code here
			Parser parser = Parser("add a simple task");
			

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = FLOATTASK;
			parserExpected.title = "a simple task";

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));
			Assert::IsTrue(parser.getCommand().cmd == ADD);
			
		}

		TEST_METHOD(Parser_ParseAddDeadLineWithoutTime)
		{
			// TODO: Your test code here
			Parser parser = Parser("add test deadline date: 9/4");

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = DEAD;
			parserExpected.title = "test deadline";
			parserExpected.startDate = Date(9,4,2015);
			parserExpected.endDate = parserExpected.startDate;
			parserExpected.startTime = Time(23,59);
			parserExpected.endTime = parserExpected.startTime;

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));
			Assert::IsTrue(parser.getCommand().cmd == ADD);
			
		}

		TEST_METHOD(Parser_ParseAddDealineWithouDate)
		{
		}

		TEST_METHOD(Parser_ParseAddTimedTask)
		{
		}

		TEST_METHOD(Parser_Delete)
		{
		}

		TEST_METHOD(Parser_Done)
		{
		}

		TEST_METHOD(Parser_Search)
		{
		}

		TEST_METHOD(Parser_Display)
		{
		}

		TEST_METHOD(Parser_Edit)
		{
		}

		TEST_METHOD(Parser_Undo)
		{
		}

		TEST_METHOD(Parser_Undone)
		{
		}
	};
}