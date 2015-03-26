#pragma once

#include "Parser.h"
#include "Command.h"

class Logic {
private:
	Parser _parser;
	Command _command;

	std::vector<Task> _displayTaskList;

	void createCommand(CommandType);
	void createAddCommand();
	void createDeleteCommand();
	void createEditCommand();
	void createDisplayCommand();

public:
	Logic(void);
	~Logic(void);

	CommandType executeUserInput(std::string);
};