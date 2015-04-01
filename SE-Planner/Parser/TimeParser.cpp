#include "TimeParser.h"

TimeParser::TimeParser(void) {
}

TimeParser::~TimeParser(void) {
}

//Take in a string with one of the following formats: "" or "XXXX" or "XXXX-XXXX"
//and convert it to startingTime and endingTime
void TimeParser::parseTime(std::string time) {
	int size;
	size = time.size();

	//When string is ""
	if (size == 0) {
		_startingTime.setIsEmpty(true);
		_endingTime.setIsEmpty(true);

	//When string is "XXXX"
	} else if (size == 4) {
		_startingTime.setHours(stoi(time.substr(0, 2)));
		_startingTime.setMinutes(stoi(time.substr(2, 2)));
		_startingTime.setIsEmpty(false);

		_endingTime = _startingTime;

	//When string is "XXXX-XXXX"
	} else if (size == 9) {
		_startingTime.setHours(stoi(time.substr(0, 2)));
		_startingTime.setMinutes(stoi(time.substr(2, 2)));
		_startingTime.setIsEmpty(false);

		_endingTime.setHours(stoi(time.substr(5, 2)));
		_endingTime.setMinutes(stoi(time.substr(7, 2)));
		_endingTime.setIsEmpty(false);
	}
}

Time TimeParser::getStartingTime() {
	return _startingTime;
}
	
Time TimeParser::getEndingTime() {
	return _endingTime;
}