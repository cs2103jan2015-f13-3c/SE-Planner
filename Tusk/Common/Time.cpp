#include "Time.h"

Time::Time(void) {
}

Time::~Time(void) {
}

void Time::setHours(int hours) {
	_hours = hours;
}

void Time::setMinutes(int minutes) {
	_minutes = minutes;
}

int Time::getHours() {
	return _hours;
}

int Time::getMinutes() {
	return _minutes;
}