#pragma once

#include "Command.h"

class Display: public Command {

private:
	Task _task;

public:
	Display(void);
	~Display(void);

	void setTask(Task);

	std::vector<Task> execute();
};