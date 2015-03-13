#pragma once

#include <vector>
#include "Task.h"

class Create {
public:
	Create(void);
	~Create(void);

	void executeCommand(std::vector<Task>&, Task);
};