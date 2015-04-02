#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserTest{
	TEST_CLASS(ParserTest){
	public:

		// Method: for testing add command
		TEST_METHOD(ParserTestInputAddMethod){
			Assert::AreEqual(1,1);
			// Test cases and expected result:
			std::vector<std::string> input;
			input.push_back("add FLOATING task one");
			input.push_back("add");
			
			// t1 time: 0100
			// d2 date: - 
			// t2 time: 0100-0100
			// t1d2 date: - time: 
			// date got range only when time got range <- test this
			// if i have time i must have date
			std::vector<std::string> expectedResult;
			expectedResult.push_back("task one");
			expectedResult.push_back("");
			
			// Begin testing
			Parser parser;
			Task outputTask;
			int size = input.size();
			for (int i = 0; i < size; i++) {
				parser.parseUserInput(input.at(i));	
				outputTask = parser.getTask();
			
				Assert::AreEqual(expectedResult.at(i), outputTask.getDescription());
			}		
		}

		// add command test with time input only
		TEST_METHOD(ParserTestAddWithTimeOnlyMethod){
			// Test cases and expected result:
			std::vector<std::string> input;
			input.push_back("add t1 ERROR time w/o range time: 0100");
			input.push_back("add t2 ERROR time range time: 0100-0200");
			
			std::vector<std::string> expectedResult;
			expectedResult.push_back("task one");
			expectedResult.push_back("abcde ");
	
			// Begin testing
			Parser parser;
			Task outputTask;
			int size = input.size();
			for (int i = 0; i < size; i++) {
				parser.parseUserInput(input.at(i));	
				outputTask = parser.getTask();
			
				Assert::AreEqual(expectedResult.at(i), outputTask.getDescription());
			}		
		}
		
		// add command test with date input only
		TEST_METHOD(ParserTestAddWithDateOnlyMethod){
			// Test cases and expected result:
			std::vector<std::string> input;
			input.push_back("add d1 DEADLINE task date w/o range date: 12/12/1234");
			input.push_back("add d2 date w range date: 01/02/1234-12/12/1234");
			
			std::vector<std::string> expectedResult;
			expectedResult.push_back("task one");
			expectedResult.push_back("abcde ");
			
			// Begin testing
			Parser parser;
			Task outputTask;
			int size = input.size();
			for (int i = 0; i < size; i++) {
				parser.parseUserInput(input.at(i));	
				outputTask = parser.getTask();
			
				Assert::AreEqual(expectedResult.at(i), outputTask.getDescription());
			}		
		}
		
		// add command test with time and date input
		TEST_METHOD(ParserTestAddWithDateTimeMethod){
			// Test cases and expected result:
			std::vector<std::string> input;
			input.push_back("add t2d1 time w range, date w/o range  time: 0100-0200 date: 12/12/1234");
			input.push_back("add t1d2 ERROR time w/o range, date w range time: 0100 date: 12/12/1234-12/12/1235");
			input.push_back("add t1d1 TIMED task time w/o range, date w/o range time: 1234 date: 12/12/1234");
			input.push_back("add t2d2 CORRECT time w range, date w range time: 0100-0200 date: 12/12/1234-12/12/1235");
			
			std::vector<std::string> expectedResult;
			expectedResult.push_back("task one");
			expectedResult.push_back("abcde ");
			expectedResult.push_back("tusk ");
			expectedResult.push_back("tusk one ");
			
			// Begin testing
			Parser parser;
			Task outputTask;
			int size = input.size();
			for (int i = 0; i < size; i++) {
				parser.parseUserInput(input.at(i));	
				outputTask = parser.getTask();
			
				Assert::AreEqual(expectedResult.at(i), outputTask.getDescription());
			}
		}

	};//TEST CLASS end
}