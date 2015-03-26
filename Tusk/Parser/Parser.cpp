#include "Parser.h"

Parser::Parser(void) {
}

Parser::~Parser(void) {
}

//std::pair <Command, Task> Parser::parseUserInput(std::string userInput){
void Parser::parseUserInput(std::string userInput){
	ParserLog log;
	
	log.start();

	log.write("commandParser started with input:"+userInput);

	CommandParser cmdParser (userInput);
	cmdParser.parse();

	std::string newUserInput = cmdParser.getProcessedString();
	
	_command = cmdParser.getCommandType();
	bool hasIndex=false;
	if(_command == EDIT ||_command == SEARCH){
	hasIndex = true;
	}
	log.write("commandParser ended");

	log.write("taskParser started with input:"+newUserInput);

	TaskParser taskParser (newUserInput,hasIndex);
	taskParser.parse();
	
	log.write("taskParser ended");
	
	_task = taskParser.getTask();
	_index = taskParser.getTaskIndex();
	log.end();
}

Task Parser::getTask(){
	return _task;
}

CommandType Parser::getCommandType(){
	return _command;
}

std::string Parser::getInformation(){
	return _index;
}
