#include "Task.h"

Task::Task(void) {
}

Task::~Task(void) {
}

void Task::inputTask(std::string task) {
	_task = task;
}

std::string Task::getTask() {
	return _task;
}