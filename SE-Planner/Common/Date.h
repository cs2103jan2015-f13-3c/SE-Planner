#pragma once

enum Month {
	JANUARY=1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
	JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class Date {
private:
	int _year;
	Month _month;
	int _day;
	bool _isEmpty;

public:
	Date(void);
	~Date(void);

	void setYear(int);
	void setMonth(Month);
	void setDay(int);
	void setIsEmpty(bool);

	int getYear();
	Month getMonth();
	int getDay();
	bool getIsEmpty();

	bool isSame(Date);
};