//Authored by Ang Yoong Zhen
//
//Pre-condition: Date's details must be stored in the following order:
//				 year, month, day
//
//Post-condition: Date will be stored in _year, _month and _day variables
//                which can be retrived and editied individually when needed.
//
//Sample usage:
//		Date date;
//
//	To store/edit date as 12/12/2012 or 12 December 2012:
//		date.setYear(2012);
//		date.setMonth(DECEMBER);
//		date.setDay(12);
//
//	To retrieve date's details:
//		date.getYear();
//		date.getMonth();
//		date.getDay();

#pragma once

enum Month {
	JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
	AUGUST, SEPTEMBER, OCTOBBER, NOVEMBER, DECEMBER
};

class Date {
private:
	int _year;
	Month _month;
	int _day;

	//Supporting functions 
	bool isYearPositive(int);
	bool isDayCorrect(int);
	bool isMonthFebruary();
	bool isLeapYear();
	bool isDayCorrectForMonth(int, Month);

public:
	Date(void);
	~Date(void);

	void setYear(int);
	void setMonth(Month);
	void setDay(int);

	int getYear();
	Month getMonth();
	int getDay();
};