#pragma once

#include <vector>
#include <iostream>

#include "Task.h"
#include "Command.h"

using namespace std;

class Storage {
public:
	Storage(void);
	~Storage(void);

	vector<Task> getAllTask();
	void writeToFile(vector<Task>);
};