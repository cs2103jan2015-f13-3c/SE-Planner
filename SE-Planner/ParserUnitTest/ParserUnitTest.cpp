#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserUnitTest
{		
	TEST_CLASS(ParserUnitTestClass)
	{
	public:
		
		TEST_METHOD(SimpleAddTest)
		{
			// TODO: Your test code here
			Parser parser = Parser("add a simple task");
			Utility utility;

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = FLOATTASK;
			parserExpected.title = "a simple task";

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));
			Assert::IsTrue(parser.getCommand().cmd == ADD);
			
		}

		TEST_METHOD(SimpleAddDeadline)
		{
			// TODO: Your test code here
			Parser parser = Parser("add test deadline date: 9/4");
			Utility utility;

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

	};
}