#pragma once

#include <vector>
#include "Task.h"

class Create {
public:
	Create(void);
	~Create(void);

	void execute(std::vector<Task>&, Task);
};