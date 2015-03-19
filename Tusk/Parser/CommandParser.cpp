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

//ADD, DISPLAY, EDIT, DELETE, UNDO, SEARCH
CommandType CommandParser::parse(){
	CommandType commandType;
	int numCommands = 0;

	if(searchForCreateCommand(_commandInput)){
	commandType = ADD;
	numCommands++;
	
	} else if(searchForUpdateCommand(_commandInput)){
	commandType = EDIT;
	numCommands++;
	
	} else if(searchForReadCommand(_commandInput)){
		commandType = DISPLAY;
	numCommands++;
	
	} else if(searchForDeleteCommand(_commandInput)){
	commandType = DELETE;
	numCommands++;
	
	}
		
	//TODO: check that numCommands should be == 1
	return commandType;
}


bool CommandParser::searchForCreateCommand(std::string sentence){
	if(sentence.find(CREATE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool CommandParser::searchForUpdateCommand(std::string sentence){
	if(sentence.find(UPDATE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool CommandParser::searchForReadCommand(std::string sentence){
	if(sentence.find(READ_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool CommandParser::searchForDeleteCommand(std::string sentence){
	if(sentence.find(DELETE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
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
return trimLeadingSpaces(removeFirstWord(_commandInput));
}

CommandType CommandParser::getCommandType(){
return CommandParser::parse();
}
