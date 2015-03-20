#include "Add.h"
#include "Display.h"
#include "Edit.h"
#include "Delete.h"
#include "Logic.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

std::vector<Task> Logic::executeUserInput(std::string userInput) {
	_parser.parseUserInput(userInput);

	CommandType commandType;
	commandType = _parser.getCommandType();

	Command command;
	command = createCommand(commandType);

	_displayedTaskList = _commandExecutor.executeCommand(command);

	return _displayedTaskList;
}

Command Logic::createCommand(CommandType commandType) {
	Command command;

	Add add;
	Display display;
	Edit edit;
	Delete remove;

	Task task;
	int index;

	task = _parser.getTask();
	index = _parser.getIndex();

	switch (commandType) {
	case ADD:
		add.setTask(task);
		command = add;
		break;

	case DISPLAY:
		command = display;
		break;

	case EDIT:
		edit.setIndex(index);
		edit.setTask(task);
		edit.setDisplayedTaskList(_displayedTaskList);
		command = edit;
		break;

	case DELETE:
		remove.setIndex(index);
		remove.setDisplayedTaskList(_displayedTaskList);
		command = remove;
		break;

	default:
		break;
	};

	return command;
}