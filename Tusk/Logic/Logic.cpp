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
	
	_parser.parseUserInput(userInput);
	
	commandType = _parser.getCommandType();
	
	createCommand(commandType);
	//_command.execute();

	return commandType;
}

void Logic::createCommand(CommandType commandType) {
	switch (commandType) {
	case ADD_CMD:
		createAddCommand();
		break;
	case DELETE_CMD:
		createDeleteCommand();
		break;
	case EDIT_CMD:
		createEditCommand();
		break;
	case DISPLAY_CMD:
		createDisplayCommand();
		break;
	case SEARCH_CMD:
		createSearchCommand();
		break;
	}
}

void Logic::createAddCommand() {
	Add add;
	add.setTask(_parser.getTask());

	add.execute();
	_result = add.getResult();
}

void Logic::createDeleteCommand() {
	Delete remove;
	remove.setInformation(_parser.getInformation());
	remove.setDisplayedTaskList(_result);

	remove.execute();
	_result = remove.getResult();
}

void Logic::createEditCommand() {
	Edit edit;
	edit.setTask(_parser.getTask());
	edit.setInformation(_parser.getInformation());
	edit.setDisplayedTaskList(_result);

	edit.execute();
	_result = edit.getResult();
}

void Logic::createDisplayCommand() {
	Display display;
	
	display.execute();
	_result = display.getResult();
}

void Logic::createSearchCommand() {
	Search search;
	search.setInformation(_parser.getInformation());

	search.execute();
	_result = search.getResult();
}


std::vector<Task> Logic::getResult() {
	//return _command.getResult();
	return _result;
}