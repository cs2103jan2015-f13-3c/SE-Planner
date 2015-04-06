#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserTest
{
	TEST_CLASS(CommandTypeParserTest)
	{
	public:
		
			TEST_METHOD(CommandTypeParserTestMethod){
			// TODO: Your test code here
			Assert::AreEqual(1,1);
			CommandTypeParser cmdParser;
			cmdParser.parseCommandType("add");
			

		}

	};
}