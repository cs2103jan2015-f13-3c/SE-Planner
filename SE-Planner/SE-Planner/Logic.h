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

	// IMPORTANT API
	vector<Task> Add(vector<Task> allTask, Task addTask);
	vector<Task> Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);
	vector<Task> Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);
	std::vector<Task> search(std::vector<Task>, Task);
	vector<Task> Display(vector<Task> allTasks, Task displayedTaskDate, InstructionType instruction);
	vector<Task> Edit(vector<Task> allTasks, vector<Task> displayedTasks, int index, Task newTaskInfo);
	vector<Task> Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);

	// was the command execution succesful or not
	int success;

private:
	Utility utility;

	// sorting comparator for the displayedTaskList
	bool orderTask(Task,Task);

//@author A0108417J
public:
	//search function's sub-functions
	bool isTaskValid(Task);
	std::vector<Task> findMatchedTasks(std::vector<Task>, Task);
	bool isTaskMatch(Task, Task);
	
};

