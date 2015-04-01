#pragma once

#include <string>
#include "Date.h"

class DateParser {
private:
	Date _startingDate;
	Date _endingDate;

public:
	DateParser(void);
	~DateParser(void);

	void parseDate(std::string);
	Date getStartingDate();
	Date getEndingDate();
};