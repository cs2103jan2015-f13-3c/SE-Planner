#pragma once

#include "Command.h"

class Add: public Command {
public:
	Add(void);
	~Add(void);

	void execute();
};