#include "Add.h"
#include "Delete.h"
#include "Edit.h"
#include "Display.h"
#include "Search.h"
#include "Logic.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

CommandType Logic::executeUserInput(std::string userInput) {
	CommandType commandType;
	commandType = _parser.parseUserInput(userInput);
	createCommand(commandType);
	_result = _command.execute();

	return commandType;
}

void Logic::createCommand(CommandType commandType) {
	switch (commandType) {
	case ADD:
		createAddCommand();
		break;
	case DELETE:
		createDeleteCommand();
		break;
	case EDIT:
		createEditCommand();
		break;
	case DISPLAY:
		createDisplayCommand();
		break;
	case SEARCH:
		createSearchCommand();
	default:
		break;
	};
}

void Logic::createAddCommand() {
	Task task;
	task = _parser.getTask();

	Add add;
	add.setTask(task);

	_command = add;
}

void Logic::createDeleteCommand() {
	std::string information;
	information = _parser.getInformation();

	Delete remove;
	remove.setInformation(information);
	remove.setDisplayedTaskList(_displayTaskList);

	_command = remove;
}

void Logic::createEditCommand() {
	std::string information;
	information = _parser.getInformation();

	Task task;
	task = _parser.getTask();

	Edit edit;
	edit.setInformation(information);
	edit.setTask(task);
	edit.setDisplayedTaskList(_displayTaskList);

	_command = edit;
}

void Logic::createDisplayCommand() {
	Display display;
	_command = display;
}

void Logic::createSearchCommand() {
	std::string information;
	information = _parser.getInformation;

	Search search;
	search.setInformation(information);

	_command = search;
}