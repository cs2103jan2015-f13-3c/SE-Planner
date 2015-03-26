#pragma once

#include "Command.h"

class CommandExecutor {
public:
	CommandExecutor(void);
	~CommandExecutor(void);

	std::vector<Task> executeCommand(Command);
};