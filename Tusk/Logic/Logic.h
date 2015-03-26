#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "CommandType.h"
#include "Task.h"
#include "Parser.h"

class Logic {
private:
	Command _command;
	Parser _parser;

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
	std::vector<Task> getResult();
};