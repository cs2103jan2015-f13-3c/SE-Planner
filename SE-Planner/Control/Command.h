#pragma once

#include "Storage.h"

class Command {
protected:
	Storage _storage;

public:
	Command(void);
	~Command(void);

	virtual void execute();
};