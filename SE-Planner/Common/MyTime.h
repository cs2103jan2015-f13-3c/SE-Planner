#pragma once

class MyTime {
private:
	int _hours;
	int _minutes;
	bool _isEmpty;

public:
	MyTime(void);
	~MyTime(void);

	void setHours(int);
	void setMinutes(int);
	void setIsEmpty(bool);

	int getHours();
	int getMinutes();
	bool getIsEmpty();

	bool isSameAs(MyTime);
	bool isLaterThan(MyTime);
};