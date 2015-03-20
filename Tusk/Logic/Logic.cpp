#include "Add.h"
#include "Display.h"
#include "Edit.h"
#include "Delete.h"
#include "Logic.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

void Logic::executeUserInput(std::string userInput) {
	_parser.parseUserInput(userInput);

	CommandType commandType;
	commandType = _parser.getCommandType();

	Command command;
	command = createCommand(commandType);

	std::vector<Task> result;
	result = _commandExecutor.executeCommand(command);
}

Command Logic::createCommand(CommandType commandType) {
	Command command;

	Add add;
	Display display;
	Edit edit;
	Delete remove;

	Task task;
	int index;
	std::string description;

	task = _parser.getTask();
	index = _parser.getIndex();
	description = _parser.getDescription();

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