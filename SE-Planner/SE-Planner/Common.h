#pragma once
#include <string>
#include <vector>

using namespace std;

enum TaskType
{
	// NUL = The Task is INVALID
	FLOATTASK, TIMED, DEAD, NUL, REPEAT
};

enum InstructionType
{
	TODAY, TMR, SHOWDATE, OVERDUE, ALL, NONE, DISPLAYDONE, DISPLAYUNDONE
};

enum CommandType
{
	ADD, SEARCH, DISPLAY, DEL, EDIT, DONE, UNDO, REDO, EXIT, INVALID, CLS, HELP, UNDONE, USE, WHERE
};

class Date 
{
public:
	int year, month, day;

	Date()
	{
		// default constructor
		year = -1;
		month = -1;
		day = -1;
	}

	Date(int x, int y, int z)
	{
		day = x; month = y; year = z;
	}


};

class Time
{
public:
	int hour,min;

	Time()
	{
		// default constructor
		hour = -1;
		min = -1;
	}

	Time(int x, int y)
	{
		hour = x; min = y;
	}
};


class Task {
public:
	TaskType taskType;
	string title;

	Time startTime, endTime;
	Date startDate, endDate;

	bool isDone;

	Task()
	{
		// default constructor
		title = "";
		taskType = NUL;
		startTime = Time(-1,-1);
		endTime = Time(-1,-1);
		startDate = Date(-1,-1,-1);
		endDate = Date(-1,-1,-1);
		isDone = false;
	}

};

class Command 
{
public:
	CommandType cmd;
	vector<int> idx;
	InstructionType instruction;
	string path;

	Command()
	{
		// default constructor
		cmd = INVALID;
		idx.clear();
		instruction = NONE;
		path = "";
	}
};



