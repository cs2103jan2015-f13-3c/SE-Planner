#include "Command.h"

#include <iostream>

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::setTask(Task task) {
	_task = task;
}

void Command::setInformation(std::string information) {
	_information = information;
}

void Command::setDisplayedTaskList(std::vector<Task> displayedTaskList) {
	_displayedTaskList = displayedTaskList;
}

std::vector<Task> Command::getResult() {
	return _result;
}

void Command::execute() {
}