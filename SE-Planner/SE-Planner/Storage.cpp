#include "Storage.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Parser.h"

Storage::Storage(void)
{
}

Storage::Storage(string filePath)
{
	// currently useless
	// will implement this later
	outputFile = filePath;
}

Storage::~Storage(void)
{
}

// Check if the output file is ready for reading/writing. If file not exist, create one
void checkOuputFile(string outFile)
{
	ofstream savefile;
	savefile.open(outFile, ofstream::app);

	bool fileExist = false;
	if (savefile.good()) fileExist = true;

	if (!fileExist)
	{
		//cout<<"SAVE FILE NOT FOUND. CREATED A NEW ONE\n";
		savefile.open(outFile, ios_base::out);
	}

	savefile.close();
}

// GET ALL TASKS FROM FILE AND RETURN IN CORRECT FORMAT
vector<Task> Storage::getAllTask(void)
{
	
	checkOuputFile(outputFile);

	// open File for reading
	ifstream myfile(outputFile);
	// TODO : HANDLE EXCEPTION WHEN OPENING A FILE

	vector<Task> allTask;
	allTask.clear();

	if (myfile.is_open())
	{
		//cout<<"FILE OPENED"<<endl;
		string line;
		while (getline(myfile,line))
		{
			//cout<<"LINE READ FROM FILE: "<<line<<endl;
			// file Structure : [1/0]add ..........
			// process each line

			Task newTask = Task();

			// GET DONE STATUS
			bool DoneStatus = false;
			if (line[0] == '1') DoneStatus = true;
			else DoneStatus = false;
			
			// extract the add command: add ....... and pass to parser
			line = line.substr(1);
			//cout<<"LINE TO PARSER: "<<line<<endl;
			Parser parseFromFile(line);
			newTask = parseFromFile.getTask();
			newTask.isDone = DoneStatus;
			if (newTask.taskType != NUL) allTask.push_back(newTask);
		}
		myfile.close();
	}
	// return

	//cout<<"TASK READ FROM FILE = "<<allTask.size()<<endl;

	return allTask;

}

// convert time to String for writing to file
string timeToString(Time x)
{
	string out = "";

	if (x.hour < 10) out = "0"+to_string(x.hour);
	else out = to_string(x.hour);

	if (x.min < 10) out += ("0"+to_string(x.min));
	else out += to_string(x.min);

	return out;
}

// convert task to string for writing to file
string convertToString(Task tempTask)
{
	//Task tempTask = Task();

	string TaskString = "";

	// isDone Status
	if (tempTask.isDone == true) TaskString += "1";
	else TaskString += "0";
	// add
	TaskString += "add ";
	// Title
	TaskString += tempTask.title;

	if (tempTask.taskType != FLOATTASK)
	{
		TaskString += " ";

		// Deadline
		if (tempTask.taskType == DEAD)
		{
			TaskString += "date: ";
			string TaskDate = to_string(tempTask.startDate.day) + "/" + to_string(tempTask.startDate.month) + "/" + to_string(tempTask.startDate.year);
			TaskString += TaskDate;

			TaskString += " time: ";
			string TaskTime = timeToString(tempTask.startTime);
			TaskString += TaskTime;
		}
		// Timed

		if (tempTask.taskType == TIMED)
		{
			TaskString += "date: ";
			string TaskDate = to_string(tempTask.startDate.day) + "/" + to_string(tempTask.startDate.month) + "/" + to_string(tempTask.startDate.year);
			TaskString += TaskDate;
			TaskString += "-";
			TaskDate = to_string(tempTask.endDate.day) + "/" + to_string(tempTask.endDate.month) + "/" + to_string(tempTask.endDate.year);
			TaskString += TaskDate;

			TaskString += " time: ";
			string TaskTime = timeToString(tempTask.startTime);
			TaskString += TaskTime;
			TaskString += "-";
			TaskTime = timeToString(tempTask.endTime);
			TaskString += TaskTime;
		}
	}

	return TaskString;
}

void Storage::writeToFile(vector<Task> allTask)
{
	ofstream myfile;
	myfile.open(outputFile);

	if (myfile.is_open())
	{
		//cout<<"WRITING TO FILE"<<endl;
		//cout<<"TASK WRITTEN TO FILE = "<<allTask.size()<<endl;

		for (int i = 0; i < allTask.size(); i++)
		{
			string out = convertToString(allTask[i]);
			//cout<<allTask[i].isDone<<endl;
			//cout<<"CONVERTED = "<<out<<endl;
			//out = "test";
			myfile << out << endl;
		}
		myfile.flush();
		myfile.close();
	}
}
