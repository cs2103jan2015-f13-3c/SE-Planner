#include "InstructionParser.h"

InstructionParser::InstructionParser(void) {
}

InstructionParser::~InstructionParser(void) {
}

//Take in a string that can be an index or a word or multiple words
//and convert it to instruction
void InstructionParser::parseInstruction(std::string instruction) {
	_instruction = instruction;
}

std::string InstructionParser::getInstruction() {
	return _instruction;
}