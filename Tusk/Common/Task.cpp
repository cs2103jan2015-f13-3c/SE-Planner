#include "Task.h"

Task::Task(void) {
}

Task::~Task(void) {
}

void Task::setTaskType(TaskType taskType) {
	_taskType = taskType;
}

void Task::setTitle(std::string title) {
	_title = title;
}

void Task::setStartingTime(Time startingTime) {
	_startingTime = startingTime;
}

void Task::setEndingTime(Time endingTime) {
	_endingTime = endingTime;
}

void Task::setStartingDate(Date startingDate) {
	_startingDate = startingDate;
}

void Task::setEndingDate(Date endingDate) {
	_endingDate = endingDate;
}

inline TaskType Task::getTaskType() {
	return _taskType;
}

inline std::string Task::getTitle() {
	return _title;
}

inline Time Task::getStartingTime() {
	return _startingTime;
}

inline Time Task::getEndingTime() {
	return _endingTime;
}

inline Date Task::getStartingDate() {
	return _startingDate;
}

inline Date Task::getEndingDate() {
	return _endingDate;
}