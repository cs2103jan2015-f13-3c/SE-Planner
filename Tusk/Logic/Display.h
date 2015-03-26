#pragma once

#include "command.h"

class Display: public Command {
public:
	Display(void);
	~Display(void);

	std::vector<Task> execute();
};