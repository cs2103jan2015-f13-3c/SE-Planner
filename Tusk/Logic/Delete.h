#pragma once

#include "Command.h"

class Delete: public Command {
private:
	std::vector<Task> _displayedTaskList;
	std::string _information;

public:
	Delete(void);
	~Delete(void);

	std::vector<Task> execute();
	void setDisplayedTaskList(std::vector<Task>);
	void setInformation(std::string);
};