#include "Date.h"

Date::Date(void) {
	_isEmpty = true;
}

Date::~Date(void) {
}

void Date::setYear(int year) {
	_year = year;
}

void Date::setMonth(Month month) {
	_month = month;
}

void Date::setDay(int day) {
	_day = day;
}

void Date::setIsEmpty(bool isEmpty) {
	_isEmpty = isEmpty;
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

bool Date::getIsEmpty() {
	return _isEmpty;
}

bool Date::isSameAs(Date date) {
	if ((_year == date.getYear()) &&
		(_month == date.getMonth()) &&
		(_day == date.getDay()) &&
		(_isEmpty == date.getIsEmpty())) {
			return true;
	} else {
		return false;
	}
}

bool Date::isLaterThan(Date date) {
	if (((_year > date.getYear()) ||
		((_year == date.getYear()) && (_month > date.getMonth())) ||
		(_year == date.getYear()) && (_month == date.getMonth()) && (_day > date.getDay()))) {
			return true;
	} else {
		return false;
	}
}