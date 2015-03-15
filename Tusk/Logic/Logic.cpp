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

std::vector<Task> Logic::getMainTaskList() {
	return _mainTaskList;
}
void Logic::executeCommand() {
	switch (_command.getCommandType()) {
	case ADD:
		_create.executeCommand(_mainTaskList, _task);
		break;
	case DISPLAY:
		_displayedTaskList = _read.executeCommand(_mainTaskList, _task);		break;
	case EDIT:
		_update.executeCommand(_mainTaskList, _task, _displayedTaskList);
		break;
	case DELETE:
		_delete.executeCommand(_mainTaskList, _task, _displayedTaskList);
		break;
	}
}