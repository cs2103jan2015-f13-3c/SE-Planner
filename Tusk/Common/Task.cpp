#include "Task.h"

Task::Task(void) {
}

Task::~Task(void) {
}

void Task::inputTaskType(TaskType taskType) {
	_taskType = taskType;
}

void Task::inputTitle(std::string title) {
	_title = title;
}

TaskType Task::getTaskType() {
	return _taskType;
}

std::string Task::getTitle() {
	return _title;
}