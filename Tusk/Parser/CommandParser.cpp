#include "CommandParser.h"

CommandParser::CommandParser(std::string input){
	_commandInput = input;
}

CommandParser::CommandParser(void){
}


//***1. command processing methods ***
CommandType CommandParser::parse(std::string input){
	_commandInput = input;
	return parse();
}

//available enum commandTypes: ADD, DISPLAY, EDIT, DELETE, SEARCH, UNDO
CommandType CommandParser::parse(){
	CommandType commandType = DISPLAY_CMD;//default cmdType
	int numCommands = 0;

	if(searchForCreateCommand(_commandInput)){
		commandType = ADD_CMD;
		numCommands++;

	} else if(searchForEditCommand(_commandInput)){
		commandType = EDIT_CMD;
		numCommands++;

	} else if(searchForReadCommand(_commandInput)){
		commandType = DISPLAY_CMD;
		numCommands++;

	} else if(searchForDeleteCommand(_commandInput)){
		commandType = DELETE_CMD;
		numCommands++;

	} else if(searchForSearchCommand(_commandInput)){
		commandType = SEARCH_CMD;
		numCommands++;

	}else if(searchForSearchCommand(_commandInput)){
		commandType = EXIT_CMD;
		numCommands++;

	}
	//_ASSERT(numCommands == 1);

	return commandType;
}

bool CommandParser::searchForCreateCommand(std::string sentence){
	return (sentence.find(CREATE_COMMAND) != std::string::npos);
}

bool CommandParser::searchForExitCommand(std::string sentence){
	return (sentence.find(EXIT_COMMAND) != std::string::npos);
}

bool CommandParser::searchForSearchCommand(std::string sentence){
	return (sentence.find(SEARCH_COMMAND) != std::string::npos);
}

bool CommandParser::searchForEditCommand(std::string sentence){
	return (sentence.find(UPDATE_COMMAND) != std::string::npos);
}

bool CommandParser::searchForReadCommand(std::string sentence){
	return (sentence.find(READ_COMMAND) != std::string::npos);
}

bool CommandParser::searchForDeleteCommand(std::string sentence){
	return (sentence.find(DELETE_COMMAND) != std::string::npos);
}

std::string CommandParser::removeFirstWord(std::string sentence){
	return sentence.substr(sentence.find(" "), sentence.length());
}

std::string CommandParser::trimLeadingSpaces(std::string sentence){
	size_t pos = sentence.find_first_not_of(" \t");
	sentence.erase(0, pos);
	return sentence;
}

//*** Accessors
std::string CommandParser::getProcessedString(){
	if(getCommandType() == DISPLAY_CMD){
		return " ";
	}
	return trimLeadingSpaces(removeFirstWord(_commandInput));
}

CommandType CommandParser::getCommandType(){
	return CommandParser::parse();
}
