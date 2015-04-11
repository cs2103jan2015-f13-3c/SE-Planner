#include "Parser.h"
#include "Utility.h"

#include <string>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <sstream>

using namespace std;

Command newCommand;
Task newTask;
Date today;
smatch cap;

bool isDateRange = false, isTimeRange = false;
bool isDateValid = false, isTimeValid = false;
bool isDate = false, isTime = false;
string TaskTitle = "";
string DateString = "";
string TimeString = "";


Parser::Parser(void)
{
}


Parser::~Parser(void)
{
}

Time ParseTime(string inp) {
	Time ret(-1,-1);

	//HH or H
	if (inp.length() <= 2) 
	{
		ret.hour = atoi(inp.c_str());
		ret.min = 0;
	}

	//HHMM
	if (inp.length() == 4)
	{
		ret.hour = atoi(inp.substr(0,2).c_str());
		ret.min = atoi(inp.substr(2,2).c_str());
	}

	//HMM
	if (inp.length() == 3)
	{
		ret.hour = atoi(inp.substr(0,1).c_str());
		ret.min = atoi(inp.substr(1,2).c_str());
	}
	return ret;
}

string removeSpace(string inp)
{
	string str = inp;
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	return str;
}

Date ParseDate(string inp)
{
	Date ret(-1,-1,-1);
	string inp1 = inp;
	string inp2 = removeSpace(inp1);
	inp = inp2;
	

	// D or DD
	if (inp.length() <= 2)
	{
		regex rgxDD("(\\d+)");
		if (regex_search(inp,cap,rgxDD))
		{
			ret.day = atoi(string(cap[1]).c_str());
			ret.month = today.month;
			ret.year = today.year;
		}
	}

	// DD/MM
	else if (inp.length() <= 5)
	{
		//cout<<"DATE ONE SLASH"<<endl;
		regex rgxDD("(\\d+)\\/(\\d+)");
		if (regex_search(inp,cap,rgxDD))
		{
			//cout<<cap[1]<<"|"<<cap[2]<<endl;
			ret.day = atoi(string(cap[1]).c_str());
			ret.month = atoi(string(cap[2]).c_str());
			ret.year = today.year;
		}
		//cout<<"DOES IT WORK"<<endl;
	}
	else 
	{
		
		// DD/MM/YYYY
		regex rgxDD("(\\d+)\\/(\\d+)\\/(\\d+)");
		if (regex_search(inp,cap,rgxDD))
		{
			ret.day = atoi(string(cap[1]).c_str());
			ret.month = atoi(string(cap[2]).c_str());
			ret.year = atoi(string(cap[3]).c_str());
			// convert 15 -> 2015
			if (ret.year >= 0 && ret.year <= 99) ret.year += 2000;
		}
	}
	return ret;
}

CommandType extractCommandType(string inp)
{
	CommandType ret = INVALID;

	regex rgx("^\\s*(\\S+)");
	smatch sm;

	if (regex_search(inp,sm,rgx))
	{
		string cmd = sm[1];

		if (cmd == COMMAND_ADD) ret = ADD;
		if (cmd == COMMAND_SEARCH) ret = SEARCH;
		if (cmd == COMMAND_DISPLAY) ret = DISPLAY;
		if (cmd == COMMAND_DELETE) ret = DEL;
		if (cmd == COMMAND_EDIT) ret = EDIT;
		if (cmd == COMMAND_DONE) ret = DONE;
		if (cmd == COMMAND_UNDONE) ret = UNDO;
		if (cmd == COMMAND_EXIT) ret = EXIT;
		if (cmd == COMMAND_CLS) ret = CLS;
		if (cmd == COMMAND_HELP) ret = HELP;
		if (cmd == COMMAND_UNDONE) ret = UNDONE;
		if (cmd == COMMAND_USE) ret = USE;
		if (cmd == COMMAND_WHERE) ret = WHERE;
	}

	return ret;
}

void extractTimedTaskInfo(string inp)
{
	newTask.taskType = TIMED;

	if (!isDate)
	{
		// TIMED TASK WITHOUT DATE
		regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
		if (regex_search(TimeString, cap, rgxTimeRangeInner))
		{
			newTask.startTime = ParseTime(cap[1]);
			newTask.endTime = ParseTime(cap[2]);
		}
	}
	else
	{
		// DATE RANGE
		if (isDateRange)
		{
			// TIMED TASK WITH DATE RANGE
			regex rgxDateRangeInner("\\s*(.*)\\s*-\\s*(.*)");
			smatch cap2;
			if (regex_search(DateString, cap2, rgxDateRangeInner))
			{
				newTask.startDate = ParseDate(cap2[1]);
				newTask.endDate = ParseDate(cap2[2]);
			}
		}
		else
		{
			//cout<<"TIMED TASK WITH DATE NO RANGE"<<endl;
			regex rgxOnlyDate("date:\\s*([\\d\\/\\s]+)\\s*");
			if (regex_search(inp, cap, rgxOnlyDate))
			{
				newTask.startDate = ParseDate(cap[1]);
				newTask.endDate = newTask.startDate;
			}
		}

		// TIME RANGE
		regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
		if (regex_search(TimeString, cap, rgxTimeRangeInner))
		{
			newTask.startTime = ParseTime(cap[1]);
			newTask.endTime = ParseTime(cap[2]);
		}
	}
}

void extractDeadlineInfo(string inp)
{
	newTask.taskType = DEAD;

	// only one date and optional one time

	regex rgxOnlyDate("date:\\s*([\\d\\/]+)");
	if (regex_search(inp,cap,rgxOnlyDate))
	{
		newTask.startDate = ParseDate(cap[1]);
		newTask.endDate = newTask.startDate;
	}

	if (isTime)
	{
		regex rgxOnlyTime("time:\\s*(\\d+)");
		if (regex_search(inp,cap,rgxOnlyTime))
		{
			newTask.startTime = ParseTime(cap[1]);
			newTask.endTime = newTask.startTime;
		}
	}
}

void extractDateTime(string inp)
{
	smatch sm;
	regex rgxDateRange("date:\\s*([\\d\\/]+\\s*-\\s*[\\d\\/]+)");
	if (regex_search(inp,sm,rgxDateRange)) 
	{
		DateString = sm[1];
		isDateRange = true;
	}

	regex rgxTimeRange("time:\\s*(\\d+\\s*-\\s*\\d+)");
	if (regex_search(inp,sm,rgxTimeRange)) 
	{
		TimeString = sm[1];
		isTimeRange = true;
	}

	if (isDateRange || isTimeRange)
	{
		// Timed Task
		extractTimedTaskInfo(inp);
	}
	else
	{
		// Deadline
		extractDeadlineInfo(inp);
	}

}


void trimString(string &input) {
	size_t pos;
	pos = input.find_first_not_of(" \n\t");

	if (pos != string::npos) {
		input = input.substr(pos);
	}

	input = input.substr(0, input.find_last_not_of(" \n\t") + 1);
}

void extractTitle(string inp)
{
	if (isDate && isTime)
	{
		regex TitleWithDateTime("\\s(.*)\\s(date:|time:).*(date:|time:).*$");
		if (regex_search(inp,cap,TitleWithDateTime)) newTask.title = cap[1];
	}
	else if (!isDate && !isTime)
	{
		regex TitleOnly("\\s(.*)");
		if (regex_search(inp,cap,TitleOnly)) newTask.title = cap[1];
	}
	else
	{
		regex TitleWithDateOrTime("\\s(.*)\\s(date:|time:).*$");
		if (regex_search(inp,cap,TitleWithDateOrTime)) newTask.title = cap[1];
	}
	
	if (newTask.title != "") trimString(newTask.title);
	
}


void extractTaskInfo(string inp, int skip)
{
	

	// check if date exist
	regex rgxDate("date:");
	if (regex_search(inp,rgxDate)) isDate = true;

	// check if time exist
	regex rgxTime("time:");
	if (regex_search(inp,rgxTime)) isTime = true;

	extractTitle(inp.substr(skip));

	if (!isDate && !isTime)
	{
		newTask.taskType = FLOATTASK;
	}
	else
	{
		// extract date and time:
		extractDateTime(inp);
	}


}

void Parser::assumeInfo()
{
	time_t t = time(0);
	struct tm * now = localtime ( &t );

	today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);


	if (newTask.taskType == DEAD)
	{
		// date without time
		if (!utility.isNull(newTask.startDate) && utility.isNull(newTask.startTime))
		{
			newTask.startTime = Time(23,59);
			newTask.endTime = Time(23,59);
		}

		// time without date
		if (!utility.isNull(newTask.startTime) && utility.isNull(newTask.startDate))
		{
			newTask.startDate = today;
			newTask.endDate = today;
		}
	}

	if (newTask.taskType == TIMED)
	{
		// time range without date
		if (!utility.isNull(newTask.startTime) && utility.isNull(newTask.startDate))
		{
			newTask.startDate = today;
			newTask.endDate = today;
		}
		// date without time
		if (!utility.isNull(newTask.startDate) && utility.isNull(newTask.startTime))
		{
			newTask.startTime = Time(0,0);
			newTask.endTime = Time(23,59);
		}
	}
}

void readIndexList(string inp, int skip)
{
	istringstream iss(inp.substr(skip));

	int readIndex;
	bool correct = true;

	while (iss>>readIndex)
	{
		newCommand.idx.push_back(readIndex);
		if (readIndex < 1) correct = false;
	}

	if (!correct) newCommand.idx.clear();
}

void Parser::extractDisplayInfo(string inp)
{
	bool isInstruction = false;
	// get instruction
	regex rgxToday("display today");
	if (regex_search(inp,rgxToday))
	{
		isInstruction = true;
		newCommand.instruction = TODAY;
	}

	regex rgxTmr("display tomorrow");
	if (regex_search(inp,rgxTmr))
	{
		isInstruction = true;
		newCommand.instruction = TMR;
	}

	regex rgxOverdue("display overdue");
	if (regex_search(inp,rgxOverdue))
	{
		isInstruction = true;
		newCommand.instruction = OVERDUE;
	}

	regex rgxAll("display all");
	if (regex_search(inp,rgxAll))
	{
		isInstruction = true;
		newCommand.instruction = ALL;
	}

	regex rgxDone("display done");
	if (regex_search(inp,rgxDone))
	{
		isInstruction = true;
		newCommand.instruction = DISPLAYDONE;
	}

	regex rgxUndone("display undone");
	if (regex_search(inp,rgxUndone))
	{
		isInstruction = true;
		newCommand.instruction = DISPLAYUNDONE;
	}

		
	// or get date

	if (!isInstruction)
	{
		//display [Date]
		// Deadline
		newTask.taskType = DEAD;

		// only one date and optional one time

		regex rgxOnlyDate("display\\s*([\\d\\/]+)");
		if (regex_search(inp,cap,rgxOnlyDate))
		{
			newTask.startDate = ParseDate(cap[1]);
			newTask.endDate = newTask.startDate;
		}

		if (utility.isValidDate(newTask.startDate)) newCommand.instruction = SHOWDATE;
		else newCommand.cmd = INVALID;
	}

}

Parser::Parser(string inp)
{
	// receive input, parse accordingly
	isDateRange = false;
	isTimeRange = false;
	isDateValid = false;  
	isTimeValid = false;
	isDate = false; 
	isTime = false;
	TaskTitle = "";
	DateString = "";
	TimeString = "";

	newCommand = Command();
	newTask = Task();

	// extract command type
	CommandType cmdType = extractCommandType(inp);
	newCommand.cmd = cmdType;


	if (cmdType == ADD)
	{
		extractTaskInfo(inp,COMMAND_ADD.length());
		assumeInfo();

		bool isValidTask = utility.isValidAddTask(newTask);
		if (!isValidTask)
		{
			newCommand.cmd = INVALID;
		}

	}

	if (cmdType == DEL)
	{
		readIndexList(inp,COMMAND_DELETE.length());
	}

	if (cmdType == EDIT)
	{
		// extract EDIT index;
		regex rgxEditIdx("edit\\s*(\\d+)");

		if (regex_search(inp,cap,rgxEditIdx))
		{
			newCommand.idx.push_back(atoi(string(cap[1]).c_str()));
			if (newCommand.idx[0] < 1) newCommand.idx.clear();
		}

		extractTaskInfo(inp,COMMAND_EDIT.length()+2);
		if (!utility.isValidOtherTask(newTask))
		{
			newCommand.cmd = INVALID;
		}

	}

	if (cmdType == DISPLAY)
	{
		extractDisplayInfo(inp);
	}

	if (cmdType == SEARCH)
	{
		extractTaskInfo(inp,COMMAND_SEARCH.length());
		if (!utility.isValidOtherTask(newTask))
		{
			newCommand.cmd = INVALID;
		}

	}

	if (cmdType == DONE)
	{	
		readIndexList(inp,COMMAND_DONE.length());
	}

	if (cmdType == UNDONE)
	{
		readIndexList(inp,COMMAND_UNDONE.length());
	}

	if (cmdType == USE)
	{
		regex rgxFilePath("use (.*)");
		
		if (regex_search(inp,cap,rgxFilePath))
		{
			newCommand.path = cap[1];
		}

	}
}


Command Parser::getCommand()
{
	return newCommand;
}

Task Parser::getTask()
{
	return newTask;
}