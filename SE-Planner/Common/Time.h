#pragma once

class Time {
private:
	int _hours;
	int _minutes;
	bool _isEmpty;

public:
	Time(void);
	~Time(void);

	void setHours(int);
	void setMinutes(int);
	void setIsEmpty(bool);

	int getHours();
	int getMinutes();
	bool getIsEmpty();

	bool isSame(Time);
};