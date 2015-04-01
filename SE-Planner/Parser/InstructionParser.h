#pragma once

#include <string>

class InstructionParser {
private:
	std::string _instruction;

public:
	InstructionParser(void);
	~InstructionParser(void);

	void parseInstruction(std::string);
	std::string getInstruction();
};