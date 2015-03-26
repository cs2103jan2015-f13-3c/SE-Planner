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

//ADD, DISPLAY, EDIT, DELETE, SEARCH, UNDO
CommandType CommandParser::parse(){
	CommandType commandType = DISPLAY;//default cmd
	int numCommands = 0;

	if(searchForCreateCommand(_commandInput)){
	commandType = ADD;
	numCommands++;
	
	} else if(searchForEditCommand(_commandInput)){
	commandType = EDIT;
	numCommands++;
	
	} else if(searchForReadCommand(_commandInput)){
		commandType = DISPLAY;
	numCommands++;
	
	} else if(searchForDeleteCommand(_commandInput)){
	commandType = DELETE;
	numCommands++;
	
	} else if(searchForSearchCommand(_commandInput)){
		commandType = SEARCH;
	numCommands++;
	
	}else if(searchForSearchCommand(_commandInput)){
		commandType = EXIT_COMMAND;
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
bool CommandParser::searchForExitCommand(std::string sentence){
	if(sentence.find(EXIT_CMD) != std::string::npos){
		return true;
	}
	return false;
}

bool CommandParser::searchForSearchCommand(std::string sentence){
	if(sentence.find(SEARCH_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool CommandParser::searchForEditCommand(std::string sentence){
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
