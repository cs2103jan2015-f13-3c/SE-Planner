#pragma once

#include "Common.h"
#include "Utility.h"
#include <vector>

using namespace std;

const int OPERATION_SUCCEEDED = 1;
const int OPERATION_FAILED = 0;
const int MAX_TASK_SIZE = 1000;

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
	vector<Task> Search(vector<Task> allTasks, Task searchedTask);
	vector<Task> Display(vector<Task> allTasks, Task displayedTaskDate, InstructionType instruction);
	vector<Task> Edit(vector<Task> allTasks, vector<Task> displayedTasks, int index, Task newTaskInfo);
	


	// sorting comparator for the displayedTaskList
	bool orderTask(Task,Task);

	// Tung
	vector<Task> Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);
};

