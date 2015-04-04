#pragma once

#include "Command.h"

class Edit:	public Command {
public:
	Edit(void);
	~Edit(void);

	void execute();
};