#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "Task.h"

const std::string MESSAGE_CREATED = "[Created] ";
const std::string MESSAGE_DISPLAY = "[Display]\n";
const std::string MESSAGE_UPDATED = "[Update] ";
const std::string MESSAGE_DELETED = "[DELETED] ";

class Output {
private:
	std::string _message;

public:
	Output(void);
	~Output(void);

	void setMessage(Command, Task, std::vector<Task>);
	std::string getMessage();
};