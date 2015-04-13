#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicDeleteUnitTest
{		
	TEST_CLASS(LogicDeleteUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicDeleteOneIndex)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("delete 1");
			Command actualCommand = parser.getCommand();

			Assert::IsTrue(actualCommand.cmd == DEL);
			Assert::IsTrue(actualCommand.idx.size() == 1);

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Assert::AreEqual(6,previousSize);
			Task nulTask = Task();

			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(6,(int)displayedTaskList.size());
			
			vector<Task> newTask;
			newTask = logic.Delete(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(5,(int)newTask.size());
			
		}

		TEST_METHOD(LogicDeleteMultipleIndex)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("delete 1 2");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();
			Task nulTask = Task();

			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			allTask = logic.Delete(allTask,displayedTaskList,actualCommand.idx);

			Assert::IsTrue(allTask.size() == previousSize - 2);
		}

		TEST_METHOD(LogicDeleteInvalidIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("delete 10000");
			Command actualCommand = parser.getCommand();
			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();
			Task nulTask = Task();

			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			allTask = logic.Delete(allTask,displayedTaskList,actualCommand.idx);

			Assert::IsTrue(allTask.size() == previousSize);
		}

	};
}