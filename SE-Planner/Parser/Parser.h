#pragma once

#include <string>
#include "CommandTypeParser.h"
#include "TaskParser.h"
#include "DisplayTypeParser.h"

class Parser {
private:
	CommandTypeParser _commandTypeParser;
	TaskParser _taskParser;
	DisplayTypeParser _displayTypeParser;
	std::string _instruction;

public:
	Parser(void);
	~Parser(void);

	CommandType parseUserInput(std::string);

	Task getTask();
	DisplayType getDisplayType();
	Date getSpecificDateForDisplay();
	std::string getInstruction();
};