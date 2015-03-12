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

	Create _create;
	Read _read;
	Update _update;
	Delete _delete;

public:
	Logic(void);
	~Logic(void);
};