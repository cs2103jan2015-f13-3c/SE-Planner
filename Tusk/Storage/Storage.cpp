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
string inputFile = "input.txt";

Storage::Storage(void) {
}

Storage::~Storage(void) {
}

vector<Task> getAllTask() {

	FILE* in = fopen(inputFile.c_str(),"r");

	char readBuffer[65536];
	FileReadStream is(in,readBuffer,sizeof(readBuffer));

	Document d;
	d.ParseStream(is);

	fclose(in);

	const Value& TaskArray = d["data"];

	vector<Task> newVector;
	newVector.clear();

	for (SizeType i = 0; i < TaskArray.Size(); i++)
	{
		const Value& TaskObject = TaskArray[i];

		if (TaskObject["TaskType"].GetString() == "FloatingTask")
		{
			Task newFloatTask;

			newFloatTask.setTaskType(FLOATINGTASK);
			newFloatTask.setTitle(TaskObject["TaskTitle"].GetString());

			newVector.push_back(newFloatTask);

		}
	}

	return newVector;
}

void writeToFile(vector<Task> TaskVector) {

	Document d;
	d.SetObject();

	Value myArray(kArrayType);

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