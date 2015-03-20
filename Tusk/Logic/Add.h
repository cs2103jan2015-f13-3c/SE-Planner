#pragma once

#include "Command.h"

class Add: public Command {
private:
	Task _task;

public:
	Add(void);
	~Add(void);

	std::vector<Task> execute();

	void setTask(Task);
};