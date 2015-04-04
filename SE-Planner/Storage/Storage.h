#pragma once

#include <vector>
#include <iostream>

#include "../Common/Task.h"
//#include "Command.h"
//#include "../Parser/CommandParser.h"
using namespace std;

class Storage {
public:
	Storage(void);
	~Storage(void);

	vector<Task> getAllTask();
	void writeToFile(vector<Task>);
};