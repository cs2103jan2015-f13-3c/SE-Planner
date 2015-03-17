#pragma once

enum TimeType {
	AM, PM
};

class Time {
private:
	TimeType _timeType;
	int _hours;
	int _minutes;

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