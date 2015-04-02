#include "TimeParser.h"

TimeParser::TimeParser(void) {
}

TimeParser::~TimeParser(void) {
}

int strToInt(std::string str){
	int number;
	try{
        number = stoi(str);
		
		} catch (std::invalid_argument&){
		} catch (std::out_of_range&){
		}
		return number;
}

bool isWithinRange(int hours, int minutes){
	return (hours<24 || hours>0 || minutes<59 || minutes>0);
}

//Take in a string with one of the following formats: "" or "XXXX" or "XXXX-XXXX"
//and convert it to startingTime and endingTime
void TimeParser::parseTime(std::string time) {
	int size;
	size = time.size();
	int hours;
	int minutes;

	//When string is ""
	if (size == 0) {
		_startingTime.setIsEmpty(true);
		_endingTime.setIsEmpty(true);

	//When string is "XXXX"
	} else if (size == 4) {
		hours = strToInt(time.substr(0, 2));
		minutes = strToInt(time.substr(2, 2));

		isWithinRange(hours, minutes);

		_startingTime.setHours(hours);
		_startingTime.setMinutes(minutes);
		_startingTime.setIsEmpty(false);

		_endingTime = _startingTime;

	//When string is "XXXX-XXXX"
	} else if (size == 9) {
		hours = strToInt(time.substr(0, 2));	
		minutes = strToInt(time.substr(2, 2));

		isWithinRange(hours, minutes);

		_startingTime.setHours(hours);
		_startingTime.setMinutes(minutes);
		_startingTime.setIsEmpty(false);

		hours = strToInt(time.substr(5, 2));	
		minutes = strToInt(time.substr(7, 2));
		
		isWithinRange(hours, minutes);

		_endingTime.setHours(hours);
		_endingTime.setMinutes(minutes);
		_endingTime.setIsEmpty(false);
	}
}

Time TimeParser::getStartingTime() {
	return _startingTime;
}
	
Time TimeParser::getEndingTime() {
	return _endingTime;
}