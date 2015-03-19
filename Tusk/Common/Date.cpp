//author A0108417J

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

//Precondition: Date's details on year and month must be stored beforehand.
void Date::setDay(int day) {
	assert(isDayCorrect(day));
	_day = day;
}

bool Date::isDayCorrect(int day) {
	bool isCorrect;

	if (isMonthFebruary() && !isLeapYear()) {
		isCorrect = isDayCorrectForMonth(day+1);
	} else {
		isCorrect = isDayCorrectForMonth(day);
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
	if (!isYearDivisible(DIVISOR_FOUR)) {
		return false;
	} else if (!isYearDivisible(DIVISOR_ONEHUNDRED)) {
		return true;
	} else if (!isYearDivisible(DIVISOR_FOURHUNDRED)) {
		return false;
	} else {
		return true;
	}
}

bool Date::isYearDivisible(int divisor) {
	if (_year%divisor == 0) {
		return true;
	} else {
		return false;
	}
}

bool Date::isDayCorrectForMonth(int day) {
	if ((day >= MINIMUM_DAY) && (day <= MAXIMUM_DAY_FOR_MONTH[_month])) {
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