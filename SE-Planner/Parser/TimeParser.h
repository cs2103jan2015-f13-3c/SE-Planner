#pragma once

#include <string>
#include "Time.h"

class TimeParser {
private:
	Time _startingTime;
	Time _endingTime;

public:
	TimeParser(void);
	~TimeParser(void);

	void parseTime(std::string);
	Time getStartingTime();
	Time getEndingTime();
};