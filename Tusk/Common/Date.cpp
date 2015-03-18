#include <assert.h>
#include "Date.h"

const int MAXIMUM_DAY_FOR_MONTH[DECEMBER+1] = {31, 29, 31, 30, 
											   31, 30, 31, 31,
											   30, 31, 30, 31};

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
	_day = day;
}

bool Date::isDayCorrect(int day) {
	if ((day >= 1) && (day <= MAXIMUM_DAY_FOR_MONTH[_month])) {
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