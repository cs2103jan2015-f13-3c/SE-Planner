#pragma once

//Time class stores the inputted time in _timeType, _hours & _minutes variables
//Sample usage:
//	inputted time = 12.00am
//
//	_timeType = AM
//	_hours = 12
//	_minutes = 0

//Precondition: Inputted time must be in 12hr format instead of 24hr format.
//Sample conversion:
//	24hr Format:	12hr Format:
//		00:00			12.00am
//		00:01			12.01am
//		01:00			1.00am
//
//		12:00			12.00pm
//		12:01			12.01pm
//		13:00			1.00pm

enum TimeType {
	AM, PM
};

class Time {
private:
	TimeType _timeType;
	int _hours;
	int _minutes;

	bool isHoursCorrect(int);
	bool isMinutesCorrect(int);

public:
	Time(void);
	~Time(void);

	void setTimeType(TimeType);
	void setHours(int);
	void setMinutes(int);

	TimeType getTimeType();
	int getHours();
	int getMinutes();
};