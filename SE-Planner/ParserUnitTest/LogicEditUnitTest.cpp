#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicEditUnitTest
{		
	TEST_CLASS(LogicEditUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicEditFloatTitle)
		{	
		}

		TEST_METHOD(LogicEditDeadlineDate)
		{	
		}

		TEST_METHOD(LogicEditDeadlineTime)
		{	
		}

		TEST_METHOD(LogicEditTimedTask)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display all");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			
			vector<Task> displayTask;
			Task nulTask = Task();
			displayTask = logic.Display(allTask, nulTask, actualCommand.instruction);

			
			parser = Parser("edit 1 new timed task date: 12/4 time: 11-20");
			actualCommand = parser.getCommand();
			Task editTask = parser.getTask();
			vector<Task> newTask = logic.Edit(allTask,displayTask,actualCommand.idx[0],editTask);

			Assert::IsTrue(newTask[3].title == "new timed task");
		}

		TEST_METHOD(LogicEditInvalid)
		{	
		}
	};
}