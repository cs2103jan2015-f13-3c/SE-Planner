#include "TaskParser.h"

//TODO: methods to be completed
//findTimeType 
//findTaskTime 
//findDateType 
//findTaskDate 
//getTime : swtich timeType set am/pm set range
//getDate : switch dateType set d/m/y set range
//removeTime
//removeDate

TaskParser::TaskParser(std::string input){
	_taskInput = input;
}

//***2. task processing methods ***

void TaskParser::parse(){
	_taskType = findTaskType();
	//	_timeType = findTimeType();
	//	_dateType = findDateType();

	//	setTime(_taskTime);
	//	setDate(_taskDate);

	_taskTitle = findTaskTitle();

}


void TaskParser::setTime(TimeTypes timeType){

	switch(timeType){

	case NO_TIME:
		break;
	case DEFAULT_TIME:
		//		_taskTime = findTaskTime(); break;
	case TIME_W_RANGE:
		//		_taskTime = findTaskTime();	break;		// requires addtional processing, format : xxxxam-xxxxpm
		break;
	}
}

void TaskParser::setDate(DateTypes dateType){
	switch(dateType){

	case NO_DATE:
		break;
	case DEFAULT_DATE:
		//		_taskDate = findTaskDate(); break;
	case DATE_W_RANGE:
		//		_taskDate = findTaskDate();	break;		// requires addtional processing, format : xxxxam-xxxxpm
		break;
	}
}

TaskType TaskParser::findTaskType(){
	TaskType taskType = FLOATINGTASK;

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

bool TaskParser::isFound(std::string keyword,std::string sentence){
	return sentence.find(keyword) != std::string::npos;
}	


std::string TaskParser::findTaskTitle(){
	std::string processedString = _taskInput;

	if( isFound(DATE_KEYWORD, _taskInput) ){
		//	processedString = removeDate(DATE_KEYWORD, processedString);
	}

	if( isFound(TIME_KEYWORD, _taskInput) ){
		//		processedString = removeTime(TIME_KEYWORD, processedString);
	}

	return processedString;

}


//***INCOMPLETE METHODS:
/*
std::string TaskParser::extractKeyword(std::string keyword,std::string sentence){
std::string timeStr;
timeStr = getKeywordAfter(keyword,sentence);

_task.setStartTime(getStartTimeString(timeStr));
_task.setEndTime(getEndTimeString(timeStr));

return removeKeyword("time: ", sentence);
}

std::string TaskParser::getKeywordAfter(std::string keyword, std::string sentence){
sentence = sentence.substr(sentence.find(keyword));
return sentence.substr(0,sentence.find(" "));
}

std::string TaskParser::removeKeyword(std::string delimiter, std::string s){
size_t pos = 0;
//std::string delimiter = "time: ";
std::string token;
std::string processedString;

while ((pos = s.find(delimiter)) != std::string::npos) {
token = s.substr(0, pos);

processedString += token;
s.erase(0, pos + delimiter.length());
s = s.substr(1);
}

return processedString;
}
*/