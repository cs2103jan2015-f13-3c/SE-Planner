#pragma once

enum CommandType {
	ADD, DISPLAY, EDIT, DELETE, UNDO, REDO, SEARCH, ERROR
};

class Command {
private:
	CommandType _commandType;
	int _index;

public:
	Command(void);
	~Command(void);

	void setCommandType(CommandType);
	void setIndex(int);

	CommandType getCommandType();
	int getIndx();
};