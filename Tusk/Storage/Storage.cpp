#define _CRT_SECURE_NO_DEPRECATE
#include "Storage.h"
#include "Task.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filestream.h"
#include "rapidjson/filewritestream.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace rapidjson;
using namespace std;

const int MAX_TITLE_SIZE = 100;

string outputFile = "output.txt";
string inputFile = "output.txt";

Month convertToMonth(int month)
{
	if (month == 1) return JANUARY;
	if (month == 2) return FEBRUARY;
	if (month == 3) return MARCH;

	if (month == 4) return APRIL;
	if (month == 5) return MAY;
	if (month == 6) return JUNE;

	if (month == 7) return JULY;
	if (month == 8) return AUGUST;
	if (month == 9) return SEPTEMBER;

	if (month == 10) return OCTOBER;
	if (month == 11) return NOVEMBER;
	if (month == 12) return DECEMBER;
}

int convertMonthToInt(Month x)
{
	if (x == JANUARY) return 1;
	if (x == FEBRUARY) return 2;
	if (x == MARCH) return 3;

	if (x == APRIL) return 4;
	if (x == MAY) return 5;
	if (x == JUNE) return 6;

	if (x == JULY) return 7;
	if (x == AUGUST) return 8;
	if (x == SEPTEMBER) return 9;

	if (x == OCTOBER) return 10;
	if (x == NOVEMBER) return 11;
	if (x == DECEMBER) return 12;
}

TimeType convertToTimeType(int timeType)
{
	if (timeType == 0) return AM;
	if (timeType == 1) return PM;
}

int convertTimeTypeToInt(TimeType x)
{
	if (x == AM) return 0;
	if (x == PM) return 1;
}

Storage::Storage(void) {
}

Storage::~Storage(void) {
}

vector<Task> Storage::getAllTask() {

	FILE* in = fopen(inputFile.c_str(),"r");

	char readBuffer[65536];
	FileReadStream is(in,readBuffer,sizeof(readBuffer));

	Document d;
	d.ParseStream(is);

	fclose(in);

	//cout<<"Finshed Read file"<<endl;

	const Value& TaskArray = d["data"];

	//cout<<"Get data Array done"<<endl;

	vector<Task> newVector;
	newVector.clear();

	//cout<<"Size of input = "<<TaskArray.Size()<<endl;

	for (SizeType i = 0; i < TaskArray.Size(); i++)
	{
		const Value& TaskObject = TaskArray[i];
		//cout<<"Input index = "<<i<<" | TaskType = "<<TaskObject["TaskType"].GetString()<<" "<<endl;

		string inputTaskType = TaskObject["TaskType"].GetString();

		if (inputTaskType == "FloatingTask")
		{
			//cout<<"Added 1 task"<<endl;
			Task newFloatTask;

			newFloatTask.setTaskType(FLOATINGTASK);
			newFloatTask.setTitle(TaskObject["TaskTitle"].GetString());

			newVector.push_back(newFloatTask);

		}

		if (inputTaskType == "Deadline")
		{
			Task newDeadline;

			newDeadline.setTaskType(DEADLINE);
			newDeadline.setTitle(TaskObject["TaskTitle"].GetString());
			
			Date TaskDate;
			TaskDate.setDay(TaskObject["TaskDay"].GetInt());
			TaskDate.setMonth(convertToMonth(TaskObject["TaskMonth"].GetInt()));
			TaskDate.setYear(TaskObject["TaskYear"].GetInt());

			Time TaskTime;
			TaskTime.setHours(TaskObject["TaskHour"].GetInt());
			TaskTime.setMinutes(TaskObject["TaskMinute"].GetInt());
			TaskTime.setTimeType(convertToTimeType(TaskObject["TaskTimeType"].GetInt()));

			newDeadline.setStartingDate(TaskDate);
			newDeadline.setEndingDate(TaskDate);
			
			newDeadline.setStartingTime(TaskTime);
			newDeadline.setEndingTime(TaskTime);

			newVector.push_back(newDeadline);
		}

		if (inputTaskType == "TimedTask")
		{
			Task newTimedTask;

			newTimedTask.setTaskType(TIMEDTASK);
			newTimedTask.setTitle(TaskObject["TaskTitle"].GetString());
			
			Date TaskDate;
			TaskDate.setDay(TaskObject["TaskStartDay"].GetInt());
			TaskDate.setMonth(convertToMonth(TaskObject["TaskStartMonth"].GetInt()));
			TaskDate.setYear(TaskObject["TaskStartYear"].GetInt());

			Time TaskTime;
			TaskTime.setHours(TaskObject["TaskStartHour"].GetInt());
			TaskTime.setMinutes(TaskObject["TaskStartMinute"].GetInt());
			TaskTime.setTimeType(convertToTimeType(TaskObject["TaskStartTimeType"].GetInt()));

			newTimedTask.setStartingDate(TaskDate);
			newTimedTask.setStartingTime(TaskTime);
			//
			TaskDate.setDay(TaskObject["TaskEndDay"].GetInt());
			TaskDate.setMonth(convertToMonth(TaskObject["TaskEndMonth"].GetInt()));
			TaskDate.setYear(TaskObject["TaskEndYear"].GetInt());

			TaskTime.setHours(TaskObject["TaskEndHour"].GetInt());
			TaskTime.setMinutes(TaskObject["TaskEndMinute"].GetInt());
			TaskTime.setTimeType(convertToTimeType(TaskObject["TaskEndTimeType"].GetInt()));

			newTimedTask.setEndingTime(TaskTime);
			newTimedTask.setEndingDate(TaskDate);

			newVector.push_back(newTimedTask);
		}
	}

	//cout<<"Input size = "<<newVector.size()<<endl;

	return newVector;
}

void Storage::writeToFile(vector<Task> TaskVector) {

	Document d;
	d.SetObject();

	Value myArray(kArrayType);

	//cout<<"Output size = "<<TaskVector.size()<<endl;
	for (int i = 0; i < TaskVector.size(); i++)
	{
		Value obj(kObjectType);
		obj.SetObject();
		
		if (TaskVector[i].getTaskType() == FLOATINGTASK)
		{
			char title[MAX_TITLE_SIZE];
			sprintf(title, "%s", TaskVector[i].getTitle().c_str());

			Value taskTitle(kStringType);
			taskTitle.SetString(title,strlen(title),d.GetAllocator());
			obj.AddMember("TaskType", "FloatingTask",d.GetAllocator());
			obj.AddMember("TaskTitle", taskTitle,d.GetAllocator());
		}

		if (TaskVector[i].getTaskType() == DEADLINE)
		{
			char title[MAX_TITLE_SIZE];
			sprintf(title, "%s", TaskVector[i].getTitle().c_str());

			Value taskTitle(kStringType);
			taskTitle.SetString(title,strlen(title),d.GetAllocator());
			obj.AddMember("TaskType", "Deadline",d.GetAllocator());
			obj.AddMember("TaskTitle", taskTitle,d.GetAllocator());

			obj.AddMember("TaskDay",TaskVector[i].getStartingDate().getDay(),d.GetAllocator());
			obj.AddMember("TaskMonth",convertMonthToInt(TaskVector[i].getStartingDate().getMonth()),d.GetAllocator());
			obj.AddMember("TaskYear",TaskVector[i].getStartingDate().getDay(),d.GetAllocator());

			obj.AddMember("TaskHour",TaskVector[i].getStartingTime().getHours(),d.GetAllocator());
			obj.AddMember("TaskMinute",TaskVector[i].getStartingTime().getMinutes(),d.GetAllocator());
			obj.AddMember("TaskTimeType",convertTimeTypeToInt(TaskVector[i].getStartingTime().getTimeType()),d.GetAllocator());
		}

		if (TaskVector[i].getTaskType() == TIMEDTASK)
		{
			char title[MAX_TITLE_SIZE];
			sprintf(title, "%s", TaskVector[i].getTitle().c_str());

			Value taskTitle(kStringType);
			taskTitle.SetString(title,strlen(title),d.GetAllocator());
			obj.AddMember("TaskType", "TimedTask",d.GetAllocator());
			obj.AddMember("TaskTitle", taskTitle,d.GetAllocator());

			obj.AddMember("TaskStartDay",TaskVector[i].getStartingDate().getDay(),d.GetAllocator());
			obj.AddMember("TaskStartMonth",convertMonthToInt(TaskVector[i].getStartingDate().getMonth()),d.GetAllocator());
			obj.AddMember("TaskStartYear",TaskVector[i].getStartingDate().getDay(),d.GetAllocator());

			obj.AddMember("TaskStartHour",TaskVector[i].getStartingTime().getHours(),d.GetAllocator());
			obj.AddMember("TaskStartMinute",TaskVector[i].getStartingTime().getMinutes(),d.GetAllocator());
			obj.AddMember("TaskStartTimeType",convertTimeTypeToInt(TaskVector[i].getStartingTime().getTimeType()),d.GetAllocator());

			obj.AddMember("TaskEndDay",TaskVector[i].getEndingDate().getDay(),d.GetAllocator());
			obj.AddMember("TaskEndMonth",convertMonthToInt(TaskVector[i].getEndingDate().getMonth()),d.GetAllocator());
			obj.AddMember("TaskEndYear",TaskVector[i].getEndingDate().getDay(),d.GetAllocator());

			obj.AddMember("TaskEndHour",TaskVector[i].getEndingTime().getHours(),d.GetAllocator());
			obj.AddMember("TaskEndMinute",TaskVector[i].getEndingTime().getMinutes(),d.GetAllocator());
			obj.AddMember("TaskEndTimeType",convertTimeTypeToInt(TaskVector[i].getEndingTime().getTimeType()),d.GetAllocator());
		}

		myArray.PushBack(obj,d.GetAllocator());
	}
	
	d.AddMember("data",myArray,d.GetAllocator());
    
		
	FILE* out = fopen(outputFile.c_str(),"w");

	char writeBuffer[65536];
	FileWriteStream os(out, writeBuffer, sizeof(writeBuffer));

	PrettyWriter<FileWriteStream> out_writer(os);
	d.Accept(out_writer);
	fclose(out);
		

}