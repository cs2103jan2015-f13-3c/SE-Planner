#pragma once
#include <string>
#include "Date.h"

// special keywords
const std::string DATE_KEYWORD = "date:";
const std::string DATE_WITH_RANGE_KEY = "-";	// keys used to identify different taskTypes
const std::string D_M_Y_KEY = "/";

enum DateTypes{
	NO_DATE, DEFAULT_DATE, DATE_W_RANGE
};


class TaskDateParser{

public:
	
	TaskDateParser(std::string);
	TaskDateParser(void);

	void parse();

	Date getDate();
	Date getDateStart();
	Date getDateEnd();
	void setInput(std::string);
private:

	DateTypes _containsDateType;
	std::string _dateParserInput;
	std::string _dateStart;
	std::string _dateEnd;
	
	bool isFound(std::string, std::string);
	std::string getKeywordAfter(std::string, std::string);

	bool isDateInput();

	std::string getDateStr();

	void setDateType(std::string);
	void setDate(std::string);

	int getNumber(std::string&);
	Month getMonth(int);

};
