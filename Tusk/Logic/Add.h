#pragma once

#include <vector>
#include "Task.h"

class Add {
public:
	Add(void);
	~Add(void);

	void executeAddTask(std::vector<Task>&, Task);
};