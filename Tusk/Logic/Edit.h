#pragma once

#include "Command.h"

class Edit: public Command{
private:
	std::vector<Task> _displayedTaskList;
	int _index;
	Task _task;

public:
	Edit(void);
	~Edit(void);

	void setDisplayedTaskList(std::vector<Task>);
	void setIndex(int);
	void setTask(Task);

	std::vector<Task> execute();
};