#pragma once

#include "Command.h"
#include "Add.h"
#include "Read.h"
#include "Update.h"
#include "Delete.h"

class Logic: public Add, public Delete{
private:
	std::string _inputedCommand;
	Command _command;
	Task _task;
	std::vector<Task> _storedTaskList;
	std::vector<Task> _displayedTaskList;

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
	std::vector<Task> getMainTaskList();

	void executeCommand();
};