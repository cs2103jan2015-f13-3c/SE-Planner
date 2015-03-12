#include "Parser.h"


Parser::Parser(void) {
}

Parser::~Parser(void) {
}



Command Parser::createNewCommand(CommandType extractedCommand){
	Command newCommand;
	newCommand.setCommandType(extractedCommand);
	return newCommand;
}

Task Parser::createNewTask(TaskType task, std::string extractedTaskInfo){
	Task newTask;
	newTask.setTaskType(task);
	newTask.setTitle(extractedTaskInfo);
	return newTask;
}
	

std::string removeFirstWord(std::string sentence){
	return sentence.substr(sentence.find(" "), sentence.length());
}

std::string removeKeyword(std::string s){
	size_t pos = 0;
	std::string delimiter = "/";
	std::string token;
	std::string processedString;


	while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
	
	processedString += token;
    s.erase(0, pos + delimiter.length());
	pos = s.find(" ");
	s.erase(0, pos + delimiter.length());
	}

	return processedString;
}

std::string getKeyword(std::string s){
	return s.substr(s.find("/"), s.find(" "));

}

std::string Parser::processString(std::string s){
	std::string processedString = "";
	std::string keyword;
	
	s = removeFirstWord(s);

	keyword = getKeyword(s);
	
	s = removeKeyword(s);

	processedString = s;

	return processedString;
}

// TaskTypes: /d /t /r + FloatingTask
TaskType Parser::findTaskType(std::string input){
	TaskType userTaskType = FloatingTask;

	if(input.find("/d") != std::string::npos){
		userTaskType = Deadline;
	} else if(input.find("/t") != std::string::npos){
		userTaskType = TimedTask;
	} else if(input.find("/r") != std::string::npos){
		userTaskType = RecurringTask;
	}

return userTaskType;
}

std::pair <TaskType, std::string> Parser::extractTaskFromInput(std::string userInput){
	
	std::pair <TaskType, std::string> taskPair;

	taskPair.first = findTaskType(userInput);
	taskPair.second = processString(userInput);
	
	return taskPair;
}


bool searchForCreateCommand(std::string input){
	if(input.find(CREATE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool searchForUpdateCommand(std::string input){
	if(input.find(UPDATE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool searchForReadCommand(std::string input){
	if(input.find(READ_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}

bool searchForDeleteCommand(std::string input){
	if(input.find(DELETE_COMMAND) != std::string::npos){
		return true;
	}
	return false;
}




//	commands to search for /r : remove
//	/u : update
//	/c : create
//	/v : read
CommandType Parser::extractCommandFromInput(std::string input){
	CommandType commandType;
	int numCommands = 0;

	if(searchForCreateCommand(input)){
	commandType = Create;
	numCommands++;
	
	} else if(searchForUpdateCommand(input)){
	commandType = Update;
	numCommands++;
	
	} else if(searchForReadCommand(input)){
	commandType = Read;
	numCommands++;
	
	} else if(searchForDeleteCommand(input)){
	commandType = Delete;
	numCommands++;
	
	}
	
	//TODO: numCommands should be == 1
	return commandType;
}

std::pair <Command, Task> Parser::parseUserInput(std::string userInput){
	std::pair<Command, Task> commandAndTask;
	
	CommandType extractedCommand = extractCommandFromInput(userInput);
	
	std::string extractedTaskInfo="";
	std::pair<TaskType, std::string> taskPair = extractTaskFromInput(userInput);
	
	_task = createNewTask(taskPair.first,taskPair.second);
	_command = createNewCommand(extractedCommand);

	commandAndTask.first = _command;
	commandAndTask.second = _task;

	return commandAndTask;
}

Command Parser::getCommand(){
	return _command;
}

Task Parser::getTask(){
	return _task;
}
