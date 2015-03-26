//author A0108417J

#include <iostream>
#include "Date.h"

Date::Date(void) {
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

int Date::getYear() {
	return _year;
}

Month Date::getMonth() {
	return _month;
}

int Date::getDay() {
	return _day;
}

bool Date::isDateNull() {
	if ((_year == NULL) && (_month == NULLMONTH) && (_day == NULL)) {
		return true;
	} else {
		return false;
	}
}

bool Date::isDateSame(Date date) {
	if ((_year == date.getYear()) && (_month == date.getMonth()) && (_day == date.getDay())) {
		return true;
	} else {
		return false;
	}
}