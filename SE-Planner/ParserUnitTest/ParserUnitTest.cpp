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
			
		}

		TEST_METHOD(Parser_ParseAddDeadLineWithoutTime)
		{
			// TODO: Your test code here
			Parser parser = Parser("add test deadline date: 9");

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = DEAD;
			parserExpected.title = "test deadline";
			parserExpected.startDate = Date(9,4,2015);
			parserExpected.endDate = parserExpected.startDate;
			parserExpected.startTime = Time(23,59);
			parserExpected.endTime = parserExpected.startTime;

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));
			
		}

		TEST_METHOD(Parser_ParseAddDealineWithouDate)
		{
			Parser parser = Parser("add test deadline time: 1630");

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = DEAD;
			parserExpected.title = "test deadline";
			parserExpected.startDate = Date(11,4,2015);
			parserExpected.endDate = parserExpected.startDate;
			parserExpected.startTime = Time(16,30);
			parserExpected.endTime = parserExpected.startTime;

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));
		}

		TEST_METHOD(Parser_ParseAddTimedTask)
		{
			Parser parser = Parser("add test timed date: 10/4 - 10/4 time: 10-20");

			Task parserActual = parser.getTask();

			Task parserExpected = Task();
			parserExpected.taskType = TIMED;
			parserExpected.title = "test timed";
			parserExpected.startDate = Date(10,4,2015);
			parserExpected.endDate = parserExpected.startDate;
			parserExpected.startTime = Time(10,00);
			parserExpected.endTime = Time(20,00);

			Assert::IsTrue(utility.isSame(parserExpected,parserActual));

			parser = Parser("add special timed time: 10-20");

			parserActual = parser.getTask();

			parserExpected = Task();
			parserExpected.taskType = TIMED;
			parserExpected.title = "special timed";
			parserExpected.startTime = Time(10,00);
			parserExpected.endTime = Time(20,00);

			Assert::IsTrue(utility.isEqual(parserExpected.startTime,parserActual.startTime));
			Assert::IsTrue(utility.isEqual(parserExpected.endTime,parserActual.endTime));
			
		}

		TEST_METHOD(Parser_Delete)
		{
			Parser parser;
			Command actualCommand;

			parser = Parser("delete 1 2 3");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 3);
			Assert::IsTrue(actualCommand.cmd == DEL);

			parser = Parser("delete -1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 0);
			Assert::IsTrue(actualCommand.cmd == DEL);

			parser = Parser("delete 1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == DEL);
		}

		TEST_METHOD(Parser_Done)
		{
			Parser parser;
			Command actualCommand;

			parser = Parser("done 1 2 3");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 3);
			Assert::IsTrue(actualCommand.cmd == DONE);

			parser = Parser("done -1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 0);
			Assert::IsTrue(actualCommand.cmd == DONE);

			parser = Parser("done 1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == DONE);
		}

		TEST_METHOD(Parser_Search)
		{
			Parser parser;
			Command actualCommand;
			Task searchTask;

			parser = Parser("search oh hello");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == SEARCH);
			Assert::IsTrue(searchTask.taskType == FLOATTASK);
			Assert::IsTrue(searchTask.title == "oh hello");

			parser = Parser("search date: 11/4");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == SEARCH);
			Assert::IsTrue(searchTask.taskType == DEAD);
			Assert::IsTrue(searchTask.title == "");
			Assert::IsTrue(utility.isEqual(searchTask.startDate,Date(11,4,2015)));

			parser = Parser("search date: 11/4 - 13/4");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == SEARCH);
			Assert::IsTrue(searchTask.taskType == TIMED);
			Assert::IsTrue(searchTask.title == "");
			Assert::IsTrue(utility.isEqual(searchTask.startDate,Date(11,4,2015)));
			Assert::IsTrue(utility.isEqual(searchTask.endDate,Date(13,4,2015)));

			parser = Parser("search date: 13/4 - 11/4");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == INVALID);

			parser = Parser("search time: 13");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == SEARCH);
			Assert::IsTrue(searchTask.taskType == DEAD);
			Assert::IsTrue(searchTask.title == "");
			Assert::IsTrue(utility.isEqual(searchTask.startTime,Time(13,0)));

			parser = Parser("search time:13 - 15");
			actualCommand = parser.getCommand();
			searchTask = parser.getTask();
			Assert::IsTrue(actualCommand.cmd == SEARCH);
			Assert::IsTrue(searchTask.taskType == TIMED);
			Assert::IsTrue(searchTask.title == "");
			Assert::IsTrue(utility.isEqual(searchTask.startTime,Time(13,0)));
			Assert::IsTrue(utility.isEqual(searchTask.endTime,Time(15,0)));
		}

		TEST_METHOD(Parser_Display)
		{
			Parser parser;
			Command actualCommand;

			parser = Parser("display all");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == ALL);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display overdue");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == OVERDUE);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display undone");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == DISPLAYUNDONE);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display done");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == DISPLAYDONE);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display today");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == TODAY);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display tomorrow");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == TMR);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display 9/4");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.instruction == SHOWDATE);
			Assert::IsTrue(actualCommand.cmd == DISPLAY);

			parser = Parser("display -1/-1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.cmd == INVALID);
		}

		TEST_METHOD(Parser_Edit)
		{
			Parser parser;
			Command actualCommand;
			Task editTask;

			parser = Parser("edit 1 a new title");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == EDIT);
			Assert::IsTrue(editTask.taskType == FLOATTASK);
			Assert::IsTrue(editTask.title == "a new title");

			parser = Parser("edit 1 date: 11/4");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == EDIT);
			Assert::IsTrue(editTask.taskType == DEAD);
			Assert::IsTrue(editTask.title == "");
			Assert::IsTrue(utility.isEqual(editTask.startDate,Date(11,4,2015)));

			parser = Parser("edit 1 time: 12");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == EDIT);
			Assert::IsTrue(editTask.taskType == DEAD);
			Assert::IsTrue(editTask.title == "");
			Assert::IsTrue(utility.isEqual(editTask.startTime,Time(12,0)));
			
			parser = Parser("edit 1 time: 12 - 16");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == EDIT);
			Assert::IsTrue(editTask.taskType == TIMED);
			Assert::IsTrue(editTask.title == "");
			Time expectedTime = Time(12,0);
			Assert::IsTrue(utility.isEqual(editTask.startTime,expectedTime));
			expectedTime = Time(16,0);
			Assert::IsTrue(utility.isEqual(editTask.endTime,expectedTime));

			parser = Parser("edit 1 date: 15/4 - 17/4");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == EDIT);
			Assert::IsTrue(editTask.taskType == TIMED);
			Assert::IsTrue(editTask.title == "");
			Date expectedDate = Date(15,4,2015);
			Assert::IsTrue(utility.isEqual(editTask.startDate,expectedDate));
			expectedDate = Date(17,4,2015);
			Assert::IsTrue(utility.isEqual(editTask.endDate,expectedDate));

			parser = Parser("edit 1 date: 15/4 - 12/4");
			actualCommand = parser.getCommand();
			editTask = parser.getTask();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == INVALID);
		}

		TEST_METHOD(Parser_Undo)
		{
			Parser parser;
			Command actualCommand;

			parser = Parser("undo");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.cmd == UNDO);

			parser = Parser("undo dkasjdkajwe");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.cmd == UNDO);
		}

		TEST_METHOD(Parser_Undone)
		{
			Parser parser;
			Command actualCommand;

			parser = Parser("undone 1 2 3");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 3);
			Assert::IsTrue(actualCommand.cmd == UNDONE);

			parser = Parser("undone -1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 0);
			Assert::IsTrue(actualCommand.cmd == UNDONE);

			parser = Parser("undone 1");
			actualCommand = parser.getCommand();
			Assert::IsTrue(actualCommand.idx.size() == 1);
			Assert::IsTrue(actualCommand.cmd == UNDONE);
		}
	};
}