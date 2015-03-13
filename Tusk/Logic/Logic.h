#pragma once

#include "Command.h"
#include "Create.h"
#include "Read.h"
#include "Update.h"
#include "Delete.h"

class Logic {
private:
	std::string _inputedMessage;
	Command _command;
	Task _task;
	std::vector<Task> _mainTaskList;
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
	void setMainTaskList(std::vector<Task>);

	Command getCommand();
	Task getTask();
	std::vector<Task> getDisplayedTaskList();

	void executeCommand();
};