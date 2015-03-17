#include "Time.h"

Time::Time(void) {
}

Time::~Time(void) {
}

void Time::setTimeType(TimeType timeType) {
	_timeType = timeType;
}

void Time::setHours(int hours) {
	_hours = hours;
}

void Time::setMinutes(int minutes) {
	_minutes = minutes;
}

TimeType Time::getTimeType() {
	return _timeType;
}

int Time::getHours() {
	return _hours;
}

int Time::getMinutes() {
	return _minutes;
}