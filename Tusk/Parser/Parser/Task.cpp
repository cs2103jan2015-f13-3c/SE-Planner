#include "Task.h"

TaskTypes _taskType;
vector<string> _taskInfo;

Task::Task(TaskTypes task, vector<string> taskDetails){
	_taskType = task;
	_taskInfo = taskDetails;
}

Task::Task(void){

}

Task::~Task(void){

}

//return the name of the task
string getTaskName(){
	string taskName = "blank";

	return taskName;

}

vector<string> getTaskInfo(){
	return _taskInfo;
}