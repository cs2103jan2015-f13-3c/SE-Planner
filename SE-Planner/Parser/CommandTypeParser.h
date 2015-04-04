#pragma once

#include <string>

enum CommandType {
	ADD, REMOVE, EDIT, DISPLAY, SEARCH, MARK, UNDO, ERROR, EXIT
};

class CommandTypeParser {
private:
	CommandType _commandType;

public:
	CommandTypeParser(void);
	~CommandTypeParser(void);

	void setCommandType(CommandType);
	CommandType getCommandType();

	void parseCommandType(std::string);
};