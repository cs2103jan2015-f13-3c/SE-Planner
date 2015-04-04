#include "MyTime.h"

MyTime::MyTime(void) {
	_isEmpty = true;
}

MyTime::~MyTime(void) {
}

void MyTime::setHours(int hours) {
	_hours = hours;
}

void MyTime::setMinutes(int minutes) {
	_minutes = minutes;
}

void MyTime::setIsEmpty(bool isEmpty) {
	_isEmpty = isEmpty;
}

int MyTime::getHours() {
	return _hours;
}

int MyTime::getMinutes() {
	return _minutes;
}

bool MyTime::getIsEmpty() {
	return _isEmpty;
}

bool MyTime::isSameAs(MyTime time) {
	if ((_hours == time.getHours()) &&
		(_minutes == time.getMinutes()) &&
		(_isEmpty == time.getIsEmpty())) {
		return true;
	} else {
		return false;
	}
}

bool MyTime::isLaterThan(MyTime time) {
	if ((_hours > time.getHours()) ||
		((_hours == time.getHours()) && (_minutes > time.getMinutes()))) {
		return true;
	} else {
		return false;
	}
}