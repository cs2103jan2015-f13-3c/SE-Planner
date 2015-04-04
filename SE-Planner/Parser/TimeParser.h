#pragma once

#include <string>
#include "MyTime.h"

class TimeParser {
private:
	MyTime _startingTime;
	MyTime _endingTime;
	std::string _decodeTime;

	bool decode(std::string);

public:
	TimeParser(void);
	~TimeParser(void);

	MyTime getStartingTime();
	MyTime getEndingTime();

	bool parseTime(std::string);
};