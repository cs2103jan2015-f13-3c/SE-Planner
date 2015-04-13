#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//@author A0116724J
namespace LogicDoneUnitTest
{		
	TEST_CLASS(LogicDeleteUnitTestClass)
	{
	public:
		
		TEST_METHOD(LogicDoneOneIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("done 6");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Done(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(true,newTask[0].isDone);
		}

		TEST_METHOD(LogicDoneMultipleIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("done 5 6");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Done(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(true,newTask[0].isDone);
			Assert::AreEqual(true,newTask[5].isDone);
		}

		TEST_METHOD(LogicDoneInvalidIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("done 10000");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Done(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(0,logic.success);
		}

		TEST_METHOD(LogicUnDoneOneIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("undone 6");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Undone(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(false,newTask[0].isDone);
		}

		TEST_METHOD(LogicUnDoneMultipleIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("undone 5 6");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Undone(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(false,newTask[0].isDone);
			Assert::AreEqual(false,newTask[5].isDone);
		}

		TEST_METHOD(LogicUnDoneInvalidIndex)
		{	
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;
			Parser parser = Parser("undone 10000");
			Command actualCommand = parser.getCommand();


			vector<Task> allTask = storage.getAllTask();

			Task nulTask = Task();
			
			
			vector<Task> displayedTaskList = logic.display(allTask,nulTask,ALL);
			Assert::AreEqual(false,allTask[5].isDone);

			
			vector<Task> newTask;
			newTask = logic.Undone(allTask,displayedTaskList,actualCommand.idx);

			Assert::AreEqual(0,logic.success);
		}

	};
}