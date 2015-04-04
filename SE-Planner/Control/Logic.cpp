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
	//_command.execute();

	return commandType;
}

void Logic::createCommand(CommandType commandType) {
	switch (commandType) {
	case ADD:
		createAddCommand();
		break;
	case REMOVE:
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
	remove.setInformation(_parser.getInstruction());
	remove.setDisplayedTaskList(_result);

	remove.execute();
	_result = remove.getResult();
}

void Logic::createEditCommand() {
	Edit edit;
	edit.setTask(_parser.getTask());
	edit.setInformation(_parser.getInstruction());
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
	search.setInformation(_parser.getInstruction());

	search.execute();
	_result = search.getResult();
}


std::vector<Task> Logic::getResult() {
	//return _command.getResult();
	return _result;
}