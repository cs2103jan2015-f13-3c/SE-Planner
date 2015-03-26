#pragma once

#include "Command.h"

class Delete: public Command {
public:
	Delete(void);
	~Delete(void);

	void execute();
};