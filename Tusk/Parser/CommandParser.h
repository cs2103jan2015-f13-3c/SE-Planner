#pragma once
#include <string>


const std::string CREATE_COMMAND = "add";
const std::string UPDATE_COMMAND = "edit";
const std::string READ_COMMAND = "display";
const std::string DELETE_COMMAND = "delete";
const std::string SEARCH_COMMAND = "search";
const std::string EXIT_CMD = "exit";


enum CommandType{
ADD, DISPLAY, EDIT, DELETE, UNDO, SEARCH, EXIT_COMMAND
};


class CommandParser{
public:
	std::string _commandInput;

	CommandParser(void);
	CommandParser(std::string);
	
	CommandType parse();
	CommandType parse(std::string);
	
	CommandType getCommandType();
	std::string getProcessedString();

private:

	bool searchForCreateCommand(std::string);
	bool searchForReadCommand(std::string);
	bool searchForEditCommand(std::string);
	bool searchForDeleteCommand(std::string);
	bool searchForSearchCommand(std::string);
	bool searchForExitCommand(std::string);

	std::string trimLeadingSpaces(std::string);
	std::string removeFirstWord(std::string);
};

