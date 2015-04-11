#pragma once
#include "Common.h"
#include "Utility.h"

#include <string>
#include <iostream>

using namespace std;

const string COMMAND_ADD		= "add";
const string COMMAND_SEARCH		= "search";
const string COMMAND_DISPLAY	= "display";
const string COMMAND_DELETE		= "delete";
const string COMMAND_EDIT		= "edit";
const string COMMAND_DONE		= "done";
const string COMMAND_UNDO		= "undo";
const string COMMAND_EXIT		= "exit";
const string COMMAND_CLS		= "cls";
const string COMMAND_HELP		= "help";
const string COMMAND_UNDONE		= "undone";
const string COMMAND_WHERE		= "where";
const string COMMAND_USE		= "use";

class Parser
{
public:
	Parser(void);
	~Parser(void);

	// IMPORTANT API
	Parser(string);
	Command getCommand(void);
	Task getTask(void);


	// PARSER-SPECIFIC
	void extractDisplayInfo(string);
	void trimString(string &);
	void assumeInfo(void);
	Utility utility;
};

