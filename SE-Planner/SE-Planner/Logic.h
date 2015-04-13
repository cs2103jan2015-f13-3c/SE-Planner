//@author A0116724J
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

	//@author A0108393A
	vector<Task> Add(vector<Task> allTask, Task addTask);
	vector<Task> Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);
	vector<Task> Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);

	//@author A0108417J
	std::vector<Task> search(std::vector<Task>, Task);
	vector<Task> display(vector<Task>, Task, InstructionType);
	std::vector<Task> edit(std::vector<Task>, std::vector<Task>, int, Task);

	//@author A0116724J
	vector<Task> Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index);

	// was the command execution succesful or not
	int success;

private:
	Utility utility;

	// sorting comparator for the displayedTaskList
	bool orderTask(Task,Task);

//@author A0108417J
//Contains sub-functions of search, edit and display
//Uncomment public for unit testing
public:
	//search function's sub-functions
	bool isTaskValid(Task);
	std::vector<Task> findMatchedTasks(std::vector<Task>, Task);
	bool isTaskMatch(Task, Task);
	
	//edit function's sub-functions
	bool isInputValid(std::vector<Task>, int, Task);
	bool isIndexValid(std::vector<Task>, int);
	bool isTaskTypeValid(Task, Task);
	std::vector<Task> updateAllTasks(vector<Task>, Task, Task);
	Task updateTask(Task, Task);

	//display function's sub-function
	Date getTodayDate();
	Date getTmrDate();
	Date getSpecificDate(Task);
	std::vector<Task> findDoneTasks(std::vector<Task>);
	std::vector<Task> findUndoneTasks(std::vector<Task>);
	std::vector<Task> findOverdueTasks(std::vector<Task>);
	std::vector<Task> findTodayTasks(std::vector<Task>);
	std::vector<Task> findTmrTasks(std::vector<Task>);
	std::vector<Task> findSpecificDateTasks(std::vector<Task>, Task);
};