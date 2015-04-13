#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicEditUnitTest
{		
	TEST_CLASS(LogicEditUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicEditTimedTask)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display all");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			
			vector<Task> displayTask;
			Task nulTask = Task();
			displayTask = logic.display(allTask, nulTask, actualCommand.instruction);

			
			parser = Parser("edit 1 new timed task date: 12/4 time: 11-20");
			actualCommand = parser.getCommand();
			Task editTask = parser.getTask();
			vector<Task> newTask = logic.edit(allTask,displayTask,actualCommand.idx[0],editTask);

			Assert::IsTrue(newTask[3].title == "new timed task");
		}

		//@author A0108417J
		TEST_METHOD(isIndexValidTest) {
			Logic logic;

			//Test for valid index
			std::vector<Task> displayedTasks;
			Task floatTask;
			displayedTasks.push_back(floatTask);
			bool result = logic.isIndexValid(displayedTasks, 1);
			Assert::IsTrue(result);

			//Test for invalid index of 0 or lesser
			result = logic.isIndexValid(displayedTasks, 0);
			Assert::IsFalse(result);

			//Test for invalid index of greater than displayedTask.size()
			result = logic.isIndexValid(displayedTasks, 2);
			Assert::IsFalse(result);
		}

		//@author A0108417J
		TEST_METHOD(isTaskTypeValid) {
			Logic logic;

			//Test when edit is not allowed when toBeEditedTask is FLOATTASK and newTaskInfo is not FLOATTASK
			Task tobeEditedTask;
			tobeEditedTask.taskType = FLOATTASK;
			Task newTaskInfo;
			newTaskInfo.taskType = DEAD;
			bool result = logic.isTaskTypeValid(tobeEditedTask, newTaskInfo);
			Assert::IsFalse(result);

			//Test when edit is not allowed when toBeEditedTask is TIMED and newTaskInfo is DEAD
			tobeEditedTask.taskType = TIMED;
			result = logic.isTaskTypeValid(tobeEditedTask, newTaskInfo);
			Assert::IsFalse(result);

			//Test when edit is not allowed when toBeEditedTask is DEAD and newTaskInfo is TIMED
			tobeEditedTask.taskType = DEAD;
			newTaskInfo.taskType = TIMED;
			result = logic.isTaskTypeValid(tobeEditedTask, newTaskInfo);
			Assert::IsFalse(result);
		}

	};
}