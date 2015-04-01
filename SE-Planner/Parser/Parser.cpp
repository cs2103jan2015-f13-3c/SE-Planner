#include "Parser.h"

#include <iostream>
using namespace std;

Parser::Parser(void) {
}

Parser::~Parser(void) {
}

CommandType Parser::parseUserInput(std::string userInput) {
	CommandType commandType;

	//Obtain first word and input it to CommandTypeParser
	int firstSpacePos = userInput.find(" ");
	std::string firstWord = userInput.substr(0, firstSpacePos);
	_commandTypeParser.parseCommandType(firstWord);
	commandType = _commandTypeParser.getCommandType();

	//Obtain the remaining userInput
	std::string remainingUserInput = userInput.substr(firstSpacePos+1, userInput.size() - firstWord.size() - 1);

	//Parse task only if command is add
	if (commandType == ADD) {
		_taskParser.parseTask(remainingUserInput);

	//Parse task and instruction if command is edit
	} else if (commandType == EDIT) {
		//Obtain index and put into instructionParser;
		firstSpacePos = remainingUserInput.find(" ");
		std::string index = remainingUserInput.substr(0, firstSpacePos);
		_instructionParser.parseInstruction(remainingUserInput.substr(0, firstSpacePos));
		
		//Obtain updated task and put into taskParser;
		remainingUserInput = remainingUserInput.substr(firstSpacePos+1,remainingUserInput.size() - index.size());
		_taskParser.parseTask(remainingUserInput);

	//Else, parse instruction
	} else {
		_instructionParser.parseInstruction(remainingUserInput);
	}

	return commandType;
}

Task Parser::getTask() {
	return _taskParser.getTask();
}

std::string Parser::getInstruction() {
	return _instructionParser.getInstruction();
}