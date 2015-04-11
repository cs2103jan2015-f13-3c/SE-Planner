#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicAddUnitTest
{		
	TEST_CLASS(LogicAddUnitTestClass)
	{
	public:
		
		

		TEST_METHOD(LogicAddFloat)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;

			vector<Task> allTask = storage.getAllTask();

			Task addTask;
			addTask.taskType = FLOATTASK;
			addTask.title = "a new thing";

			allTask = logic.Add(allTask,addTask);

			Assert::IsTrue(allTask[allTask.size()-1].title == "a new thing");
		}


		TEST_METHOD(LogicAddDeadline)
		{	
			
		}

		TEST_METHOD(LogicAddTimedTask)
		{	
		}

		TEST_METHOD(LogicAddInvalid)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task addTask;
			addTask.taskType = NUL;
			addTask.title = "a new thing";

			allTask = logic.Add(allTask,addTask);

			Assert::IsTrue(allTask.size() == previousSize);
		}

		
	};
}