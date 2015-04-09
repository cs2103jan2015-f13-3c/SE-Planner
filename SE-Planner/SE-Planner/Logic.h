#pragma once

#include "Common.h"
#include "Utility.h"
#include <vector>

using namespace std;

class Logic
{
public:
	Logic(void);
	~Logic(void);

	// utility class
	Utility utility;

	// was the command execution succesful or not
	int success;
	
	// WEIMIN
	vector<Task> Add(vector<Task> allTask, Task addTask);
	vector<Task> Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);
	vector<Task> Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);

	// YOONG ZHEN
	vector<Task> Search(vector<Task> allTask, Task searchTask);
	vector<Task> Display(vector<Task> allTask, Task displayTask, InstructionType instruction);
	vector<Task> Edit(vector<Task> allTask, vector<Task> displayedTask, int index, Task editTask);
	


	// sorting comparator for the displayedTaskList
	bool orderTask(Task,Task);
};

