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
bool isDate = false, isTime = false, isRepeat = false;
string TaskTitle = "";
string DateString = "";
string TimeString = "";

string CommandString[] = {"ADD", "SEARCH", "DISPLAY", "DEL", "EDIT", "DONE", "UNDO", "REDO", "EXIT", "INVALID", "CLS"};
string TaskTypeString[] = {"FLOATTASK", "TIMED", "DEAD", "NULL", "RECUR"};
string InstructionString[] = {"TODAY", "TMR", "SHOWDATE", "OVERDUE", "ALL", "NONE"};
Parser::Parser(void)
{
}


Parser::~Parser(void)
{
}

Time ParseTime(string inp)
{
	//cout<<"^"<<inp<<"$"<<endl;
	Time ret(-1,-1);

	//if (inp.length() == 3) return ret;

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
	//cout<<"PROCESSED STRING="<<inp<<endl;
	// no slash
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
	// one slash
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
		// two slashes
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
		//cout<<"^"<<cmd<<"$"<<endl;
		// TODO : upperCase

		if (cmd == "add") ret = ADD;
		if (cmd == "search") ret = SEARCH;
		if (cmd == "display") ret = DISPLAY;
		if (cmd == "delete") ret = DEL;
		if (cmd == "edit") ret = EDIT;
		if (cmd == "done") ret = DONE;
		if (cmd == "undo") ret = UNDO;
		if (cmd == "redo") ret = REDO;
		if (cmd == "exit") ret = EXIT;
		if (cmd == "cls") ret = CLS;
		if (cmd == "help") ret = HELP;
		if (cmd == "undone") ret = UNDONE;
		if (cmd == "use") ret = USE;
		if (cmd == "where") ret = WHERE;
	}

	return ret;
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
		newTask.taskType = TIMED;
		//cout<<"IT IS A TIMED TASK\n"<<endl;
		if (!isDate)
		{
			// default date to today
			newTask.startDate = today;
			newTask.endDate = today;
			// extract range of time
			regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
			if (regex_search(TimeString, cap, rgxTimeRangeInner))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = ParseTime(cap[2]);
			}
		}
		else
		{
			//cout<<"TIMED TASK WITH DATE"<<endl;
			if (isDateRange)
			{
				//cout<<"TIMED TASK WITH DATE RANGE"<<endl;
				//cout<<"DATESTRING = ^"<<DateString<<"$"<<endl;
				regex rgxDateRangeInner("\\s*(.*)\\s*-\\s*(.*)");
				smatch cap2;
				if (regex_search(DateString, cap2, rgxDateRangeInner))
				{
					newTask.startDate = ParseDate(cap2[1]);
					newTask.endDate = ParseDate(cap2[2]);
				}
				//cout<<"IT GOES HERE ALSO??"<<endl;
			}
			else
			{
				//cout<<"TIMED TASK WITH DATE NO RANGE"<<endl;
				//cout<<"DATESTRING = ^"<<DateString<<"$"<<endl;
				regex rgxOnlyDate("date:\\s*([\\d\\/\\s]+)\\s*");
				if (regex_search(inp, cap, rgxOnlyDate))
				{
					newTask.startDate = ParseDate(cap[1]);
					newTask.endDate = newTask.startDate;
				}
			}

			// time range
			regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
			if (regex_search(TimeString, cap, rgxTimeRangeInner))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = ParseTime(cap[2]);
			}
		}
	}
	else
	{
		// Deadline
		newTask.taskType = DEAD;

		// only one date and optional one time

		regex rgxOnlyDate("date:\\s*([\\d\\/]+)");
		if (regex_search(inp,cap,rgxOnlyDate))
		{
			newTask.startDate = ParseDate(cap[1]);
			newTask.endDate = newTask.startDate;
		}
		else
		{
			newTask.startDate = today;
			newTask.endDate = today;
		}

		if (!isTime)
		{
			newTask.startTime = Time(23,59);
			newTask.endTime = Time(23,59);
		}
		else
		{
			regex rgxOnlyTime("time:\\s*(\\d+)");
			if (regex_search(inp,cap,rgxOnlyTime))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = newTask.startTime;
			}
		}
	}

}

void extractOtherDateTime(string inp)
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
		newTask.taskType = TIMED;
		//cout<<"IT IS A TIMED TASK\n"<<endl;
		if (!isDate)
		{
			// default date to today
			//newTask.startDate = today;
			//newTask.endDate = today;
			// extract range of time
			regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
			if (regex_search(TimeString, cap, rgxTimeRangeInner))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = ParseTime(cap[2]);
			}
		}
		else
		{
			//cout<<"TIMED TASK WITH DATE"<<endl;
			if (isDateRange)
			{
				//cout<<"TIMED TASK WITH DATE RANGE"<<endl;
				//cout<<"DATESTRING = ^"<<DateString<<"$"<<endl;
				regex rgxDateRangeInner("\\s*(.*)\\s*-\\s*(.*)");
				smatch cap2;
				if (regex_search(DateString, cap2, rgxDateRangeInner))
				{
					newTask.startDate = ParseDate(cap2[1]);
					newTask.endDate = ParseDate(cap2[2]);
				}
				//cout<<"IT GOES HERE ALSO??"<<endl;
			}
			else
			{
				//cout<<"TIMED TASK WITH DATE NO RANGE"<<endl;
				//cout<<"DATESTRING = ^"<<DateString<<"$"<<endl;
				regex rgxOnlyDate("date:\\s*([\\d\\/\\s]+)\\s*");
				if (regex_search(inp, cap, rgxOnlyDate))
				{
					newTask.startDate = ParseDate(cap[1]);
					newTask.endDate = newTask.startDate;
				}
			}

			// time range
			regex rgxTimeRangeInner("(\\d+)\\s*-\\s*(\\d+)");
			if (regex_search(TimeString, cap, rgxTimeRangeInner))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = ParseTime(cap[2]);
			}
		}
	}
	else
	{
		// Deadline
		newTask.taskType = DEAD;

		// only one date and optional one time

		regex rgxOnlyDate("date:\\s*([\\d\\/]+)");
		if (regex_search(inp,cap,rgxOnlyDate))
		{
			newTask.startDate = ParseDate(cap[1]);
			newTask.endDate = newTask.startDate;
		}

		if (!isTime)
		{
			//newTask.startTime = Time(23,59);
			//newTask.endTime = Time(23,59);
		}
		else
		{
			regex rgxOnlyTime("time:\\s*(\\d+)");
			if (regex_search(inp,cap,rgxOnlyTime))
			{
				newTask.startTime = ParseTime(cap[1]);
				newTask.endTime = newTask.startTime;
			}
		}
	}

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
}

void extractAddTask(string inp, int skip)
{
	// get info about doay
	time_t t = time(0);
	struct tm * now = localtime ( &t );

	today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

	
	// get Title

	// check if date exist
	regex rgxDate("date:");
	if (regex_search(inp,rgxDate)) isDate = true;

	// check if time exist
	regex rgxTime("time:");
	if (regex_search(inp,rgxTime)) isTime = true;
	// check if repeat exist

	regex rgxRepeat("repeat:");
	if (regex_search(inp,rgxRepeat)) isRepeat = true;

	if (!isRepeat)
	{
		if (!isDate && !isTime)
		{
			newTask.taskType = FLOATTASK;
			// Floating Task
			/*
			regex rgxTitle("add.(.*)$");
			if (regex_search(inp,cap,rgxTitle))
			{
				
				TaskTitle = cap[1];
				newTask.title = TaskTitle;
				//cout<<"BEING IDENTIFIED AS FLOATTASK TASK"<<endl;
				//cout<<newTask.startDate.day<<endl;
			}
			*/
		}
		else
		{
			// extract date and time:
			extractDateTime(inp);
		}
		extractTitle(inp.substr(skip));
	}
	else
	{
		// separate recur task
			
		
	}
	

	

}

void extractOtherTask(string inp, int skip)
{
	// get info about doay
	time_t t = time(0);
	struct tm * now = localtime ( &t );

	today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

	
	// get Title

	// check if date exist
	regex rgxDate("date:");
	if (regex_search(inp,rgxDate)) isDate = true;

	// check if time exist
	regex rgxTime("time:");
	if (regex_search(inp,rgxTime)) isTime = true;
	// check if repeat exist

	regex rgxRepeat("repeat:");
	if (regex_search(inp,rgxRepeat)) isRepeat = true;

	if (!isRepeat)
	{
		if (!isDate && !isTime)
		{
			newTask.taskType = FLOATTASK;
			// Floating Task
			/*
			regex rgxTitle("add.(.*)$");
			if (regex_search(inp,cap,rgxTitle))
			{
				
				TaskTitle = cap[1];
				newTask.title = TaskTitle;
				//cout<<"BEING IDENTIFIED AS FLOATTASK TASK"<<endl;
				//cout<<newTask.startDate.day<<endl;
			}
			*/
		}
		else
		{
			// extract date and time:
			extractOtherDateTime(inp);
		}
		extractTitle(inp.substr(skip));
	}
	else
	{
		// separate recur task
			
		
	}
	

}






void Parser::trimString(string &input) {
	size_t pos;
	pos = input.find_first_not_of(" \n\t");

	if (pos != string::npos) {
		input = input.substr(pos);
	}

	input = input.substr(0, input.find_last_not_of(" \n\t") + 1);
}

Parser::Parser(string inp)
{
	// receive input, parse accordingly
	isDateRange = false;
	isTimeRange = false;
	isDateValid = false;  
	isTimeValid = false;
	isDate = false; isTime = false; isRepeat = false;
	TaskTitle = "";
	DateString = "";
	TimeString = "";

	time_t t = time(0);
	struct tm * now = localtime ( &t );

	today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

	newCommand = Command();
	newTask = Task();
	//cout<<"AFTER INIT INFO"<<endl;
	//cout<<newTask.startDate.day<<endl;

	// extract command type
	CommandType cmdType = extractCommandType(inp);
	newCommand.cmd = cmdType;

	//cout<<"COMMAND TYPE = "<<CommandString[cmdType]<<endl;

	if (cmdType == ADD)
	{
		extractAddTask(inp,3);
		trimString(newTask.title);
		bool isValidTask = utility.isValidAddTask(newTask);
		if (!isValidTask)
		{
			newCommand.cmd = INVALID;
			//newTask.taskType = NUL;
		}

		// debug
		/*
		cout<<"---------------------- TASK INFO\n";
		cout<<"TASK TYPE = "<<TaskTypeString[newTask.taskType]<<" ";
		cout<<"TITLE = ^"<<newTask.title<<"$"<<" ";
		printf("START DATE = %d/%d/%d ",newTask.startDate.day,newTask.startDate.month,newTask.startDate.year);
		printf("END DATE = %d/%d/%d ",newTask.endDate.day,newTask.endDate.month,newTask.endDate.year);
		printf("START TIME = %d:%d ",newTask.startTime.hour,newTask.startTime.min);
		printf("END TIME = %d:%d ",newTask.endTime.hour,newTask.endTime.min);
		cout<<"END OF THIS TASK ----------------------------------"<<endl;
		*/
		// end of debug
	}

	if (cmdType == DEL)
	{
		// extract delete index;
		/*
		regex rgxDeleteIdx("delete\\s*(\\d+)");

		if (regex_search(inp,cap,rgxDeleteIdx))
		{
			//newCommand.idx = atoi(string(cap[1]).c_str());

		}
		*/

		//if (newCommand.idx < -1) newCommand.idx = -1;

		istringstream iss(inp.substr(6));

		int readIndex;
		bool correct = true;

		while (iss>>readIndex)
		{
			newCommand.idx.push_back(readIndex);
			if (readIndex < 1) correct = false;
		}

		if (!correct) newCommand.idx.clear();
		// debug
		/*
		cout<<"---------------------- DEL INFO\n";
		cout<<"DEL INDEX = ^"<<newCommand.idx.size()<<"$"<<endl;
		for (int i = 0; i < newCommand.idx.size(); i++) cout<<newCommand.idx[i]<<" ";
		cout<<endl;
		cout<<"END OF INFO -------------------"<<endl;
		*/
		// end of debug
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


		// get rest of info 
		//cout<<"INPUT = "<<inp<<endl;
		extractOtherTask(inp,6);
		if (!utility.isValidOtherTask(newTask))
		{
			newCommand.cmd = INVALID;
			//newTask.taskType = NUL;
		}

		// debug
		/*
		cout<<"---------------------- EDIT INFO\n";
		cout<<"EDIT INDEX = ^"<<newCommand.idx<<"$"<<endl;
		cout<<"TASK TYPE = "<<TaskTypeString[newTask.taskType]<<endl;
		cout<<"TITLE = ^"<<newTask.title<<"$"<<endl;
		printf("START DATE = %d/%d/%d\n",newTask.startDate.day,newTask.startDate.month,newTask.startDate.year);
		printf("END DATE = %d/%d/%d\n",newTask.endDate.day,newTask.endDate.month,newTask.endDate.year);
		printf("START TIME = %d:%d\n",newTask.startTime.hour,newTask.startTime.min);
		printf("END TIME = %d:%d\n",newTask.endTime.hour,newTask.endTime.min);
		cout<<"END OF EDIT ----------------------------------"<<endl;
		*/
		// end of debug
	}

	if (cmdType == DISPLAY)
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

		// debug
		/*
		cout<<"---------------------- DISPLAY INFO\n";
		cout<<"DISPLAY TYPE = "<<InstructionString[newCommand.instruction]<<endl;
		printf("START DATE = %d/%d/%d\n",newTask.startDate.day,newTask.startDate.month,newTask.startDate.year);
		printf("END DATE = %d/%d/%d\n",newTask.endDate.day,newTask.endDate.month,newTask.endDate.year);
		cout<<"END OF DISPLAY ----------------------------------"<<endl;
		*/
		// end of debug

	}

	if (cmdType == SEARCH)
	{
		// get rest of info 
		//cout<<"INPUT = "<<inp<<endl;
		extractOtherTask(inp,6);
		if (!utility.isValidOtherTask(newTask))
		{
			newCommand.cmd = INVALID;
			//newTask.taskType = NUL;
		}

		// debug
		/*
		cout<<"---------------------- SEARCH INFO\n";
		cout<<"TASK TYPE = "<<TaskTypeString[newTask.taskType]<<endl;
		cout<<"TITLE = ^"<<newTask.title<<"$"<<endl;
		printf("START DATE = %d/%d/%d\n",newTask.startDate.day,newTask.startDate.month,newTask.startDate.year);
		printf("END DATE = %d/%d/%d\n",newTask.endDate.day,newTask.endDate.month,newTask.endDate.year);
		printf("START TIME = %d:%d\n",newTask.startTime.hour,newTask.startTime.min);
		printf("END TIME = %d:%d\n",newTask.endTime.hour,newTask.endTime.min);
		cout<<"END OF SEARCH ----------------------------------"<<endl;
		*/
		// end of debug
	}

	if (cmdType == DONE)
	{
		// extract delete index;
		
		istringstream iss(inp.substr(4));

		int readIndex;
		bool correct = true;

		while (iss>>readIndex)
		{
			newCommand.idx.push_back(readIndex);
			if (readIndex < 1) correct = false;
		}

		if (!correct) newCommand.idx.clear();

	}

	if (cmdType == UNDONE)
	{
		// extract delete index;
		
		istringstream iss(inp.substr(6));

		int readIndex;
		bool correct = true;

		while (iss>>readIndex)
		{
			newCommand.idx.push_back(readIndex);
			if (readIndex < 1) correct = false;
		}

		if (!correct) newCommand.idx.clear();

	}

	if (cmdType == USE)
	{
		regex rgxFilePath("use (.*)");
		
		if (regex_search(inp,cap,rgxFilePath))
		{
			newCommand.path = cap[1];
		}

	}
	if (cmdType == CLS)
	{
	}

	if (cmdType == EXIT)
	{
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