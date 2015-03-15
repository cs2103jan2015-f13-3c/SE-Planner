#pragma once

class Date {
private:
	int _day;
	int _month;
	int _year;

public:
	Date(void);
	~Date(void);

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay();
	int getMonth();
	int getYear();
};