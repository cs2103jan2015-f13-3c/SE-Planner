#include "DisplayTypeParser.h"

DisplayTypeParser::DisplayTypeParser(void) {
}

DisplayTypeParser::~DisplayTypeParser(void) {
}

DisplayType DisplayTypeParser::getDisplayType() {
	return _displayType;
}

Date DisplayTypeParser::getSpecificDate() {
	return _dateParser.getStartingDate();
}

bool DisplayTypeParser::parseDisplayType(std::string displayInput) {
	if (displayInput == "overdue") {
		_displayType = OVERDUE;
	} else if (displayInput == "today") {
		_displayType = TODAY;
	} else if (displayInput == "all") {
		_displayType = ALL;
	} else {
		bool executionResult = _dateParser.parseDate(displayInput);

		if (!executionResult) {
			return false;
		}

		_displayType = SPECIFICDATE;
	}

	return true;
}