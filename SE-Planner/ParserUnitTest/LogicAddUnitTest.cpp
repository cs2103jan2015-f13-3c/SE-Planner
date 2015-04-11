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
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Utility utility;

			Parser parser = Parser("add a new deadline date: 22/2");
			Task addTask = parser.getTask();
			vector<Task> allTask = storage.getAllTask();

			
			allTask = logic.Add(allTask,addTask);

			string expectedTitle = "a new deadline";
			Assert::AreEqual(allTask[allTask.size()-1].title,expectedTitle);
			Assert::IsTrue(utility.isEqual(allTask[allTask.size()-1].startDate,Date(22,2,2015)));
		}

		TEST_METHOD(LogicAddTimedTask)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Utility utility;

			Parser parser = Parser("add a random timed task date: 22/2 time: 10 - 15");
			Task addTask = parser.getTask();
			vector<Task> allTask = storage.getAllTask();

			allTask = logic.Add(allTask,addTask);

			Assert::IsTrue(allTask[allTask.size()-1].title == "a random timed task");
			Assert::IsTrue(utility.isEqual(allTask[allTask.size()-1].startDate,Date(22,2,2015)));
			Assert::IsTrue(utility.isEqual(allTask[allTask.size()-1].startTime,Time(10,0)));
			Assert::IsTrue(utility.isEqual(allTask[allTask.size()-1].endTime,Time(15,0)));
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