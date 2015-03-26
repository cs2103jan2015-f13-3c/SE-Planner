//author A0108417J
//
//Pre-condition: Time must be in 12hr clock format instead of 24hr format.
//Sample conversion:
//	24hr format:	12hr format:
//		00:00			12.00am
//		00:01			12.01am
//		01:00			1.00am
//
//		12:00			12.00pm
//		12:01			12.01pm
//		13:00			1.00pm
//
//Post-condition: Time will be stored in _timeType, _hours and _minutes variables
//				  which can be retrived and edited individually when needed.
//
//Sample usage:
//		Time time;
//
//	To store/edit time as 12.00am:
//		time.setTimeType(AM);
//		time.setHours(12);
//		time.setMinutes(0);
//
//	To retrieve time's details:
//		time.getTimeType();
//		time.getHours();
//		time.getMinutes();

#pragma once

enum TimeType {
	AM, PM
};

class Time {
private:
	TimeType _timeType;
	int _hours;
	int _minutes;

	//Supporting functions
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