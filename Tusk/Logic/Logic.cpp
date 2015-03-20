#include "Logic.h"
#include "../Parser/CommandParser.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

void Logic::setInpuedMessage(std::string inputedMessage) {
	_inputedCommand = inputedMessage;
}

void Logic::setCommand(Command command) {
	_command = command;
}

void Logic::setTask(Task task) {
	_task = task;
}

void Logic::setMainTaskList(std::vector<Task> mainTaskList) {
	_storedTaskList = mainTaskList;
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
	return _storedTaskList;
}
void Logic::executeCommand() {
	switch (_command.getCommandType()) {
	case ADD:
		executeAdd(_storedTaskList, _task);
		break;
	case DISPLAY:
		_//displayedTaskList = _read.executeCommand(_storedTaskList, _task);
		;break;
	case EDIT:
		//_update.executeCommand(_storedTaskList, _task, _displayedTaskList);
		break;
	case DELETE:
		executeDelete(_storedTaskList, _task, _displayedTaskList);
		break;
	}
}