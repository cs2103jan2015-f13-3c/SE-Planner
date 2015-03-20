#pragma once

#include "Task.h"
#include <vector>

class Edit {
public:
	Edit(void);
	~Edit(void);

	void executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task>& displayedTaskList);
};