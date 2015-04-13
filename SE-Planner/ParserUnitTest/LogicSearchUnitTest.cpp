#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//@author A0116724J
namespace LogicSearchUnitTest
{		
	TEST_CLASS(LogicSearchUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicSearchInvalid)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			

			vector<Task> allTask = storage.getAllTask();
			Task nulTask = Task();
			
			vector<Task> matchTask;
			matchTask = logic.search(allTask,nulTask);

			Assert::AreEqual(0, (int)matchTask.size());
		}

		TEST_METHOD(LogicSearchTitleDateTime)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("search deadline date: 11/4 time: 11");
			Command actualCommand = parser.getCommand();
			Task searchTask = parser.getTask();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			
			vector<Task> matchTask;
			matchTask = logic.search(allTask,searchTask);

			Assert::AreEqual(1, (int)matchTask.size());
		}

		//@author A0108417J
		TEST_METHOD(isTaskValidTest) {
			Logic logic;

			//Test if isTaskValid will return false if taskType = NUL
			Task invalidTask;
			bool result = logic.isTaskValid(invalidTask);
			Assert::IsFalse(result);

			//Test if isTaskValid will return true if taskType != NUL
			Task validTask;
			validTask.taskType = FLOATTASK;
			result = logic.isTaskValid(validTask);
			Assert::IsTrue(result);
		}

		//@author A0108417J
		TEST_METHOD(isTaskMatchTest) {
			Logic logic;

			//Test if isTaskMatch will return true when all fields of tasks are same
			Task task;
			task.title = "Floating Task";
			Task matchingTask = task;
			bool result = logic.isTaskMatch(task, matchingTask);
			Assert::IsTrue(result);

			//Test if isTaskMatch will return false when all fields of tasks are same except title
			matchingTask.title = "Floating Task 2";
			result = logic.isTaskMatch(task, matchingTask);
			Assert::IsFalse(result);

			//Test if isTaskMatch will return false when all fields of tasks are same except date
			matchingTask = task;
			matchingTask.startDate.day = 1;
			result = logic.isTaskMatch(task, matchingTask);
			Assert::IsFalse(result);

			//Test if isTaskMatch will return false when all fields of tasks are same except time
			matchingTask = task;
			matchingTask.startTime.hour = 1;
			result = logic.isTaskMatch(task, matchingTask);
			Assert::IsFalse(result);
		}

		//@author A0108417J
		TEST_METHOD(findMatchedTaskTest) {
			Logic logic;

			//Test if findMatchedTaskTest will return the displayedTask.size() of 1
			//if matchingTask is the only task in allTasks
			Task floatingTask;
			floatingTask.title = "Floating Task";
			std::vector<Task> allTasks;
			allTasks.push_back(floatingTask);
			std::vector<Task> displayedTask = logic.findMatchedTasks(allTasks, floatingTask);
			Assert::AreEqual(1, (int)displayedTask.size());
			
			//Test if findMatchedTaskTest will return the displayedTask.size() of 1
			//if matchingTask is the one of the two tasks in allTasks
			Task dead;
			dead.title = "Dead";
			allTasks.push_back(dead);
			displayedTask = logic.findMatchedTasks(allTasks, floatingTask);
			Assert::AreEqual(1, (int)displayedTask.size());
		}

	};
}