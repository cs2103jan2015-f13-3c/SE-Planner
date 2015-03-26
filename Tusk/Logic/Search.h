#pragma once

#include "Task.h"
#include <vector>

class Search {
public:
	Search(void);
	~Search(void);

	std::vector<Task> executeCommand(std::vector<Task>&, Task&);
};