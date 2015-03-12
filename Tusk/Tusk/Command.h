#pragma once

#include <string>

class Command {
private:
	std::string _command;

public:
	Command(void);
	~Command(void);

	void inputCommand(std::string);

	std::string getCommand();
};