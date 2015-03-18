#include <assert.h>
#include "Time.h"

const int MAXIMUM_HOURS = 12;
const int MINIMUM_HOURS = 1;
const int MAXIMUM_MINUTES = 59;
const int MINIMUM_MINUTES = 0;

Time::Time(void) {
}

Time::~Time(void) {
}

void Time::setTimeType(TimeType timeType) {
	_timeType = timeType;
}

void Time::setHours(int hours) {
	assert(isHoursCorrect(hours));
	_hours = hours;
}

bool Time::isHoursCorrect(int hours) {
	if ((hours >= MINIMUM_HOURS) && (hours <= MAXIMUM_HOURS)) {
		return true;
	} else {
		return false;
	}
}

void Time::setMinutes(int minutes) {
	assert(isMinutesCorrect(minutes));
	_minutes = minutes;
}

bool Time::isMinutesCorrect(int minutes) {
	if ((minutes >= MAXIMUM_MINUTES) && (minutes <= MAXIMUM_MINUTES)) {
		return true;
	} else {
		return false;
	}
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