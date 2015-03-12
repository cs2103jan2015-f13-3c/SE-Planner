#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "Task.h"
#include "Create.h"
#include "Read.h"
#include "Update.h"
#include "Delete.h"

class Logic {
private:
	std::string _inputedMessage;
	Command _command;
	std::vector<Task> _taskList;

public:
	Logic(void);
	~Logic(void);
};