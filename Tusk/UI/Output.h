#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "Task.h"

class Output {
private:
	std::string _message;

public:
	Output(void);
	~Output(void);

	void outputMessage(Command, std::vector<Task>);
};