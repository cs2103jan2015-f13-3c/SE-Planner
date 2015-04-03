#include "Task.h"

Task::Task(void) {
}

Task::~Task(void) {
}

void Task::setTaskType(TaskType taskType) {
	_taskType = taskType;
}

void Task::setDescription(std::string description) {
	_description = description;
}

void Task::setIsDone(bool isDone) {
	_isDone = isDone;
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

TaskType Task::getTaskType() {
	return _taskType;
}

std::string Task::getDescription() {
	return _description;
}

bool Task::getIsDone() {
	return _isDone;
}

Time Task::getStartingTime() {
	return _startingTime;
}

Time Task::getEndingTime() {
	return _endingTime;
}

Date Task::getStartingDate() {
	return _startingDate;
}

Date Task::getEndingDate() {
	return _endingDate;
}

bool Task::isSameAs(Task task) {
	if ((_taskType == task.getTaskType()) &&
		(_description == task.getDescription()) &&
		(_isDone == task.getIsDone()) &&
		(_startingTime.isSameAs(task.getStartingTime())) &&
		(_endingTime.isSameAs(task.getEndingTime())) &&
		(_startingDate.isSameAs(task.getStartingDate())) &&
		(_endingDate.isSameAs(task.getEndingDate()))) {
			return true;
	} else {
		return false;
	}
}