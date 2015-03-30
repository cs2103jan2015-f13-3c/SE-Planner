#include "TaskParser.h"
#include <iostream>
TaskParser::TaskParser(std::string input, bool hasIndex){
	_taskInput = input;
	_hasIndex = hasIndex;
}

void TaskParser::parse(){
	
	_taskType = findTaskType();
	if(_hasIndex){
		_taskIndex = findTaskIndex();
	}
	_taskTitle = findTaskTitle();
	_timeParser.setInput(_taskInput);
	_timeParser.parse();
	_dateParser.setInput(_taskInput);
	_dateParser.parse();
	
}


TaskType TaskParser::findTaskType(){
	TaskType taskType = FLOATINGTASK;//default taskType

	if( isFound(DATE_KEYWORD, _taskInput) ){
		taskType = DEADLINE;
	} 
	if( isFound(TIME_WITH_RANGE_KEY, _taskInput) ){
		taskType = TIMEDTASK;
	} 
	if( isFound(D_M_Y_KEY,_taskInput) ){
		//taskType = RECURRINGTASK;
		//Recurring task not ready	
	}

	return taskType;
}

std::string TaskParser::findTaskIndex(){
	_taskInput = trimLeadingSpaces(_taskInput);
	std::string index = _taskInput.substr(0, _taskInput.find(" "));
	_taskInput.erase(0, _taskInput.find(" "));
	return index;
}

bool TaskParser::isFound(std::string keyword,std::string sentence){
	return sentence.find(keyword) != std::string::npos;
}	

std::string TaskParser::findTaskTitle(){
	std::string processedString = _taskInput;
	
	if( isFound(DATE_KEYWORD, _taskInput) ){
		processedString = removeDate(processedString);
	}

	if( isFound(TIME_KEYWORD, _taskInput) ){
		processedString = removeTime(processedString);
	}

	return processedString;

}

std::string TaskParser::removeDate(std::string sentence){
	std::string sentenceBeforeDate = sentence.substr(0, sentence.find("date:"));
	std::string sentenceAfterDate = sentence.substr(sentence.find("date: ")+6);
	sentenceAfterDate = sentenceAfterDate.substr(sentenceAfterDate.find(" "));
	if(sentenceAfterDate.length()>1){
		sentenceAfterDate.erase(0,1);
	}
	return sentenceBeforeDate + sentenceAfterDate;
}

std::string TaskParser::removeTime(std::string sentence){
	std::string sentenceBeforeTime = sentence.substr(0, sentence.find("time:"));
	std::string sentenceAfterTime = sentence.substr(sentence.find("time: ")+6);
	sentenceAfterTime = sentenceAfterTime.substr(sentenceAfterTime.find(" "));
	
	if(sentenceAfterTime.length()>1){
		sentenceAfterTime.erase(0,1);
	}
	
	return sentenceBeforeTime + sentenceAfterTime;
}

std::string TaskParser::trimLeadingSpaces(std::string sentence){
	size_t pos = sentence.find_first_not_of(" \t");
	sentence.erase(0, pos);
	return sentence;
}

//*** Accessors
Date TaskParser::getDateStart(){
	return _dateParser.getDateStart();
}

Date TaskParser::getDateEnd(){
	return _dateParser.getDateEnd();
}

Time TaskParser::getTimeStart(){
	return _timeParser.getTimeStart();
}

Time TaskParser::getTimeEnd(){
	return _timeParser.getTimeEnd();
}

Time TaskParser::getTime(){
	return _timeParser.getTime();
}

Date TaskParser::getDate(){
	return _dateParser.getDate();
}

Task TaskParser::getTask(){
	Task newTask;
	newTask.setStartingDate(getDateStart());
	newTask.setEndingDate(getDateEnd());
	newTask.setStartingTime(getTimeStart());
	newTask.setEndingTime(getTimeEnd());
	newTask.setTaskType(_taskType);
	newTask.setTitle(_taskTitle);
	return newTask;
}

std::string TaskParser::getTaskIndex(){
	return _taskIndex;
}
