#include "TaskTimeParser.h"
#include <iostream>

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
		_timeEnd = _timeStart;
		break;	
	case TIME_W_RANGE:
		_timeStart = timeStr.substr(0,4);
		_timeEnd = timeStr.substr(5,9);
	}

}

bool TaskTimeParser::isTimeInput(){
	return(isFound(TIME_KEYWORD, _timeParserInput));
}

bool TaskTimeParser::isFound(std::string keyword,std::string sentence){
	return sentence.find(keyword) != std::string::npos;
}	

std::string TaskTimeParser::getKeywordAfter(std::string keyword, std::string sentence){
	sentence = sentence.substr(sentence.find(keyword)+keyword.length()+1);
	std::string timeRangeStr=sentence.substr(0,9);
	if(isFound("-",timeRangeStr)==false){
		return timeRangeStr.substr(0,4);
	}
	return timeRangeStr;
}

std::string TaskTimeParser::trimLeadingSpaces(std::string sentence){
	size_t pos = sentence.find_first_not_of(" \t");
	sentence.erase(0, pos);
	return sentence;
}

std::string TaskTimeParser::getTimeStr(){
	return getKeywordAfter(TIME_KEYWORD, _timeParserInput);
}

Time TaskTimeParser::getTime(){
	return getTimeStart();
}

Time TaskTimeParser::getTimeStart(){
	std::string timeStr = _timeStart;
	std::string timeTypeStr = _timeStart;
	Time newTime;
	_timeStart_AM_PM = getTimeType(timeTypeStr);	
	newTime.setTimeType(_timeStart_AM_PM);
	int hours = getNumber(timeStr);
	if(_timeStart_AM_PM==PM){   //1200-2359h = PM
		hours%=12;
	}else{						//0000-1159 = AM
		if(hours==0){
			hours=12;
		}
	}		

	newTime.setHours(hours);
	newTime.setMinutes(getNumber(timeStr));
	return newTime;
}

Time TaskTimeParser::getTimeEnd(){	

	if(_containsTimeType == DEFAULT_TIME){
		return getTimeStart();
	}
	std::string timeStr = _timeEnd;
	std::string timeTypeStr = _timeEnd;

	Time newTime;
	_timeEnd_AM_PM = getTimeType(timeTypeStr);	
	newTime.setTimeType(_timeEnd_AM_PM);
	int hours = getNumber(timeStr);

	if(_timeEnd_AM_PM==PM){   //1200-2359h = PM
		hours%=12;
	}else{						//0000-1159 = AM
		if(hours==0){
			hours=12;
		}
	}

	newTime.setHours(hours);
	newTime.setMinutes(getNumber(timeStr));
	newTime.setTimeType(getTimeType(_timeEnd));
	return newTime;
}

TimeType TaskTimeParser::getTimeType(std::string time){
	if(getNumber(time)>=12){
		return PM;
	}
	return AM;
}

int TaskTimeParser::getNumber(std::string& time){
	std::string numberStr = time.substr(0, 2); 
	time.erase(0, numberStr.length());
	return atoi(numberStr.c_str());
}
