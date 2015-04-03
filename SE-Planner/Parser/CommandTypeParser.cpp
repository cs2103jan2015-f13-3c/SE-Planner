#include "CommandTypeParser.h"

CommandTypeParser::CommandTypeParser(void) {
}

CommandTypeParser::~CommandTypeParser(void) {
}

void CommandTypeParser::setCommandType(CommandType commandType) {
	_commandType = commandType;
}

CommandType CommandTypeParser::getCommandType() {
	return _commandType;
}

void CommandTypeParser::parseCommandType(std::string commandInput) {
	if (commandInput == "add") {
		_commandType = ADD;
	} else if (commandInput == "delete") {
		_commandType = DELETE;
	} else if (commandInput == "edit") {
		_commandType = EDIT;
	} else if (commandInput == "display") {
		_commandType = DISPLAY;
	} else if (commandInput == "search") {
		_commandType = SEARCH;
	} else if (commandInput == "mark") {
		_commandType = MARK;
	} else if (commandInput == "undo") {
		_commandType = UNDO;
	} else {
		_commandType = ERROR;
	}
}