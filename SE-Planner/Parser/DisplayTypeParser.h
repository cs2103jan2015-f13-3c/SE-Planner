#pragma once

#include <string>
#include "DateParser.h"
#include "Date.h"

enum DisplayType {
	OVERDUE, TODAY, ALL, SPECIFICDATE
};

class DisplayTypeParser {
private:
	DisplayType _displayType;
	DateParser _dateParser;

public:
	DisplayTypeParser(void);
	~DisplayTypeParser(void);

	DisplayType getDisplayType();
	Date getSpecificDate();

	bool parseDisplayType(std::string);
};