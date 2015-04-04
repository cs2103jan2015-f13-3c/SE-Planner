#include "DateParser.h"

const int MAXIMUM_DAY_FOR_MONTH[12] = {31, 28, 31, 30,
									   31, 30, 31, 31,
									   30, 31, 30, 31};

DateParser::DateParser(void) {
}

DateParser::~DateParser(void) {
}

Date DateParser::getStartingDate() {
	return _startingDate;
}

Date DateParser::getEndingDate() {
	return _endingDate;
}

//Decode dateInput into suitable format
//before inputting dateInput into startingDate and endingDate
bool DateParser::parseDate(std::string dateInput) {
	if (dateInput.empty()) {
		_startingDate.setIsEmpty(true);
		_endingDate.setIsEmpty(true);
		return true;
	} else {
		bool decodeResult = decode(dateInput);

		if (decodeResult) {
			_startingDate.setYear(stoi(_decodeDate.substr(4, 4)));
			_startingDate.setMonth(monthConversion(stoi(_decodeDate.substr(2, 2))));
			_startingDate.setDay(stoi(_decodeDate.substr(0, 2)));
			_startingDate.setIsEmpty(false);
			_endingDate.setYear(stoi(_decodeDate.substr(12, 4)));
			_endingDate.setMonth(monthConversion(stoi(_decodeDate.substr(10, 2))));
			_endingDate.setDay(stoi(_decodeDate.substr(8, 2)));
			_endingDate.setIsEmpty(false);
			return true;
		}
	}

	return false;
}

//Decode timeInput into 16 characters string format
//which the first 8 characters represents the starting time
//and the last 8 characters represents the ending time
bool DateParser::decode(std::string dateInput) {
	int size = dateInput.size();

	//Check if dateInput is in XX/XX/XXXX format
	if (size == 10) {
		int year = stoi(dateInput.substr(6, 4));
		int month = stoi(dateInput.substr(3, 2));
		int day = stoi(dateInput.substr(0, 2));

		if ((year >= 0) && (month >= 1) && (month <= 12) &&
			(dateInput[2] == '/') && (dateInput[5] == '/')) {

			//Check for leap year and FEBRUARY month
			if ((month == 2) && (isLeapYear(year))) {
				if ((day >= 1) && (day <= MAXIMUM_DAY_FOR_MONTH[month - 1] + 1)) {
					_decodeDate = dateInput.substr(0, 2) + dateInput.substr(3, 2) + dateInput.substr(6, 4);
					_decodeDate = _decodeDate + _decodeDate;
					return true;
				}

			//When not leap year or FEBRUARY month
			} else if ((day >= 1) && (day <= MAXIMUM_DAY_FOR_MONTH[month - 1])) {
					_decodeDate = dateInput.substr(0, 2) + dateInput.substr(3, 2) + dateInput.substr(6, 4);
					_decodeDate = _decodeDate + _decodeDate;
					return true;
			}
		}

	//Check if dateInput is in XX/XX/XXXX-XX/XX/XXXX format
	} else if (size == 21) {
		int startingYear = stoi(dateInput.substr(6, 4));
		int startingMonth = stoi(dateInput.substr(3, 2));
		int startingDay = stoi(dateInput.substr(0, 2));
		int endingYear = stoi(dateInput.substr(17, 4));
		int endingMonth = stoi(dateInput.substr(14, 2));
		int endingDay = stoi(dateInput.substr(11, 2));

		if ((startingYear >= 0) && (startingMonth >= 1) && (startingMonth <= 12) &&
			(endingYear >= 0) && (endingMonth >= 1) && (endingMonth <= 12) &&
			(dateInput[2] == '/') && (dateInput[5] == '/') && (dateInput[13] == '/' && (dateInput[16] == '/') &&
			(dateInput[10] == '-'))) {

			//Check for leap year and FEBRUARY month for starting date
			if ((startingMonth == 2) && (isLeapYear(startingYear))) {
				if ((startingDay >= 1) && (startingDay <= MAXIMUM_DAY_FOR_MONTH[startingMonth - 1] + 1)) {
					_decodeDate = dateInput.substr(0, 2) + dateInput.substr(3, 2) + dateInput.substr(6, 4);

					//Check for leap year and FEBRUARY month for ending date
					if ((endingMonth == 2) && (isLeapYear(endingYear))) {
						if ((endingDay >= 1) && (endingDay <= MAXIMUM_DAY_FOR_MONTH[endingMonth - 1] + 1)) {
							_decodeDate = _decodeDate + dateInput.substr(11, 2) + dateInput.substr(14, 2) + dateInput.substr(17, 4);
							return true;
						}

					//When not leap year or FEBRUARY month for ending date
					} else if ((endingDay >= 1) && (endingDay <= MAXIMUM_DAY_FOR_MONTH[endingMonth - 1])) {
						_decodeDate = _decodeDate + dateInput.substr(11, 2) + dateInput.substr(14, 2) + dateInput.substr(17, 4);
						return true;
					}
				}

			//When not leap year or FEBRUARY month for starting date
			} else if ((startingDay >= 1) && (startingDay <= MAXIMUM_DAY_FOR_MONTH[startingMonth - 1])) {
					_decodeDate = dateInput.substr(0, 2) + dateInput.substr(3, 2) + dateInput.substr(6, 4);

					//Check for leap year and FEBRUARY month for ending date
					if ((endingMonth == 2) && (!isLeapYear(endingYear))) {
						if ((endingDay >= 1) && (endingDay <= MAXIMUM_DAY_FOR_MONTH[endingMonth - 1] + 1)) {
							_decodeDate = _decodeDate + dateInput.substr(11, 2) + dateInput.substr(14, 2) + dateInput.substr(17, 4);
							return true;
						}

					//When not leap year or FEBRUARY month for ending date
					} else if ((endingDay >= 1) && (endingDay <= MAXIMUM_DAY_FOR_MONTH[endingMonth - 1])) {
							_decodeDate = _decodeDate + dateInput.substr(11, 2) + dateInput.substr(14, 2) + dateInput.substr(17, 4);
							return true;
						}
					}
		}
	}

	return false;
}

bool DateParser::isLeapYear(int year) {
	if (year%4 != 0) {
		return false;
	} else if (year%100 != 0) {
		return true;
	} else if (year%400 != 0) {
		return false;
	} else {
		return true;
	}
}

Month DateParser::monthConversion(int month) {
	Month convertedMonth;

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

	return convertedMonth;
}