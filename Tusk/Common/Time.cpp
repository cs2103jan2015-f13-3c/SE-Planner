//author A0108417J

#include <iostream>
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

bool Time::isTimeNull() {
	if ((_timeType == NULLTIMETYPE) && (_hours == NULL) && (_minutes == NULL)) {
		return true;
	} else {
		return false;
	}
}

bool Time::isTimeSame(Time time) {
	if ((_timeType == time.getTimeType()) && (_hours == time.getHours()) && (_minutes == time.getMinutes())) {
		return true;
	} else {
		return false;
	}
}