#pragma once

#include "Command.h"

class Search: public Command {
public:
	Search(void);
	~Search(void);

	void execute();
};