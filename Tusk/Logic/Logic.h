#pragma once

#include "Parser.h"
#include "CommandExecutor.h"

class Logic {
private:
	Parser _parser;
	CommandExecutor _commandExecutor;
	std::vector<Task> _displayedTaskList;

	Command createCommand(CommandType);

public:
	Logic(void);
	~Logic(void);

	void executeUserInput(std::string);
};