#pragma once

class Time {
private:
	int _hours;
	int _minutes;

public:
	Time(void);
	~Time(void);

	void setHours(int);
	void setMinutes(int);

	inline int getHours();
	inline int getMinutes();

};