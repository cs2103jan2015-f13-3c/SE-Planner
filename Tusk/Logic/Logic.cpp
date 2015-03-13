#include "Logic.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

void Logic::setInpuedMessage(std::string inputedMessage) {
	_inputedMessage = inputedMessage;
}

void Logic::setCommand(Command command) {
	_command = command;
}

void Logic::setTask(Task task) {
	_task = task;
}

void Logic::setMainTaskList(std::vector<Task> mainTaskList) {
	_mainTaskList = mainTaskList;
}

Command Logic::getCommand() {
	return _command;
}

Task Logic::getTask() {
	return _task;
}

std::vector<Task> Logic::getDisplayedTaskList() {
	return _displayedTaskList;
}

void Logic::executeCommand() {
	switch (_command.getCommandType()) {
	case CREATE:
		_create.executeCommand(_mainTaskList, _task);
		break;
	case READ:
		break;
	case UPDATE:
		break;
	case DELETE:
		_delete.executeCommand(_mainTaskList, _task, _displayedTaskList);
		break;
	}
}