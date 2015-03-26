#pragma once
#include <string>
#include "Time.h"

// special keywords
const std::string TIME_KEYWORD = "time:";
const std::string TIME_WITH_RANGE_KEY = "-";	// keys used to identify different taskTypes

enum TimeTypes{
	NO_TIME, DEFAULT_TIME, TIME_W_RANGE
};

class TaskTimeParser{
public:
	TaskTimeParser(std::string);
	TaskTimeParser(void);

	void parse();
	void setInput(std::string);

	Time getTime();
	Time getTimeStart();
	Time getTimeEnd();

private:
	
	int getNumber(std::string&);
	TimeTypes _containsTimeType;
	std::string _timeParserInput;
	std::string _timeStart;
	TimeType _timeStart_AM_PM;
	std::string _timeEnd;
	TimeType _timeEnd_AM_PM;
	
	std::string trimLeadingSpaces(std::string);
	bool isFound(std::string, std::string);
	std::string getKeywordAfter(std::string, std::string);

	bool isTimeInput();

	std::string getTimeStr();

	TimeType getTimeType(std::string);

	void setTimeType(std::string);
	void setTime(std::string);


};
