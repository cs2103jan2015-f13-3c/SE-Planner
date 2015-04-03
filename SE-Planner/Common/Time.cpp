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

bool Time::isSame(Time time) {
	if ((_hours == time.getHours()) && (_minutes == time.getMinutes())) {
		return true;
	} else {
		return false;
	}
}