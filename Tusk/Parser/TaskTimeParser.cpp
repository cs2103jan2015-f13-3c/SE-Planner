#include "TaskTimeParser.h"

TaskTimeParser::TaskTimeParser(void){
}

TaskTimeParser::TaskTimeParser(std::string input){
	_timeParserInput = input;
}

void TaskTimeParser::setInput(std::string input){
	_timeParserInput = input;
}

void TaskTimeParser::parse(){
	std::string timeStr;

	if(isTimeInput()){
		timeStr = getTimeStr();
		setTimeType(timeStr);	
		setTime(timeStr);

	}
}

std::string TaskTimeParser::getTimeStr(){
	return getKeywordAfter(TIME_KEYWORD, _timeParserInput);
}

void TaskTimeParser::setTimeType(std::string timeStr){
	_containsTimeType = DEFAULT_TIME;
	
	if(isFound(TIME_WITH_RANGE_KEY, timeStr)){
		_containsTimeType = TIME_W_RANGE;
	}
}

void TaskTimeParser::setTime(std::string timeStr){
	switch(_containsTimeType){	
	
	case DEFAULT_TIME:
		_timeStart = timeStr.substr(0,4);
		_timeStart_AM_PM = timeStr.substr(4,6);
			
	case TIME_W_RANGE:
		_timeEnd = timeStr.substr(6,10);
		_timeEnd_AM_PM = timeStr.substr(10,12);

	}

}

bool TaskTimeParser::isTimeInput(){
return(isFound(TIME_KEYWORD, _timeParserInput));
}

bool TaskTimeParser::isFound(std::string keyword,std::string sentence){
	return sentence.find(keyword) != std::string::npos;
}	

std::string TaskTimeParser::getKeywordAfter(std::string keyword, std::string sentence){
sentence = sentence.substr(sentence.find(keyword));
return sentence.substr(0,sentence.find(" "));
}

Time TaskTimeParser::getTime(){
	return getTimeStart();
}


//TODO:
Time TaskTimeParser::getTimeStart(){
	std::string timeStr = _timeStart;

	Time newTime;
	newTime.setHours(getNumber(timeStr));
	newTime.setMinutes(getNumber(timeStr));
	newTime.setTimeType(getTimeType(_timeStart));
	return newTime;
}

Time TaskTimeParser::getTimeEnd(){
		if(_containsTimeType = DEFAULT_TIME){
		return getTimeStart();
	}
	std::string timeStr = _timeEnd;
	Time newTime;
	newTime.setHours(getNumber(timeStr));
	newTime.setMinutes(getNumber(timeStr));
	newTime.setTimeType(getTimeType(_timeEnd));
	return newTime;
}

TimeType TaskTimeParser::getTimeType(std::string time){
	if(getNumber(time)>12){
	return PM;
	}
	return AM;
}

int TaskTimeParser::getNumber(std::string& time){
	std::string numberStr = time.substr(0, 2); 
	time.erase(0, numberStr.length());
	return atoi(numberStr.c_str());
}
