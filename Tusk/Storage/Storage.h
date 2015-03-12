#pragma once

#include <iostream>
#include <vector>
#include "Task.h"
#include "Command.h"

using namespace std;

class Storage {
public:
	Storage(void);
	~Storage(void);

	vector<Task> getAllTask();
	void writeToFile(vector<Task> TaskVector);
};