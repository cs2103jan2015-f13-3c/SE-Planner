#pragma once

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Parser {
public:
	Parser(void);
	~Parser(void);
	vector<Task> getAllTask();
};