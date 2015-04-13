//@author A0115935A
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UIUnitTest {		
	TEST_CLASS(UIUnitTestClass) {
	public:
		
		TEST_METHOD(UIEmptyDisplayTrue) {	
			UI testUI;
			vector<Task> testVector;
			bool actualOutput;
			bool expectedOutput = true;

			actualOutput = testUI.printIfEmpty(testVector);
			Assert::AreEqual(expectedOutput, actualOutput);

			string expectedPrint = "Empty\n\n";
			string actualPrint = testUI.getOutputString();

			Assert::AreEqual(expectedPrint, actualPrint);
		}

		TEST_METHOD(UIEmptyDisplayFalse) {	
			UI testUI;
			vector<Task> testVector;
			bool actualOutput;
			bool expectedOutput = false;

			Task testTask;
			testTask.title = "hello";

			testVector.push_back(testTask);

			actualOutput = testUI.printIfEmpty(testVector);
			Assert::AreEqual(expectedOutput, actualOutput);

			string expectedPrint = "";
			string actualPrint = testUI.getOutputString();

			Assert::AreEqual(expectedPrint, actualPrint);
		}

		TEST_METHOD(UIDisplay) {	
			UI testUI;
			Storage storage = Storage("..\\SE-PlannerExe\\output_unittest.txt");
			Logic logic;

			vector<Task> allTask = storage.getAllTask();
			Parser parser = Parser("display all");
			Command actualCommand = parser.getCommand();

			Task nulTask = Task();

			vector<Task> displayTask = logic.Display(allTask, nulTask, actualCommand.instruction);

			Assert::AreEqual(6,(int)displayTask.size());

			testUI.showTaskList(displayTask);

		}

		TEST_METHOD(UIInputHelp)
		{
			UI testUI;

			testUI.showHelp();

		}

	};
}