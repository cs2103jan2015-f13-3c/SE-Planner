#pragma once

#include <string>

enum CommandType {
	ADD, REMOVE, EDIT, DISPLAY, SEARCH, UNDO, DONE, EXIT, INVALID
};

class CommandTypeParser {
private:
	CommandType _commandType;

public:
	CommandTypeParser(void);
	~CommandTypeParser(void);

	void parseCommandType(std::string);
	CommandType getCommandType();
};