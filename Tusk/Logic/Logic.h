#pragma once

#include "Parser.h"
#include "Command.h"

class Logic {
private:
	Parser _parser;
	Command _command;

	std::vector<Task> _displayTaskList;
	std::vector<Task> _result;

	void createCommand(CommandType);
	void createAddCommand();
	void createDeleteCommand();
	void createEditCommand();
	void createDisplayCommand();
	void createSearchCommand();

public:
	Logic(void);
	~Logic(void);

	CommandType executeUserInput(std::string);
};