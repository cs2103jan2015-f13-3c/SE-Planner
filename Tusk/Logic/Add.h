#pragma once

#include "Command.h"

class Add: public Command {
private:
	Task _task;

public:
	Add(void);
	~Add(void);

	void setTask(Task);

	std::vector<Task> execute();
};