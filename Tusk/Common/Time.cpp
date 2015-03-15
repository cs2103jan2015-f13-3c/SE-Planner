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

inline int Time::getHours() {
	return _hours;
}

inline int Time::getMinutes() {
	return _minutes;
}