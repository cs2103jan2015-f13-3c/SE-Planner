#pragma once

#include <string>
#include "Time.h"

class TimeParser {
private:
	Time _startingTime;
	Time _endingTime;
	std::string _decodeTime;

	bool decode(std::string);

public:
	TimeParser(void);
	~TimeParser(void);

	Time getStartingTime();
	Time getEndingTime();

	bool parseTime(std::string);
};