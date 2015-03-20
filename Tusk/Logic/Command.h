#pragma once

//Abstract Class

#include "Storage.h"

class Command {
protected:
	Storage _storage;
	std::vector<Task> _result;

public:
	Command(void);
	~Command(void);

	virtual std::vector<Task> execute();
};