#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StorageUnitTest
{		
	TEST_CLASS(StorageUnitTestClass)
	{
	public:
		
		TEST_METHOD(Storage_ReadFileTest)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output.txt");

			vector<Task> actualTaskList = storage.getAllTask();

			Assert::AreEqual(2,(int)actualTaskList.size());
			
		}

		TEST_METHOD(Storage_AutoCreateNewFileTest)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output1.txt");

			vector<Task> actualTaskList = storage.getAllTask();

			Assert::AreEqual(0,(int)actualTaskList.size());
		}

		TEST_METHOD(Storage_WriteToFile)
		{
			Storage storage = Storage("..\\SE-PlannerExe\\output.txt");

			vector<Task> actualTaskList = storage.getAllTask();

			int previousNumberOfTask = actualTaskList.size();
			// perform one add
			Parser parser = Parser("add a random new task");
			Logic logic;
			
			actualTaskList = logic.Add(actualTaskList, parser.getTask());

			storage.writeToFile(actualTaskList);

			vector<Task> newTaskList = storage.getAllTask();
			int newNumberOfTask = newTaskList.size();

			Assert::AreEqual(newNumberOfTask,previousNumberOfTask+1);

		}

	};
}