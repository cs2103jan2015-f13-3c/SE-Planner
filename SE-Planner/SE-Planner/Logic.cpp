#include "Logic.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <functional> 

using namespace std;


Logic::Logic(void)
{
	Utility utility;
}


Logic::~Logic(void)
{
}

// WEIMIN
vector<Task> Logic::Add(vector<Task> allTask, Task addTask)
{
	
	if (addTask.taskType == NUL)
	{
		success = 0;
		return allTask;
	}
	else
	{
		success = 1;

		vector<Task> temp = allTask;
		temp.push_back(addTask);
		return temp;
	}
}

// WEIMIN
vector<Task> Logic::Delete(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	// if there is no index instruction -> fail command
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	// if any index exceeds the size of display Task List -> fail command
	for (int j = 0; j < index.size(); j++)
	{
		//cout<<index[j]<<endl;
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}


	success = 1;

	// 'marked' array for allTask
	// meaning : false = this task will NOT be deleted
	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	// mark the task to be deleted inside the mainTaskList
	for (int j = 0; j < index.size(); j++)
	{
		
		success = 1;

		Task deleteTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],deleteTask)) 
			{
				marked[i] = true; // THIS TASK WILL BE DELETED
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		// DELETE ACCORDINGLY
		if (!marked[i]) temp.push_back(allTask[i]);
	}

	return temp;

}

// WEIMIN
vector<Task> Logic::Done(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	
	// Logic similar to Done
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	for (int j = 0; j < index.size(); j++)
	{
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}

	success = 1;

	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++)
	{
		
		success = 1;

		Task doneTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],doneTask)) 
			{
				marked[i] = true;
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		temp.push_back(allTask[i]);
		if (marked[i]) temp[i].isDone = true;
		//cout<<i<<" "<<temp[i].isDone<<endl;
	}

	return temp;

}

// YOONG ZHEN
vector<Task> Logic::Search(vector<Task> allTask, Task searchTask)
{
	// list of all Task that match the requirement
	vector<Task> matchTask;
	matchTask.clear();

	// if the search info is INVALID
	if (searchTask.taskType == NUL)
	{
		success = 0;
		return matchTask;
	}
	else
	{
		success = 1;
		int totalDisplay = 0;

		for (int i = 0; i < allTask.size(); i++)
		{
			// check Title
			bool matchTitle = utility.compareTitle(allTask[i],searchTask);
			// check Date
			bool matchDate = utility.compareDate(allTask[i],searchTask);
			// check Time
			bool matchTime = utility.compareTime(allTask[i],searchTask);

			// if match every thing
			if (matchTitle && matchDate && matchTime)
			{
				totalDisplay++;
				matchTask.push_back(allTask[i]);
				if (totalDisplay == 5) break;
				// LIMIT DISPLAY IS 5, CAN CHANGE LATER. I TOTALLY FORGET ABOUT THIS WHEN DOING OP2
			}
		}

		return matchTask;
	}
}


// YOONG ZHEN
// THIS IS THE COMPARATOR FOR THE SORT FUNCTION OF THE DISPLAY COMMAND. 
// FLOAT AT BOTTOM, THEN SORT BY ENDING DATE, BY TIME, THEN BY NAME
// orderTask(t1, t2) = true IF t1 shows before t2 when displayed
// that is t1 < t2

bool Logic::orderTask(Task t1, Task t2)
{
	if (t1.taskType == t2.taskType)
	{
		// SAME TASK TYPE
		if (t1.taskType == FLOATTASK)
		{
			// FLOAT BOTTOM
			return (t1.title.compare(t2.title) < 0);
		}
		else
		{
			// SAME END DATE
			if (utility.isEqual(t1.endDate,t2.endDate))
			{
				// COMPARE TIME
				if (!utility.isEqual(t1.endTime,t2.endTime))
				{
					return (utility.isLaterTime(t1.endTime,t2.endTime));
				}
				else return (t1.title.compare(t2.title) < 0);
			}
			else return (utility.isLaterDate(t1.endDate,t2.endDate));
		}
	}
	else
	{
		// DIFFERENT TASK TYPE
		if (t1.taskType == FLOATTASK || t2.taskType == FLOATTASK)
		{
			// AT MOST ONE FLOAT TASK ( DIFFERENT TASK TYPE)
			if (t1.taskType == FLOATTASK) return false;
			else return true;
		}
		else
		{
			// SAME END DATE
			if (utility.isEqual(t1.endDate,t2.endDate))
			{
				if (!utility.isEqual(t1.endTime,t2.endTime))
				{
					// COMPARE TIME
					return (utility.isLaterTime(t1.endTime,t2.endTime));
				}
				else return (t1.title.compare(t2.title) < 0);
			}
			else return (utility.isLaterDate(t1.endDate,t2.endDate));
		}
	}
}

// YOONG ZHEN
vector<Task> Logic::Display(vector<Task> allTask, Task displayTask, InstructionType instruction)
{
	// TODAY, TMR, SHOWDATE, OVERDUE, ALL, NONE

	vector<Task> matchTask;
	matchTask.clear();

	if (instruction == NONE)
	{
		success = 0;
		
	}
	else
	{
		//cout<<"I AM HERE"<<endl;
		success = 1;

		// GET DATE OF TODAY AND TMR
		Date today = Date();
		Date tmr = Date();

		time_t t = time(0);
		struct tm * now = localtime ( &t );

		today = Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

		time(&t);
		t = t + (60 * 60 * 24);
		struct tm * now1 = localtime (&t);
		
		tmr = Date(now1->tm_mday,now1->tm_mon+1,now1->tm_year+1900);

		vector<Task> allTask1;
		allTask1.clear();

		// REMOVE ALL DONE
		// THIS IS CURRENTLY MESSY
		for (int i = 0; i < allTask.size(); i++)
			if (allTask[i].isDone == false) allTask1.push_back(allTask[i]);

		if (instruction == ALL)
		{
			matchTask = allTask1;
		}
		else if (instruction == DONE)
		{
			for (int i = 0; i < allTask.size(); i++)
				if (allTask[i].isDone) matchTask.push_back(allTask[i]);
		}
		else if (instruction == UNDONE)
		{
			for (int i = 0; i < allTask.size(); i++)
				if (!allTask[i].isDone) matchTask.push_back(allTask[i]);
		}
		else if (instruction == OVERDUE)
		{
			// NOT DONE & BEFORE TODAY
			for (int i = 0; i < allTask.size(); i++)
			{
				if (!allTask[i].isDone && utility.beforeToday(allTask[i].startDate,today))
					matchTask.push_back(allTask[i]);
			}

		}
		else
		{
			Date matchDate = Date();
			// get date today

			if (instruction == TODAY)
			{
				matchDate = Date(today.day,today.month,today.year);
			}
			// get date tmr

			if (instruction == TMR)
			{
				matchDate = Date(tmr.day,tmr.month,tmr.year);
			}

			if (instruction == SHOWDATE)
			{
				matchDate = Date(displayTask.startDate.day,displayTask.startDate.month,displayTask.startDate.year);
			}

			// match

			for (int i = 0; i < allTask.size(); i++)
			{
				// SHOW UNDONE 
				// AND (SHOW FLOAT OR THE STARTDATE MATCHES THE DATE)
				if (!allTask[i].isDone && (allTask[i].taskType == FLOATTASK || utility.isEqual(allTask[i].startDate,matchDate))) matchTask.push_back(allTask[i]);
			}

		}
	}


	// sort Task
	// SHOULD NOT TOUCH LAST PART OF sort
	sort(matchTask.begin(),matchTask.end(),bind(&Logic::orderTask,this,std::placeholders::_1,std::placeholders::_2));

	return matchTask;
}

// YOONG ZHEN
vector<Task> Logic::Edit(vector<Task> allTask, vector<Task> displayedTask, int index, Task editTask)
{
	// IF THE EDIT COMMAND INFO IS INVALID
	if (editTask.taskType == NUL)
	{
		success = 0;
		return allTask;
	}
	else
	{
		// IF THE INDEX EXCEEDS THE DISPLAY TASK LIST
		if (index > displayedTask.size())
		{
			success = 0;
			return allTask;
		}

		Task theTask = displayedTask[index-1];

		// IS THE DATE & TIME EDITABLE OR NOT
		bool canEditDate = true;
		bool canEditTime = true;
		
		if (theTask.taskType == FLOATTASK)
		{
			if (editTask.taskType != FLOATTASK)
			{
				canEditDate = false;
				canEditTime = false;
			}
		}

		// DEADLINE CANNOT BE CHANGED TO TIMED TASK
		if (theTask.taskType == DEAD)
		{
			if (editTask.taskType == TIMED)
			{
				canEditDate = false;
				canEditTime = false;
			}
		}

		if (theTask.taskType == TIMED)
		{
			// TIMED TASK HAS RANGE OF TIME
			// CANNOT CHANGE TO DEADLINE (WITH SPECIFIED TIME) 

			if (editTask.taskType == DEAD && !utility.isNull(editTask.startTime))
			{
				canEditDate = false;
				canEditTime = false;
			}
		}

		// OTHERWISE, GO AHEAD
		if (canEditDate && canEditTime)
		{
			vector<Task> temp = allTask;

			for (int i = 0; i < temp.size(); i++)
				if (utility.isSame(temp[i],theTask))
				{
					if (!utility.isNull(editTask.title)) temp[i].title = editTask.title;
					if (!utility.isNull(editTask.startDate)) temp[i].startDate = editTask.startDate;
					if (!utility.isNull(editTask.endDate)) temp[i].endDate = editTask.endDate;
					if (!utility.isNull(editTask.startTime)) temp[i].startTime = editTask.startTime;
					if (!utility.isNull(editTask.endTime)) temp[i].endTime = editTask.endTime;

					if (utility.isValidAddTask(temp[i])) success = 1;
					else success = 0;
				}

			return temp;
		}

		return allTask;

	}
}

// Tung
vector<Task> Logic::Undone(vector<Task> allTask, vector<Task> displayedTask, vector<int> index)
{
	
	// Logic similar to Done
	if (index.size() == 0)
	{
		success = 0;
		return allTask;
	}

	for (int j = 0; j < index.size(); j++)
	{
		if (index[j] > displayedTask.size())
		{
			success = 0;
			return allTask;
		}
	}

	success = 1;

	bool marked[1000];
	for (int i = 0; i <= allTask.size() + 1; i++) marked[i] = false;

	vector<Task> temp;
	temp.clear();

	for (int j = 0; j < index.size(); j++)
	{
		success = 1;

		Task undoneTask = displayedTask[index[j]-1];


		for (int i = 0; i < allTask.size(); i++)
		{
			if (utility.isSame(allTask[i],undoneTask)) 
			{
				marked[i] = true;
				break;
			}
		}		
	}

	for (int i = 0; i < allTask.size(); i++)
	{
		temp.push_back(allTask[i]);
		if (marked[i]) temp[i].isDone = false;
		//cout<<i<<" "<<temp[i].isDone<<endl;
	}

	return temp;

}
