#pragma once

#include <string>
#include "CommandTypeParser.h"
#include "TaskParser.h"
#include "InstructionParser.h"

class Parser {
private:
	CommandTypeParser _commandTypeParser;
	TaskParser _taskParser;
	InstructionParser _instructionParser;

public:
	Parser(void);
	~Parser(void);

	CommandType parseUserInput(std::string);
	Task getTask();
	std::string getInstruction();
};