#pragma once

#include <string>
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
	Task _taskList;

public:
	Logic(void);
	~Logic(void);
};