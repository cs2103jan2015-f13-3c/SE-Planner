#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
			matchTask = logic.Search(allTask,nulTask);

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
			matchTask = logic.Search(allTask,searchTask);

			Assert::AreEqual(1, (int)matchTask.size());
		}
	};
}