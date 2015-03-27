#pragma once

#include <string>
#include <vector>
#include "../Storage/Storage.h"
#include "../Common/Task.h"

class Command {
protected:
	Task _task;
	std::string _information;
	std::vector<Task> _displayedTaskList;
	
	Storage _storage;
	std::vector<Task> _result;

public:
	Command(void);
	~Command(void);

	void setTask(Task);
	void setInformation(std::string);
	void setDisplayedTaskList(std::vector<Task>);

	std::vector<Task> getResult();

	virtual void execute();
};