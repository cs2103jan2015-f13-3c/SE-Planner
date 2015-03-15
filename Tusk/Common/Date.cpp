#include "Date.h"

Date::Date(void) {
}

Date::~Date(void) {
}

void Date::setDay(int day) {
	_day = day;
}

void Date::setMonth(int month) {
	_month = month;
}

void Date::setYear(int year) {
	_year = year;
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}