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

inline int Date::getDay() {
	return _day;
}

inline int Date::getMonth() {
	return _month;
}

inline int Date::getYear() {
	return _year;
}