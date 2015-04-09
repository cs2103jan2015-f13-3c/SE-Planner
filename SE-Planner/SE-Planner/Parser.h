#pragma once
#include "Common.h"
#include "Utility.h"

#include <string>
#include <iostream>

using namespace std;

class Parser
{
public:
	Parser(void);
	~Parser(void);

	Parser(string);
	Command getCommand(void);
	Task getTask(void);

	void trimString(string &);

	Utility utility;
};

