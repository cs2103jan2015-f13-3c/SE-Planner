#pragma once

#include <iostream>
#include <string>
#include "Logic.h"

class UI {
private:
	Logic _logic;

	std::string inputUserCommand();
	void printResult(CommandType, std::vector<Task>);
	std::string taskToString(Task);
	std::string vectorTaskToString(std::vector<Task>);

public:
	UI(void);
	~UI(void);

	void run();
};