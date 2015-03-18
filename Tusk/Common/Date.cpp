//Authored by Ang Yoong Zhen

#include <assert.h>
#include "Date.h"

const int MAXIMUM_DAY_FOR_MONTH[12] = {31, 29, 31, 30, 
									   31, 30, 31, 31,
									   30, 31, 30, 31};
const int MINIMUM_DAY = 1;

const int DIVISOR_FOUR = 4;
const int DIVISOR_ONEHUNDRED = 100;
const int DIVISOR_FOURHUNDRED = 400;

Date::Date(void) {
}

Date::~Date(void) {
}

void Date::setYear(int year) {
	assert(isYearPositive(year));
	_year = year;
}

bool Date::isYearPositive(int year) {
	if (year >= 0) {
		return true;
	} else {
		return false;
	}
}

void Date::setMonth(Month month) {
	_month = month;
}

void Date::setDay(int day) {
	assert(isDayCorrect(day));
	_day = day;
}

bool Date::isDayCorrect(int day) {
	bool isCorrect;

	if (isMonthFebruary() && !isLeapYear()) {
		isCorrect = isDayCorrectForMonth(day+1, _month);
	} else {
		isCorrect = isDayCorrectForMonth(day, _month);
	}

	return isCorrect;
}

bool Date::isMonthFebruary() {
	if (_month == FEBRUARY) {
		return true;
	} else {
		return false;
	}
}

bool Date::isLeapYear() {
	if (_year%DIVISOR_FOUR != 0) {
		return false;
	} else if (_year%DIVISOR_ONEHUNDRED != 0) {
		return true;
	} else if (_year%DIVISOR_FOURHUNDRED != 0) {
		return false;
	} else {
		return true;
	}
}

bool Date::isDayCorrectForMonth(int day, Month month) {
	if ((day >= MINIMUM_DAY) && (day <= MAXIMUM_DAY_FOR_MONTH[month])) {
		return true;
	} else {
		return false;
	}
}

int Date::getYear() {
	return _year;
}

Month Date::getMonth() {
	return _month;
}

int Date::getDay() {
	return _day;
}