#pragma once

#include <string>
#include "Date.h"

class DateParser {
private:
	Date _startingDate;
	Date _endingDate;
	std::string _decodeDate;

	bool decode(std::string);
	bool isLeapYear(int);
	Month monthConversion(int);

public:
	DateParser(void);
	~DateParser(void);

	Date getStartingDate();
	Date getEndingDate();

	bool parseDate(std::string);
};