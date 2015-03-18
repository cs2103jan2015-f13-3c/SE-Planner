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

	bool isYearPositive(int);
	bool isDayCorrect(int);
	bool isLeapYear();

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