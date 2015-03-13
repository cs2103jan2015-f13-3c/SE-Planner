#pragma once

#include "Task.h"
#include <vector>

class Update {
public:
	Update(void);
	~Update(void);

	void executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task>& displayedTaskList);
};