#include "Task.h"

Task::Task(void) {
}

Task::~Task(void) {
}

void Task::inputTitle(std::string title) {
	_title = title;
}

std::string Task::getTitle() {
	return _title;
}