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

void Task::setStartingTime(std::string startingTime) {
	_startingTime = startingTime;
}

void Task::setEndingTime(std::string endingTime) {
	_endingTime = endingTime;
}

inline TaskType Task::getTaskType() {
	return _taskType;
}

inline std::string Task::getTitle() {
	return _title;
}

inline std::string Task::getStartingTime() {
	return _startingTime;
}

inline std::string Task::getEndingTime() {
	return _endingTime;
}