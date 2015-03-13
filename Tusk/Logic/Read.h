#pragma once

#include "Task.h"
#include <vector>

class Read {
public:
	Read(void);
	~Read(void);

	std::vector<Task> executeCommand(std::vector<Task>&, Task&);
};