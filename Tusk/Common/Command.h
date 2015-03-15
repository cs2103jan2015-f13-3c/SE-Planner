#pragma once

enum CommandType {
	ERROR, ADD, DELETE, DISPLAY, EDIT, SEARCH, UNDO, REDO
};

class Command {
private:
	CommandType _commandType;

public:
	Command(void);
	~Command(void);

	void setCommandType(CommandType);
	inline CommandType getCommandType();
};