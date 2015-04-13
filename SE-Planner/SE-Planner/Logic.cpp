#include "Logic.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <assert.h>

using namespace std;

//@author A0108417J
const std::string SEARCH_START = "Start Search Function";
const std::string SEARCH_END  = "End Search Function";

//@author A0108417J
const std::string DISPLAY_START = "Start Display Function";
const std::string DISPLAY_END = "End Display Function";

//@author A0108417J
const std::string EDIT_START = "Start Edit Function";
const std::string EDIT_END = "End Edit Function";

//@author A0108417J
const std::string EMPTY = "Empty Array";

//@author A0108417J
//This function is a general function that throw exception when array size = 0 
void processArray(std::vector<Task> array) throw (exception) {
	if (array.size() == 0){
		throw exception();
	}
}

Logic::Logic(void){
	Utility utility;
}


Logic::~Logic(void){
}

// WEIMIN
vector<Task> Logic::Add(vector<Task> allTask, Task addTask){
	
	if (addTask.taskType == NUL){
		success = OPERATION_FAILED;
		return allTask;
	}
	else{
		success = OPERATION_SUCCEEDED;

		vector<Task> temp = allTask;
		temp.push_back(addTask);
		return temp;
	}
}

bool isValidIndex(vector<Task> displayedTask, vector<int> index){
	// if there is no index instruction -> fail command
	if (index.size() == 0){
		return false;
	}

	// if any index exceeds the size of display Task List -> fail command
	for (int j = 0; j < index.size(); j++){
		//cout<<index[j]<<endl;
		if (index[j] > displayedTask.size()){
			return false;
		}
	}

	return true;
}

// WEIMIN
vector<Task> Logic::Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index){
	
	if (!isValidIndex(displayedTask, index)){
		success = OPERATION_FAILED;
		return allTask;
	}
	
	success = OPERATION_SUCCEEDED;

	// 'marked' array for allTask
	// meaning : false = this task will NOT be deleted
	bool marked[MAX_TASK_SIZE];
	for (int i = 0; i <= allTask.size() + 1; i++){
		marked[i] = false;
	}
	vector<Task> temp;
	temp.clear();

	// mark the task to be deleted inside the mainTaskList
	for (int j = 0; j < index.size(); j++){
		
		success = OPERATION_SUCCEEDED;

		Task deleteTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++){
			if (utility.isSame(allTask[i],deleteTask)) {
				marked[i] = true; // THIS TASK WILL BE DELETED
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++){
		// DELETE ACCORDINGLY
		if (!marked[i]) temp.push_back(allTask[i]);
	}

	return temp;

}

// WEIMIN
vector<Task> Logic::Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index){
	
	if (!isValidIndex(displayedTask, index)){
		success = OPERATION_FAILED;
		return allTask;
	}

	success = OPERATION_SUCCEEDED;

	bool marked[MAX_TASK_SIZE];

	for (int i = 0; i <= allTask.size() + 1; i++){
		marked[i] = false;
	}
	
	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++){
		
		success = OPERATION_SUCCEEDED;

		Task doneTask = displayedTask[index[j]-1];

		for (int i = 0; i < allTask.size(); i++){
			if (utility.isSame(allTask[i],doneTask)) {
				marked[i] = true;
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++){
		temp.push_back(allTask[i]);
		if (marked[i]) temp[i].isDone = true;
		//cout<<i<<" "<<temp[i].isDone<<endl;
	}

	return temp;

}

//@author A0108417J
//This function searches through allTasks for searchedTask and return tasks which matched the searchedTask
std::vector<Task> Logic::search(std::vector<Task> allTasks, Task searchedTask) {
	assert(allTasks.size() >= 0);

	std::vector<Task> matchedTasks;
	success = OPERATION_FAILED;

	utility.log(SEARCH_START);

	try {
		processArray(allTasks);

		if (isTaskValid(searchedTask)) {
			matchedTasks = findMatchedTasks(allTasks, searchedTask);
			success = OPERATION_SUCCEEDED;
		} else {
			//Do nothing
		}

	} catch (exception& e) {
		utility.log(EMPTY);
	}

	utility.log(SEARCH_END);

	return matchedTasks;
}

//@author A0108417J
//This function checks if task is valid by checking its taskType
bool Logic::isTaskValid(Task task) {
	if (task.taskType != NUL) {
		return true;
	} else {
		return false;
	}
}

//@author A0108417J
//This function checks through allTasks for any tasks that matched task and return them
std::vector<Task> Logic::findMatchedTasks(std::vector<Task> allTasks, Task task) {
	std::vector<Task> matchedTasks;

	for (int i = 0; i < allTasks.size(); i++) {
		if (isTaskMatch(allTasks[i], task)) {
			matchedTasks.push_back(allTasks[i]);
		} else {
			//Do nothing
		}
	}

	return matchedTasks;
}

//@author A0108417J
//This function will return true only when the task and matchingTask have same title, date and time
bool Logic::isTaskMatch(Task task, Task matchingTask) {
	bool isTitleMatch = utility.compareTitle(task, matchingTask);
	bool isDateMatch = utility.compareDate(task, matchingTask);
	bool isTimeMatch = utility.compareTime(task, matchingTask);

	if (isTitleMatch && isDateMatch && isTimeMatch) {
		return true;
	} else {
		return false;
	}
}

//@author A0108417J
//This functions finds all tasks from allTasks that corresponds to instruction and return them
vector<Task> Logic::display(vector<Task> allTasks, Task specificTaskDate, InstructionType instruction)
{
	assert(allTasks.size() >= 0);

	vector<Task> displayedTasks;

	utility.log(DISPLAY_START);

	try {
		processArray(allTasks);

		switch (instruction) {
		case ALL:
			displayedTasks = allTasks;
			break;
		case DISPLAYDONE:
			displayedTasks = findDoneTasks(allTasks);
			break;
		case DISPLAYUNDONE:
			displayedTasks = findUndoneTasks(allTasks);
			break;
		case OVERDUE:
			displayedTasks = findOverdueTasks(allTasks);
			break;
		case TODAY:
			displayedTasks = findTodayTasks(allTasks);
			break;
		case TMR:
			displayedTasks = findTmrTasks(allTasks);
			break;
		case SHOWDATE:
			displayedTasks = findSpecificDateTasks(allTasks, specificTaskDate);
			break;
		default:
			break;
		};

	} catch (exception& e) {
		utility.log(EMPTY);
	}

	//Sort displayedTasks according to date followed by time
	sort(displayedTasks.begin(), displayedTasks.end(), bind(&Logic::orderTask,this,std::placeholders::_1,std::placeholders::_2));

	utility.log(DISPLAY_END);

	return displayedTasks;
}

//@author A0108417J
//This function find and return today date
Date Logic::getTodayDate() {
	Date today;
	time_t t = time(0);
	struct tm * now = localtime(&t);

	today = Date(now->tm_mday, now->tm_mon+1, now->tm_year+1900);

	return today;
}

//@author A0108417J
//This function find and return tmr date
Date Logic::getTmrDate() {
	Date tmrDate;
	time_t t = time(0);
	struct tm * now = localtime (&t);

	time(&t);
	t = t + (60 * 60 * 24);
	struct tm * tmr = localtime (&t);
		
	tmrDate = Date(tmr->tm_mday, tmr->tm_mon+1, tmr->tm_year+1900);

	return tmrDate;
}

//@author A0108417J
//This function returns specificTaskDate in Date class format
Date Logic::getSpecificDate(Task specificTaskDate) {
	Date specificDate = Date(specificTaskDate.startDate.day,
							 specificTaskDate.startDate.month,
							 specificTaskDate.startDate.year);
	return specificDate;
}

//@author A0108417J
//This function finds and returns all done tasks
std::vector<Task> Logic::findDoneTasks(std::vector<Task> allTasks) {
	std::vector<Task> displayedTasks;

	for (int i = 0; i < allTasks.size(); i++) {
		bool displayCondition = allTasks[i].isDone;
		if (displayCondition) {
				displayedTasks.push_back(allTasks[i]);
			}
	}

	return displayedTasks;
}

//@author A0108417J
//This function finds and returns all undone tasks
std::vector<Task> Logic::findUndoneTasks(std::vector<Task> allTasks) {
	std::vector<Task> displayedTasks;

	for (int i = 0; i < allTasks.size(); i++) {
		bool displayCondition = !allTasks[i].isDone;
		if (displayCondition) {
			displayedTasks.push_back(allTasks[i]);
		}
	}

	return displayedTasks;
}

//@author A0108417J
//This function finds and returns all undone and overdue tasks based on today date
std::vector<Task> Logic::findOverdueTasks(std::vector<Task> allTasks) {
	std::vector<Task> displayedTasks;
	Date today = getTodayDate();

	for (int i = 0; i < allTasks.size(); i++) {

		//displayCondition = when task is undone and task before today date
		bool displayCondition = !allTasks[i].isDone && utility.beforeToday(allTasks[i].startDate, today);

		if (displayCondition) {
			displayedTasks.push_back(allTasks[i]);
		}
	}

	return displayedTasks;
}

//@author A0108417J
//This function finds and returns all undone and today tasks
std::vector<Task> Logic::findTodayTasks(std::vector<Task> allTasks) {
	std::vector<Task> displayedTasks;
	Date today = getTodayDate();

	for (int i = 0; i < allTasks.size(); i++) {

		//displayCondition = when task is undone and today task or floating task
		bool displayCondition = !allTasks[i].isDone &&
								(allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate, today));
		
		if (displayCondition) {
			displayedTasks.push_back(allTasks[i]);
		}
	}

	return displayedTasks;
}

//@author A0108417J
//This function finds and returns all undone and tmr tasks
std::vector<Task> Logic::findTmrTasks(std::vector<Task> allTasks) {
	std::vector<Task> displayedTasks;
	Date tmr = getTmrDate();

	for (int i = 0; i < allTasks.size(); i++) {

		//displayCondition = when task is undone and tmr task or floating task
		bool displayCondition = !allTasks[i].isDone &&
								(allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate, tmr));
		
		if (displayCondition) {
			displayedTasks.push_back(allTasks[i]);
		}
	}

	return displayedTasks;
}

//@author A0108417J
//This function finds and returns all undone and specific date tasks
std::vector<Task> Logic::findSpecificDateTasks(std::vector<Task> allTasks, Task specificTaskDate) {
	std::vector<Task> displayedTasks;
	Date specificDate = getSpecificDate(specificTaskDate);

	for (int i = 0; i < allTasks.size(); i++) {
			
			//displayCondition = when task is undone and specific date task or floating task
			bool displayCondition = !allTasks[i].isDone &&
									(allTasks[i].taskType == FLOATTASK || utility.isEqual(allTasks[i].startDate, specificDate));
			
			if (displayCondition) {
				displayedTasks.push_back(allTasks[i]);
			}
		}

	return displayedTasks;
}

//@author A0108417J
//This functions edit allTasks with the newTaskInfo
vector<Task> Logic::edit(vector<Task> allTasks, vector<Task> displayedTasks, int index, Task newTaskInfo)
{
	assert(allTasks.size() >= 0);
	assert(displayedTasks.size() >= 0);

	std::vector<Task> updatedAllTasks = allTasks;
	success = OPERATION_FAILED;

	utility.log(EDIT_START);

	try {
		processArray(allTasks);
		processArray(displayedTasks);

		if (isInputValid(displayedTasks, index, newTaskInfo)) {
			Task toBeEditedTask = displayedTasks[index - 1];

			if (isTaskTypeValid(toBeEditedTask, newTaskInfo)) {
				updatedAllTasks = updateAllTasks(allTasks, toBeEditedTask, newTaskInfo);
			} else {
				//Do nothing
			}

		} else {
			//Do nothing
		}

	} catch (exception& e) {
		utility.log(EMPTY);
	}

	utility.log(EDIT_END);

	return updatedAllTasks;
}

//@author A0108417J
//This function checks if the edit input is correct
bool Logic::isInputValid(std::vector<Task> displayedTasks, int index, Task newTaskInfo) {
	if ((isIndexValid(displayedTasks, index)) && (isTaskValid(newTaskInfo))) {
		return true;
	} else {
		return false;
	}
}

//@author A0108417J
//This function checks if index is valid by comparing with the displayTask's size
bool Logic::isIndexValid(std::vector<Task> displayedTasks, int index) {
	if ((index <= 0) || (index > displayedTasks.size())) {
		return false;
	} else {
		return true;
	}
}

//@author A0108417J
//This function compares toBeEditedTask with newTaskInfo and determine if it is suitable to update toBeEditedTask
bool Logic::isTaskTypeValid(Task toBeEditedTask, Task newTaskInfo) {
	if (((toBeEditedTask.taskType == FLOATTASK) && (newTaskInfo.taskType != FLOATTASK)) ||
		((toBeEditedTask.taskType == DEAD) && (newTaskInfo.taskType == TIMED)) ||
		((toBeEditedTask.taskType == TIMED) && (newTaskInfo.taskType == DEAD))) {
		return false;
	} else {
		return true;
	}
}

//@author A0108417J
//This function updates allTasks with the newTaskInfo
std::vector<Task> Logic::updateAllTasks(vector<Task> allTasks, Task toBeEditedTask, Task newTaskInfo) {
	std::vector<Task> updatedAllTasks = allTasks;

	for (int i = 0; i < allTasks.size(); i++) {

		if (utility.isSame(allTasks[i],toBeEditedTask)) {
			Task updatedTask = updateTask(allTasks[i], newTaskInfo);

			if (utility.isValidAddTask(updatedTask)) {
				updatedAllTasks[i] = updatedTask;
				success = OPERATION_SUCCEEDED;
			} else {
				//Do nothing
			}
		} else {
			//Do nothing
		}
	}

	return updatedAllTasks;
}

//@author A0108417J
//This functions updates toBeEditedTask with the newTaskInfo
Task Logic::updateTask(Task toBeEditedTask, Task newTaskInfo) {
	Task editedTask = toBeEditedTask;

	//Update title
	if (!utility.isNull(newTaskInfo.title)) {
		editedTask.title = newTaskInfo.title;
	} else {
		//Do nothing
	}

	//Update Start Date
	if (!utility.isNull(newTaskInfo.startDate)) {
		editedTask.startDate = newTaskInfo.startDate;
	} else {
		//Do nothing
	}

	//Update End Date
	if (!utility.isNull(newTaskInfo.endDate)) {
		editedTask.endDate = newTaskInfo.endDate;
	} else {
		//Do nothing
	}

	//Update Start Time
	if (!utility.isNull(newTaskInfo.startTime)) {
		editedTask.startTime = newTaskInfo.startTime;
	} else {
		//Do nothing
	}

	//Update End Time
	if (!utility.isNull(newTaskInfo.endTime)) {
		editedTask.endTime = newTaskInfo.endTime;
	} else {
		//Do nothing
	}

	return editedTask;
}

// Tung
vector<Task> Logic::Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	if (!isValidIndex(displayedTask, index)){
		success = OPERATION_FAILED;
		return allTask;
	}

	success = OPERATION_SUCCEEDED;

	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++)
	{
		success = OPERATION_SUCCEEDED;

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