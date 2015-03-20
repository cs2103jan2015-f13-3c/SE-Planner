#include "TaskTimeParser.h"


TaskTimeParser::TaskTimeParser(std::string input){
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

