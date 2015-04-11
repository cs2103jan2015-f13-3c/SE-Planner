#pragma once

#include "Common.h"
#include "Utility.h"

#include <vector>

using namespace std;

const string SETTING_FILE = "setting.txt";
const string OUTPUT_FILENAME = "task.txt";

class Storage
{
public:
	Storage(void);
	~Storage(void);

	string outputFile;

	Storage(string);

	vector<Task> getAllTask(void);
	void writeToFile(vector<Task>);

	Utility utility;

	bool setOutputFilePath(string filePath);
	string getOutputFilePath();

};

