#pragma once
//#include "Definition.h"
#include <string>


const std::string CREATE_COMMAND = "add";
const std::string UPDATE_COMMAND = "edit";
const std::string READ_COMMAND = "display";
const std::string DELETE_COMMAND = "delete";

enum CommandType{
ADD, DISPLAY, EDIT, DELETE, UNDO, SEARCH
};

std::string _commandInput;

class CommandParser
{
public:
	CommandParser(void);
	CommandParser(std::string);
	
	CommandType parse();
	CommandType parse(std::string);
	
	CommandType getCommandType();
	std::string getProcessedString();

private:

	bool searchForCreateCommand(std::string);
	bool searchForReadCommand(std::string);
	bool searchForUpdateCommand(std::string);
	bool searchForDeleteCommand(std::string);

	std::string trimLeadingSpaces(std::string);
	std::string removeFirstWord(std::string);
};

