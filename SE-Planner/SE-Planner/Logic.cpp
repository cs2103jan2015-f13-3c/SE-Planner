#include "Logic.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <functional> 

using namespace std;


Logic::Logic(void)
{
	Utility utility;
}


Logic::~Logic(void)
{
}

// WEIMIN
vector<Task> Logic::Add(vector<Task> allTask, Task addTask)
{
	
	if (addTask.taskType == NUL)
	{
		success = 0;
		return allTask;
	}
	else
	{
		success = 1;

		vector<Task> temp = allTask;
		temp.push_back(addTask);
		return temp;
	}
}

// WEIMIN
vector<Task> Logic::Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	// if there is no index instruction -> fail command
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	// if any index exceeds the size of display Task List -> fail command
	for (int j = 0; j < index.size(); j++)
	{
		//cout<<index[j]<<endl;
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}


	success = 1;

	// 'marked' array for allTask
	// meaning : false = this task will NOT be deleted
	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	// mark the task to be deleted inside the mainTaskList
	for (int j = 0; j < index.size(); j++)
	{
		
		success = 1;

		Task deleteTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],deleteTask)) 
			{
				marked[i] = true; // THIS TASK WILL BE DELETED
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		// DELETE ACCORDINGLY
		if (!marked[i]) temp.push_back(allTask[i]);
	}

	return temp;

}

// WEIMIN
vector<Task> Logic::Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	
	// Logic similar to Done
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	for (int j = 0; j < index.size(); j++)
	{
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}

	success = 1;

	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++)
	{
		
		success = 1;

		Task doneTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],doneTask)) 
			{
				marked[i] = true;
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		temp.push_back(allTask[i]);
		if (marked[i]) temp[i].isDone = true;
		//cout<<i<<" "<<temp[i].isDone<<endl;
	}

	return temp;

}

//Search function's sub-functions
bool isSearchedTaskValid(Task searchedTask) {
	if (searchedTask.taskType != NUL) {
		return true;
	} else {
		return false;
	}
}

bool isSearchedTaskMatch(Task task, Task searchedTask) {
	Utility utility;
	bool isTitleMatch = utility.compareTitle(task, searchedTask);
	bool isDateMatch = utility.compareDate(task, searchedTask);
	bool isTimeMatch = utility.compareTime(task, searchedTask);

	if (isTitleMatch && isDateMatch && isTimeMatch) {
		return true;
	} else {
		return false;
	}
}

vector<Task> findAllMatchedTasks(vector<Task> allTasks, Task searchedTask) {
	vector<Task> matchedTasks;

	for (int i = 0; i < allTasks.size(); i++) {
		if (isSearchedTaskMatch(allTasks[i], searchedTask)) {
			matchedTasks.push_back(allTasks[i]);
		}
	}

	return matchedTasks;
}

//Main search function
vector<Task> Logic::Search(vector<Task> allTasks, Task searchedTask) {
	vector<Task> matchedTasks;

	if (isSearchedTaskValid(searchedTask)) {
		matchedTasks = findAllMatchedTasks(allTasks, searchedTask);
	}

	return matchedTasks;
}

// YOONG ZHEN
// THIS IS THE COMPARATOR FOR THE SORT FUNCTION OF THE DISPLAY COMMAND. 
// FLOAT AT BOTTOM, THEN SORT BY ENDING DATE, BY TIME, THEN BY NAME
// orderTask(t1, t2) = true IF t1 shows before t2 when displayed
// that is t1 < t2

bool Logic::orderTask(Task t1, Task t2)
{
	if (t1.taskType == t2.taskType)
	{
		// SAME TASK TYPE
		if (t1.taskType == FLOATTASK)
		{
			// FLOAT BOTTOM
			return (t1.title.compare(t2.title) < 0);
		}
		else
		{
			// SAME END DATE
			if (utility.isEqual(t1.endDate,t2.endDate))
			{
				// COMPARE TIME
				if (!utility.isEqual(t1.endTime,t2.endTime))
				{
					return (utility.isLaterTime(t1.endTime,t2.endTime));
				}
				else return (t1.title.compare(t2.title) < 0);
			}
			else return (utility.isLaterDate(t1.endDate,t2.endDate));
		}
	}
	else
	{
		// DIFFERENT TASK TYPE
		if (t1.taskType == FLOATTASK || t2.taskType == FLOATTASK)
		{
			// AT MOST ONE FLOAT TASK ( DIFFERENT TASK TYPE)
			if (t1.taskType == FLOATTASK) return false;
			else return true;
		}
		else
		{
			// SAME END DATE
			if (utility.isEqual(t1.endDate,t2.endDate))
			{
				if (!utility.isEqual(t1.endTime,t2.endTime))
				{
					// COMPARE TIME
					return (utility.isLaterTime(t1.endTime,t2.endTime));
				}
				else return (t1.title.compare(t2.title) < 0);
			}
			else return (utility.isLaterDate(t1.endDate,t2.endDate));
		}
	}
}

//Display function's sub-functions
Date getTodayDate() {
	Date today;
	time_t t = time(0);
	struct tm * now = localtime ( &t );

	today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

	return today;
}

Date getTmrDate() {
	Date tmr;
	time_t t = time(0);
	struct tm * now = localtime ( &t );

	time(&t);
	t = t + (60 * 60 * 24);
	struct tm * now1 = localtime (&t);
		
	tmr = Date(now1->tm_mday,now1->tm_mon+1,now1->tm_year+1900);

	return tmr;
}

//Main display function
vector<Task> Logic::Display(vector<Task> allTasks, Task displayedTaskDate, InstructionType instruction)
{
	vector<Task> displayedTasks;
	Date today = getTodayDate();
	Date tmr =  getTmrDate();
	Date specificDate = Date(displayedTaskDate.startDate.day,displayedTaskDate.startDate.month,displayedTaskDate.startDate.year);

	switch (instruction) {
	case ALL:
		for (int i = 0; i < allTasks.size(); i++) {
			displayedTasks.push_back(allTasks[i]);
		}
		break;
	case DISPLAYDONE:
		for (int i = 0; i < allTasks.size(); i++) {
			if (allTasks[i].isDone) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	case DISPLAYUNDONE:
		for (int i = 0; i < allTasks.size(); i++) {
			if (!allTasks[i].isDone) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	case OVERDUE:
		for (int i = 0; i < allTasks.size(); i++) {
			if (!allTasks[i].isDone && utility.beforeToday(allTasks[i].startDate,today)) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	case TODAY:
		for (int i = 0; i < allTasks.size(); i++) {
			if (!allTasks[i].isDone && (allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate,today))) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	case TMR:
		for (int i = 0; i < allTasks.size(); i++) {
			if (!allTasks[i].isDone && (allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate,tmr))) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	case SHOWDATE:
		for (int i = 0; i < allTasks.size(); i++) {
			if (!allTasks[i].isDone && (allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate,specificDate))) {
				displayedTasks.push_back(allTasks[i]);
			}
		}
		break;
	default:
		break;
	};

	// sort Task
	sort(displayedTasks.begin(),displayedTasks.end(),bind(&Logic::orderTask,this,std::placeholders::_1,std::placeholders::_2));

	return displayedTasks;
}

//Edit function's sub-functions
bool isInputValid(vector<Task> displayedTasks, int index, Task newTaskInfo) {
	if ((index > displayedTasks.size()) || (newTaskInfo.taskType == NUL)) {
		return false;
	} else {
		return true;
	}
}


bool isTaskTypeValid(Task toBeEditedTask, Task newTaskInfo) {
	if (((toBeEditedTask.taskType == FLOATTASK) && (newTaskInfo.taskType != FLOATTASK)) ||
		((toBeEditedTask.taskType == DEAD) && (newTaskInfo.taskType == TIMED)) ||
		((toBeEditedTask.taskType == TIMED) && (newTaskInfo.taskType == DEAD))) {
		return false;
	} else {
		true;
	}
}

Task updateTask(Task toBeEditedTask, Task newTaskInfo) {
	Utility utility;

	if (!utility.isNull(newTaskInfo.title)) {
		toBeEditedTask.title = newTaskInfo.title;
	}

	if (!utility.isNull(newTaskInfo.startDate)) {
		toBeEditedTask.startDate = newTaskInfo.startDate;
	}

	if (!utility.isNull(newTaskInfo.endDate)) {
		toBeEditedTask.endDate = newTaskInfo.endDate;
	}

	if (!utility.isNull(newTaskInfo.startTime)) {
		toBeEditedTask.startTime = newTaskInfo.startTime;
	}

	if (!utility.isNull(newTaskInfo.endTime)) {
		toBeEditedTask.endTime = newTaskInfo.endTime;
	}

	return toBeEditedTask;
}

vector<Task> updateAllTasks(vector<Task> allTasks, Task toBeEditedTask, Task newTaskInfo) {
	Utility utility;

	for (int i = 0; i < allTasks.size(); i++) {
		if (utility.isSame(allTasks[i],toBeEditedTask)) {
			allTasks[i] = updateTask(allTasks[i], newTaskInfo);
		}
	}

	return allTasks;
}

//Main edit function
vector<Task> Logic::Edit(vector<Task> allTasks, vector<Task> displayedTasks, int index, Task newTaskInfo)
{
	if (isInputValid(displayedTasks, index, newTaskInfo)) {
		Task toBeEditedTask = displayedTasks[index - 1];

		if (isTaskTypeValid(toBeEditedTask, newTaskInfo)) {
			for (int i = 0; i < allTasks.size(); i++) {
				allTasks = updateAllTasks(allTasks, toBeEditedTask, newTaskInfo);
			}
		}
	}

	return allTasks;
}

// Tung
vector<Task> Logic::Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	
	// Logic similar to Done
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	for (int j = 0; j < index.size(); j++)
	{
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}

	success = 1;

	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++)
	{
		success = 1;

		Task undoneTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],undoneTask)) 
			{
				marked[i] = true;
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		temp.push_back(allTask[i]);
		if (marked[i]) temp[i].isDone = false;
		//cout<<i<<" "<<temp[i].isDone<<endl;
	}

	return temp;


}



