#include "DateParser.h"

DateParser::DateParser(void) {
}

DateParser::~DateParser(void) {
}

//Convert month into enum Month type
Month toMonth(int month){
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

int strToInt(std::string str){
	int number;
	try{
        number = stoi(str);
		
		} catch (std::invalid_argument&){
		} catch (std::out_of_range&){
		}
		return number;
}

bool isWithinRange(int day, int month, int year){
	if(day<0 || day>31 || month>12 || month<0 || year<0){
		return false;
	}

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		return false; // only 1,3,5,7,8,10,12 has 31 days
	} else if (month == 2) {
		//leap year
		if(year % 4==0){
			if(day == 30 || day == 31){
				return false;
			} else{
				return true;
			}
		}else{
			if(day == 29 || day == 30 ||day == 31){
				return false;
			}else{
				return true;
			}
		}
	}else{				 
		return true;				 
	}
	   			
}

//Take in a string with one of the following formats: "" or "XX/XX/XXXX" or "XX/XX/XXXX-XX/XX/XXXX"
//and convert it to startingTime and endingTime
void DateParser::parseDate(std::string date) {
	int size;
	size = date.size();

	int day;
	int month;
	int year;
	Month convertedMonth;

	//When string is ""
	if (size == 0) {
		_startingDate.setIsEmpty(true);
		_endingDate.setIsEmpty(true);

	//When string is "XX/XX/XXXX"
	} else if (size == 10) {
		
        day = strToInt(date.substr(0, 2));
		month = strToInt(date.substr(3, 2));
		convertedMonth = toMonth(month);
		year = strToInt(date.substr(6, 4));

		isWithinRange(day,month,year);

		_startingDate.setDay(day);
		_startingDate.setMonth(convertedMonth);		
		_startingDate.setYear(year);

		_startingDate.setIsEmpty(false);

		_endingDate = _startingDate;

	//When string is "XX/XX/XXXX-XX/XX/XXXX"
	} else if (size == 21) {
		_startingDate.setDay(stoi(date.substr(0, 2)));

		//Convert month into enum Month type
		month = stoi(date.substr(3, 2));
		convertedMonth = toMonth(month);
		_startingDate.setMonth(convertedMonth);
		
		_startingDate.setYear(stoi(date.substr(6, 4)));
		_startingDate.setIsEmpty(false);

		_endingDate.setDay(stoi(date.substr(11, 2)));

		//Convert month into enum Month type
		month = stoi(date.substr(14, 2));
		convertedMonth = toMonth(month);
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