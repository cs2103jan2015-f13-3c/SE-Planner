#include "TimeParser.h"

TimeParser::TimeParser(void) {
}

TimeParser::~TimeParser(void) {
}

MyTime TimeParser::getStartingTime() {
	return _startingTime;
}

MyTime TimeParser::getEndingTime() {
	return _endingTime;
}

//Decode timeInput into suitable format
//before inputting timeInput into startingTime and endingTime
bool TimeParser::parseTime(std::string timeInput) {
	if (timeInput.empty()) {
		_startingTime.setIsEmpty(true);
		_endingTime.setIsEmpty(true);
		return true;
	} else {
		bool decodeResult = decode(timeInput);

		if (decodeResult) {
			_startingTime.setHours(stoi(_decodeTime.substr(0, 2)));
			_startingTime.setMinutes(stoi(_decodeTime.substr(2, 2)));
			_startingTime.setIsEmpty(false);
			_endingTime.setHours(stoi(_decodeTime.substr(4, 2)));
			_endingTime.setMinutes(stoi(_decodeTime.substr(6, 2)));
			_endingTime.setIsEmpty(false);
			return true;
		}
	}

	return false;
}

// Check if time entered is between 0-23 for hours and 0-59 for minutes
bool isWithinRange(int hours, int minutes){
	return ((hours >= 0) && (hours <= 23) && (minutes >= 0) && (minutes <= 59));
}

//Decode timeInput into 8 characters string format
//which the first 4 characters represents the starting time
//and the last 4 characters represents the ending time
bool TimeParser::decode(std::string timeInput) {
	int size = timeInput.size();

	//Check if timeInput is in XXXX format
	if (size == 4) {
		int hours = stoi(timeInput.substr(0, 2));
		int minutes = stoi(timeInput.substr(2, 2));

		if (isWithinRange(hours, minutes)) {
				_decodeTime = timeInput + timeInput;
				return true;
		}

	//Check if timeInput is in XXXX-XXXX format
	} else if (size == 9) {
		int startingHours = stoi(timeInput.substr(0, 2));
		int startingMinutes = stoi(timeInput.substr(2, 2));
		int endingHours = stoi(timeInput.substr(5, 2));
		int endingMinutes = stoi(timeInput.substr(7, 2));

		if ( isWithinRange(startingHours, startingMinutes) &&
			isWithinRange(endingHours, endingMinutes) &&
			(timeInput[4] == '-') ) {
				_decodeTime = timeInput.substr(0, 4) + timeInput.substr(5, 4);
				return true;
		}
	}

	return false;
}