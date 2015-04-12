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

	Storage(string);

	// IMPORTANT API
	vector<Task> getAllTask(void);
	void writeToFile(vector<Task>);
	bool setOutputFilePath(string filePath);
	string getOutputFilePath();

private:
	// STORAGE-SPECIFIC
	Utility utility;
	string outputFile;
	

};

