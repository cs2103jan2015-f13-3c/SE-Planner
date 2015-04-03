#include "CommandTypeParser.h"

const std::string COMMAND_ADD = "add";
const std::string COMMAND_DELETE = "delete";
const std::string COMMAND_EDIT = "edit";
const std::string COMMAND_DISPLAY = "display";
const std::string COMMAND_SEARCH = "search";
const std::string COMMAND_MARK = "mark";
const std::string COMMAND_UNDO = "undo";

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
	if (commandInput == COMMAND_ADD) {
		_commandType = ADD;
	} else if (commandInput == COMMAND_DELETE) {
		_commandType = DELETE;
	} else if (commandInput == COMMAND_EDIT) {
		_commandType = EDIT;
	} else if (commandInput == COMMAND_DISPLAY) {
		_commandType = DISPLAY;
	} else if (commandInput == COMMAND_SEARCH) {
		_commandType = SEARCH;
	} else if (commandInput == COMMAND_MARK) {
		_commandType = MARK;
	} else if (commandInput == COMMAND_UNDO) {
		_commandType = UNDO;
	} else {
		_commandType = ERROR;
	}
}