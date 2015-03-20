#pragma once

#include "Command.h"

class Edit: public Command{
private:
	int _index;
	Task _task;
	std::vector<Task> _displayedTaskList;

public:
	Edit(void);
	~Edit(void);

	std::vector<Task> execute();

	void setIndex(int);
	void setTask(Task);
	void setDisplayedTaskList(std::vector<Task>);
};