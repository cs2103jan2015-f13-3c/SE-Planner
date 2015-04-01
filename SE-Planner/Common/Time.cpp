#include "Time.h"

Time::Time(void) {
	_isEmpty = true;
}

Time::~Time(void) {
}

void Time::setHours(int hours) {
	_hours = hours;
}

void Time::setMinutes(int minutes) {
	_minutes = minutes;
}

void Time::setIsEmpty(bool isEmpty) {
	_isEmpty = isEmpty;
}

int Time::getHours() {
	return _hours;
}

int Time::getMinutes() {
	return _minutes;
}

bool Time::getIsEmpty() {
	return _isEmpty;
}

bool Time::isTimeSame(Time time) {
	if ((_hours == time.getHours()) && (_minutes == time.getMinutes()) && (_isEmpty == time.getIsEmpty())) {
		return true;
	} else {
		return false;
	}
}