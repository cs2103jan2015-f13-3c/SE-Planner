#pragma once

#include <vector>
#include "Task.h"

class Delete {
public:
	Delete(void);
	~Delete(void);

	void executeDelete(std::vector<Task>&, Task&, std::vector<Task>);
};