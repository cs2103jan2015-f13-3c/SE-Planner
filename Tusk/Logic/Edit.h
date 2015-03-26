#pragma once

#include "Command.h"

class Edit: public Command {
private:
	std::vector<Task> _displayedTaskList;
	std::string _information;
	Task _task;

public:
	Edit(void);
	~Edit(void);

	std::vector<Task> execute();
	void setTask(Task);
	void setInformation(std::string);
	void setDisplayedTaskList(std::vector<Task>);
};