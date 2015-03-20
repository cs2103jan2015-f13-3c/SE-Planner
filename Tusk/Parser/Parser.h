//Authored by Lee Wei Min
//
//Pre-condition: Input must be be in string format with correct keywords 
//
//
//
//Post-condition: get methods will be used to return processed input
//
//
//Sample usage:
//		Parser parser;
//		
//		parser.parseUserInput(input);	
//
//		parser.getCommandType();
//		parser.getTaskType();
//		parser.getTaskTitle();

#pragma once
#include "CommandParser.h"
#include "TaskParser.h"
#include "ParserLog.h"




// available TaskTypes:
// FLOATINGTASK(add [])									+default
// DEADLINE(add [] 1. date time 2. date)						+date
// TIMEDTASK(add [] 1. date: time: []-[] 2. date: []-[] time: []-[] )			+time_range
// RECURRINGTASK (add [] 1. date: [],[],[] Time: []-[] 2. date: time: []-[] )		+DMY

// available CommandTypes:
// CREATE, READ, UPDATE, DELETE
// TODO: commandTypes header not updated

class Parser {

private:
	void createNewCommand(CommandType);

public:
	Parser(void);
	~Parser(void);

	void parseUserInput(std::string);

};
