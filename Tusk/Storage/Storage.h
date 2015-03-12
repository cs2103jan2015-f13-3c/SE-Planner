#pragma once

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Storage {
public:
	Storage(void);
	~Storage(void);
	vector<Task> getAllTask();
};