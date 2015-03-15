#pragma once

#include <vector>
#include "Task.h"

class Add {
public:
	Add(void);
	~Add(void);

	void executeAdd(std::vector<Task>&, Task);
};