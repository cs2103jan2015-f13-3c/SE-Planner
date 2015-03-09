#pragma once
#include "parser.h"
class UserCommand :
	public Parser
{
public:
	UserCommand(void);
	UserCommand(string userInput);
	~UserCommand(void);
	bool readUserInput(void);
	void getUserCommand(void);
};

