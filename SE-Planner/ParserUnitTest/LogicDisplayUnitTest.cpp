#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//@author A0116724J
namespace LogicDisplayUnitTest
{		
	TEST_CLASS(LogicDisplayUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicDisplayToday)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display today");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task taskDate = Task();

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(2,(int)displayTask.size());
		}

		TEST_METHOD(LogicDisplayTmr)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display tomorrow");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task taskDate = Task();

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(2,(int)displayTask.size());
		}

		TEST_METHOD(LogicDisplayOverdue)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display overdue");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task taskDate = Task();

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(5,(int)displayTask.size());
		}

		TEST_METHOD(LogicDisplayDate)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display 11/4");
			Task taskDate = parser.getTask();
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(3,(int)displayTask.size());
		}

		TEST_METHOD(LogicDisplayDone)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display done");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task taskDate = Task();

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(1,(int)displayTask.size());
		}

		TEST_METHOD(LogicDisplayUndone)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("display undone");
			Command actualCommand = parser.getCommand();

			vector<Task> allTask = storage.getAllTask();
			int previousSize = allTask.size();

			Task taskDate = Task();

			vector<Task> displayTask;
			displayTask = logic.display(allTask,taskDate,actualCommand.instruction);

			Assert::AreEqual(5,(int)displayTask.size());
		}
	};
}