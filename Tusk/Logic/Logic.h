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
	Task _task;
	std::vector<Task> _displayedTaskList;

	Create _create;
	Read _read;
	Update _update;
	Delete _delete;

public:
	Logic(void);
	~Logic(void);

	void setInpuedMessage(std::string);
	void setCommand(Command);
	void setTask(Task);

	void executeCommand(Command, std::vector<Task>);
};