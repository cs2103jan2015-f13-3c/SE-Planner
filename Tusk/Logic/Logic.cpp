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

Command Logic::getCommand() {
	return _command;
}

Task Logic::getTask() {
	return _task;
}

std::vector<Task> Logic::getDisplayedTaskList() {
	return _displayedTaskList;
}

void Logic::executeCommand(std::vector<Task> mainTaskList) {
	switch (_command.getCommandType()) {
	case CREATE:
		_create.execute(mainTaskList, _task);
		break;
	case READ:
		break;
	case UPDATE:
		break;
	case DELETE:
		_delete.execute(mainTaskList, _task, _displayedTaskList);
		break;
	}
}