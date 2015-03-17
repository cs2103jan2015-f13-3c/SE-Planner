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