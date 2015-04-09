#pragma once

#include "Common.h"
#include <vector>

using namespace std;

class Storage
{
public:
	Storage(void);
	~Storage(void);

	string outputFile;

	Storage(string);

	vector<Task> getAllTask(void);
	void writeToFile(vector<Task>);

};

