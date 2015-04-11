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

	};
}