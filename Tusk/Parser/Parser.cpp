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
	//createNewCommand(cmdParser.getCommandType());

	std::string newUserInput = cmdParser.getProcessedString();
	
	_command = cmdParser.getCommandType();

	log.write("commandParser ended");

	log.write("taskParser started with input:"+newUserInput);

	TaskParser taskParser (newUserInput);
	taskParser.parse();
	//createNewTask(taskParser.getTaskType());
	log.write("taskParser ended");
	_task = taskParser.getTask();

	log.end();
}

Task Parser::getTask(){
	return _task;
}

CommandType Parser::getCommandType(){
	return _command;
}


/*
void Parser::createNewCommand(CommandType extractedCommand){
	Command newCommand;
	newCommand.setCommandType(extractedCommand);
	return newCommand;
}
*/

/*
Task Parser::createNewTask(TaskType task, std::string extractedTaskInfo){
	Task newTask;
	newTask.setTaskType(task);
	newTask.setTitle(extractedTaskInfo);
	return newTask;
}
*/