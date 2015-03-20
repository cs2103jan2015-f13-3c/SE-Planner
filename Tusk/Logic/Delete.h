#pragma once

#include "Command.h"

class Delete: public Command {
private:
	int _index;
	std::vector<Task> _displayedTaskList;

public:
	Delete(void);
	~Delete(void);

	std::vector<Task> execute();

	void setIndex(int);
	void setDisplayedTaskList(std::vector<Task>);
};