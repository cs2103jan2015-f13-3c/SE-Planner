#include "DateParser.h"

DateParser::DateParser(void) {
}

DateParser::~DateParser(void) {
}

//Take in a string with one of the following formats: "" or "XX/XX/XXXX" or "XX/XX/XXXX-XX/XX/XXXX"
//and convert it to startingTime and endingTime
void DateParser::parseDate(std::string date) {
	int size;
	size = date.size();

	int month;
	Month convertedMonth;

	//When string is ""
	if (size == 0) {
		_startingDate.setIsEmpty(true);
		_endingDate.setIsEmpty(true);

	//When string is "XX/XX/XXXX"
	} else if (size == 10) {
		_startingDate.setDay(stoi(date.substr(0, 2)));

		//Convert month into enum Month type
		month = stoi(date.substr(3, 2));
		switch (month) {
		case 1:
			convertedMonth = JANUARY;
			break;
		case 2:
			convertedMonth = FEBRUARY;
			break;
		case 3:
			convertedMonth = MARCH;
			break;
		case 4:
			convertedMonth = APRIL;
			break;
		case 5:
			convertedMonth = MAY;
			break;
		case 6:
			convertedMonth = JUNE;
			break;
		case 7:
			convertedMonth = JULY;
			break;
		case 8:
			convertedMonth = AUGUST;
			break;
		case 9:
			convertedMonth = SEPTEMBER;
			break;
		case 10:
			convertedMonth = OCTOBER;
			break;
		case 11:
			convertedMonth = NOVEMBER;
			break;
		case 12:
			convertedMonth = DECEMBER;
			break;
		};
		_startingDate.setMonth(convertedMonth);

		_startingDate.setYear(stoi(date.substr(6, 4)));
		_startingDate.setIsEmpty(false);

		_endingDate = _startingDate;

	//When string is "XX/XX/XXXX-XX/XX/XXXX"
	} else if (size == 21) {
		_startingDate.setDay(stoi(date.substr(0, 2)));

		//Convert month into enum Month type
		month = stoi(date.substr(3, 2));
		switch (month) {
		case 1:
			convertedMonth = JANUARY;
			break;
		case 2:
			convertedMonth = FEBRUARY;
			break;
		case 3:
			convertedMonth = MARCH;
			break;
		case 4:
			convertedMonth = APRIL;
			break;
		case 5:
			convertedMonth = MAY;
			break;
		case 6:
			convertedMonth = JUNE;
			break;
		case 7:
			convertedMonth = JULY;
			break;
		case 8:
			convertedMonth = AUGUST;
			break;
		case 9:
			convertedMonth = SEPTEMBER;
			break;
		case 10:
			convertedMonth = OCTOBER;
			break;
		case 11:
			convertedMonth = NOVEMBER;
			break;
		case 12:
			convertedMonth = DECEMBER;
			break;
		};
		_startingDate.setMonth(convertedMonth);
		
		_startingDate.setYear(stoi(date.substr(6, 4)));
		_startingDate.setIsEmpty(false);

		_endingDate.setDay(stoi(date.substr(11, 2)));

		//Convert month into enum Month type
		month = stoi(date.substr(14, 2));
		switch (month) {
		case 1:
			convertedMonth = JANUARY;
			break;
		case 2:
			convertedMonth = FEBRUARY;
			break;
		case 3:
			convertedMonth = MARCH;
			break;
		case 4:
			convertedMonth = APRIL;
			break;
		case 5:
			convertedMonth = MAY;
			break;
		case 6:
			convertedMonth = JUNE;
			break;
		case 7:
			convertedMonth = JULY;
			break;
		case 8:
			convertedMonth = AUGUST;
			break;
		case 9:
			convertedMonth = SEPTEMBER;
			break;
		case 10:
			convertedMonth = OCTOBER;
			break;
		case 11:
			convertedMonth = NOVEMBER;
			break;
		case 12:
			convertedMonth = DECEMBER;
			break;
		};
		_endingDate.setMonth(convertedMonth);

		_endingDate.setYear(stoi(date.substr(17, 4)));
		_endingDate.setIsEmpty(false);
	}
}
	
Date DateParser::getStartingDate() {
	return _startingDate;
}
	
Date DateParser::getEndingDate() {
	return _endingDate;
}