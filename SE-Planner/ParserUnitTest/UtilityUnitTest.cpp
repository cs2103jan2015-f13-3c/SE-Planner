#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UtilityUnitTest
{		
	TEST_CLASS(UtilityUnitTestClass)
	{
	public:

		Utility utility;
		bool testValue;

		TEST_METHOD(isValidDate)
		{
			Date testDate = Date(6,6,2015);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, testValue);

			testDate = Date(6,-6,2015);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, !testValue);

			testDate = Date(31,2,2015);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, !testValue);

			testDate = Date(28,2,2015);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, testValue);

			testDate = Date(29,2,2012);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, testValue);

			testDate = Date(29,2,2000);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, testValue);

			testDate = Date(29,2,3000);
			testValue = utility.isValidDate(testDate);
			Assert::AreEqual(true, !testValue);
		}

		TEST_METHOD(isValidTime)
		{	
			Time testTime = Time(15,0);
			testValue = utility.isValidTime(testTime);
			Assert::AreEqual(true,testValue);

			testTime = Time(15,66);
			testValue = utility.isValidTime(testTime);
			Assert::AreEqual(false,testValue);

			testTime = Time(25,0);
			testValue = utility.isValidTime(testTime);
			Assert::AreEqual(false,testValue);

			testTime = Time(7,30);
			testValue = utility.isValidTime(testTime);
			Assert::AreEqual(true,testValue);

			testTime = Time(15,-1);
			testValue = utility.isValidTime(testTime);
			Assert::AreEqual(false,testValue);
		}

		TEST_METHOD(isLaterDate)
		{
			Date dateBefore, dateAfter;

			dateBefore = Date(2,4,2015);
			dateAfter = Date(3,4,2015);
			testValue = utility.isLaterDate(dateBefore, dateAfter);
			Assert::AreEqual(true, testValue);

			dateBefore = Date(2,4,2015);
			dateAfter = Date(1,4,2015);
			testValue = utility.isLaterDate(dateBefore, dateAfter);
			Assert::AreEqual(false, testValue);

			dateBefore = Date(2,4,2015);
			dateAfter = Date(2,4,2015);
			testValue = utility.isLaterDate(dateBefore, dateAfter);
			Assert::AreEqual(true, testValue);
		}

		TEST_METHOD(isLaterTime)
		{
			Time timeBefore; 
			Time timeAfter;

			timeBefore = Time(15,30);
			timeAfter = Time(15,31);
			testValue = utility.isLaterTime(timeBefore, timeAfter);
			Assert::AreEqual(true, testValue);

			timeBefore = Time(15,30);
			timeAfter = Time(15,30);
			testValue = utility.isLaterTime(timeBefore, timeAfter);
			Assert::AreEqual(true, testValue);

			timeBefore = Time(15,30);
			timeAfter = Time(15,29);
			testValue = utility.isLaterTime(timeBefore, timeAfter);
			Assert::AreEqual(false, testValue);
		}

		TEST_METHOD(isDiffDate)
		{
			Date date1, date2;

			date1 = Date(29,3,2015);
			date2 = Date(28,4,2015);
			testValue = utility.isDiffDate(date1,date2);
			Assert::AreEqual(true,testValue);

			date1 = Date(29,3,2015);
			date2 = Date(29,4,2015);
			testValue = utility.isDiffDate(date1,date2);
			Assert::AreEqual(true,testValue);

			date1 = Date(29,3,2015);
			date2 = Date(28,3,2015);
			testValue = utility.isDiffDate(date1,date2);
			Assert::AreEqual(true,testValue);

			date1 = Date(29,3,2015);
			date2 = Date(29,3,2016);
			testValue = utility.isDiffDate(date1,date2);
			Assert::AreEqual(true,testValue);

			date1 = Date(29,3,2015);
			date2 = Date(29,3,2015);
			testValue = utility.isDiffDate(date1,date2);
			Assert::AreEqual(false,testValue);
		}

		TEST_METHOD(isNullDate)
		{
			Date date;

			date = Date();
			testValue = utility.isNull(date);
			Assert::AreEqual(true,testValue);

			date = Date(29,3,2015);
			testValue = utility.isNull(date);
			Assert::AreEqual(false,testValue);
		}

		TEST_METHOD(isNullTime)
		{
			Time time;

			time = Time();
			testValue = utility.isNull(time);
			Assert::AreEqual(true,testValue);

			time = Time(15,30);
			testValue = utility.isNull(time);
			Assert::AreEqual(false,testValue);
		}

		TEST_METHOD(isValidAddTask)
		{	
		}

		TEST_METHOD(isValidOtherTask)
		{	
		}

		TEST_METHOD(compareTitle)
		{
			
		}

		TEST_METHOD(compareDate)
		{	
		}

		TEST_METHOD(compareTime)
		{	
		}

		TEST_METHOD(isSameTask)
		{	
		}

	};
}