#include "CommandTypeParser.h"

CommandTypeParser::CommandTypeParser(void) {
}

CommandTypeParser::~CommandTypeParser(void) {
}

//Take in a string of one word and convert it to commandType
void CommandTypeParser::parseCommandType(std::string commandType) {
	if (commandType == "add") {
		_commandType = ADD;
	} else if (commandType == "remove") {
		_commandType = REMOVE;
	} else if (commandType == "edit") {
		_commandType = EDIT;
	} else if (commandType == "display") {
		_commandType = DISPLAY;
	} else if (commandType == "search") {
		_commandType = SEARCH;
	} else if (commandType == "undo") {
		_commandType = UNDO;
	} else if (commandType == "done") {
		_commandType = DONE;
	} else if (commandType == "exit") {
		_commandType = EXIT;
	} else {
		_commandType = INVALID;
	}
}

CommandType CommandTypeParser::getCommandType() {
	return _commandType;
}