#pragma once

#include "Command.h"

class Delete: public Command {
private:
	std::vector<Task> _displayedTaskList;
	int _index;

public:
	Delete(void);
	~Delete(void);

	void setDisplayedTaskList(std::vector<Task>);
	void setIndex(int);

	std::vector<Task> execute();
};