#pragma once

#include "Common.h"
#include <vector>
#include <string>

using namespace std;

class Utility
{
public:
	Utility(void);
	~Utility(void);

	bool isValidDate(Date);
	bool isValidTime(Time);
	bool isLaterDate(Date, Date); // isLaterDate(6/4, 7/4) = true
	bool isLaterTime(Time, Time); // isLaterTime(7,8) = true
	bool isDiffDate(Date, Date);  // different date
	bool isNotNullDate(Date);
	bool isNotNullTime(Time);
	bool beforeToday(Date, Date); // beforeToday(6/4,today) = true

	bool isNull(string);
	bool isNull(Date);
	bool isNull(Time);

	bool isEqual(Date, Date); 
	bool isEqual(Time, Time);

	bool isValidAddTask(Task); // is the Task about to add valid

	/*
		This is for search, edit
		Is the information input by user (title, date, time) a valid one
	*/
	bool isValidOtherTask(Task); 

	/*
		This is for search
	*/
	bool compareTitle(Task, Task); // compareTitle("yoong zhen, "zhen") = true. "zhen" is substring of "yoongzhen"
	bool compareDate(Task, Task); // Compare if the date from SEARCH command is matched
	bool compareTime(Task, Task); // Compare if the time from SEARCH command is matched

	// for DELETE, EDIT, DONE
	bool isSame(Task, Task); // find the task from displayTaskList inside mainTaskList

	void log(string);
};

