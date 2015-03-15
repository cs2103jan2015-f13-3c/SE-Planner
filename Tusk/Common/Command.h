#pragma once

enum CommandType {
	ADD, DISPLAY, EDIT, DELETE, UNDO, REDO, SEARCH, ERROR
};

class Command {
private:
	CommandType _commandType;

public:
	Command(void);
	~Command(void);

	void setCommandType(CommandType);
	CommandType getCommandType();
};