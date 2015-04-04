#include "Parser.h"

Parser::Parser(void) {
}

Parser::~Parser(void) {
}

CommandType Parser::parseUserInput(std::string userInput) {
	CommandType commandType;

	bool executionResult;

	//Obtain first word and input it to CommandTypeParser
	int firstSpacePos = userInput.find(" ");
	std::string firstWord = userInput.substr(0, firstSpacePos);
	_commandTypeParser.parseCommandType(firstWord);
	commandType = _commandTypeParser.getCommandType();

	//Obtain the remaining userInput
	std::string remainingUserInput = userInput.substr(firstSpacePos + 1, userInput.size() - firstWord.size() - 1);

	//Parse task only if command is add
	if (commandType == ADD) {
		executionResult = _taskParser.parseTask(remainingUserInput);

		if (!executionResult) {
			_commandTypeParser.setCommandType(ERROR);
		}

	//Parse task and instruction if command is edit
	} else if (commandType == EDIT) {
		//Obtain index and put into instructionParser;
		firstSpacePos = remainingUserInput.find(" ");
		std::string index = remainingUserInput.substr(0, firstSpacePos);
		_instruction = remainingUserInput.substr(0, firstSpacePos);
		
		//Obtain updated task and put into taskParser;
		remainingUserInput = remainingUserInput.substr(firstSpacePos+1,remainingUserInput.size() - index.size());
		executionResult = _taskParser.parseTask(remainingUserInput);

		if (!executionResult) {
			_commandTypeParser.setCommandType(ERROR);
		}

	} else if (commandType == DISPLAY) {
		executionResult = _displayTypeParser.parseDisplayType(remainingUserInput);

		if (!executionResult) {
			_commandTypeParser.setCommandType(ERROR);
		}

	//Else, parse instruction
	} else {
		_instruction = remainingUserInput;
	}

	return commandType;
}

Task Parser::getTask() {
	return _taskParser.getTask();
}

DisplayType Parser::getDisplayType() {
	return _displayTypeParser.getDisplayType();
}
Date Parser::getSpecificDateForDisplay() {
	return _displayTypeParser.getSpecificDate();
}

std::string Parser::getInstruction() {
	return _instruction;
}